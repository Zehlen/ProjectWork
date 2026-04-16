#include "ISR.h"

ISR(TIMER0_OVF_vect) 
{
    TIFR0 = (1 << TOV0);
    TCNT0 = 0xC3;
    if(LcdStrk.LcdFlgas.DlyStrt_F)
    {
        LcdStrk.LcdVars.DlyCntr_Ui16++;
        if(LcdStrk.LcdVars.DlyCntr_Ui16 > LcdStrk.LcdVars.DlyCnt_Ui16)
        {
            LcdStrk.LcdVars.DlyCntr_Ui16 = 0;
            LcdStrk.LcdFlgas.DlyStrt_F   = false;
            LcdStrk.LcdFlgas.TimOut_F    = true;
        }
    }
}

ISR(TWI_vect)
{
    switch (TWSR & 0xF8) 
    {
        case 0x08: // START condition transmitted
            I2cStrk.I2cFlags.StrtCmplt_F = true;
            TWDR = I2cStrk.I2cVars.DevAddrs_Ui8; // Load SLA+W (0x7E)
            TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWIE); 
        break;
        case 0x10:
            TWDR = I2cStrk.I2cVars.DevAddrs_Ui8; // Load SLA+W (0x7E)
            TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWIE); 
        break;
        case 0x18: // SLA+W transmitted, ACK received
            TWDR = I2cStrk.I2cFlags.DataCmdSclt_F; // Load your first Data byte (Control Byte)
            TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWIE);
        break;
        case 0x28: // Data byte transmitted, ACK received
            switch(I2cStrk.I2cVars.LwrNibbl_Ui8)
            {
                case 0:
                    LcdStrk.LcdVars.DataByte_Ui8   = LcdStrk.LcdVars.DataBffr_Ui8[I2cStrk.I2cVars.BytsCntr_Ui16++];
                    I2cStrk.I2cVars.UpprNibbl_Ui8  = (LcdStrk.LcdVars.DataByte_Ui8 & 0xF0);
                    I2cStrk.I2cVars.UpprNibbl_Ui8 |= (I2cStrk.I2cFlags.DataCmdSclt_F << _RS_POSTN) | (1 << _EN_POSTN);
                    __DATA_REG                     = I2cStrk.I2cVars.UpprNibbl_Ui8;
                    I2cStrk.I2cVars.LwrNibbl_Ui8   = 2;
                    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWIE); 
                break;
                case 1:
                    I2cStrk.I2cVars.UpprNibbl_Ui8  = (LcdStrk.LcdVars.DataByte_Ui8 << 0x04) & 0xF0;
                    I2cStrk.I2cVars.UpprNibbl_Ui8 |= (I2cStrk.I2cFlags.DataCmdSclt_F << _RS_POSTN) | (1 << _EN_POSTN);
                    __DATA_REG                     = I2cStrk.I2cVars.UpprNibbl_Ui8;
                    I2cStrk.I2cVars.LwrNibbl_Ui8   = 2;
                    I2cStrk.I2cFlags.I2cBusy_F     = true;
                    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWIE); 
                break;
                case 2:
                    I2cStrk.I2cVars.UpprNibbl_Ui8 &= ~(1 << _EN_POSTN);
                    __DATA_REG = I2cStrk.I2cVars.UpprNibbl_Ui8;
                    I2cStrk.I2cVars.LwrNibbl_Ui8 = 1;
                    if(I2cStrk.I2cFlags.I2cBusy_F)
                    {
                        I2cStrk.I2cFlags.I2cBusy_F = false;
                        I2cStrk.I2cVars.LwrNibbl_Ui8 = 3;
                    }
                    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWIE);
                break;
                case 3:
                    TWCR = (1 << TWINT) | (1 << TWEN);
                    if(I2cStrk.I2cVars.BytsCntr_Ui16 > I2cStrk.I2cVars.TotlByts2wrt_Ui16)
                    {
                        I2cStrk.I2cVars.BytsCntr_Ui16 = 0;
                        I2cStrk.I2cFlags.StpCmplt_F   = true;
                        I2cStrk.I2cFlags.StrtCmplt_F  = false;
                        __STP_I2C();
                   }
                   I2cStrk.I2cVars.LwrNibbl_Ui8 = 0;
                break;
            }
        break;
    }
}