#include "graphics.h"

void G_LCDInit_Mth(void)
{
	if(	graphics.DelayTimeout)
    {
        graphics.DelayTimeout = false;
        switch(graphics.G_GLCD_InitStatus_Ui8)
        {
        case STATUS_IDLE:
            CS1_RC0 = 1;
            CS2_RC1 = 1;
            //HAL_GPIO_WritePin(GPIOB, LCD_CS1_PB9_Pin, SET);
            //HAL_GPIO_WritePin(GPIOC, LCD_CS2_PC10_Pin, SET);
            graphics.Delay_count_Ui16 = 10;
            graphics.Delay_counter_Ui16 = 0;
            graphics.StartDelayCount = true;
            graphics.G_GLCD_InitStatus_Ui8 = DISPLAY_OFF;
        break;
        case DISPLAY_OFF:
            G_GlcdWrite_Mth(INSMODE,0X3E);
            graphics.Delay_count_Ui16 = 10;
            graphics.Delay_counter_Ui16 = 0;
            graphics.StartDelayCount = true;
            graphics.G_GLCD_InitStatus_Ui8 = SET_YADDRESS;
        break;
        case SET_YADDRESS:
            G_GlcdWrite_Mth(INSMODE,0x45);
            graphics.Delay_count_Ui16 = 10;
            graphics.Delay_counter_Ui16 = 0;
            graphics.StartDelayCount = true;
            graphics.G_GLCD_InitStatus_Ui8 = SET_XADDRESS;

        break;
        case SET_XADDRESS:
            G_GlcdWrite_Mth(INSMODE,0xB8);
            graphics.Delay_count_Ui16 = 10;
            graphics.Delay_counter_Ui16 = 0;
            graphics.StartDelayCount = true;
            graphics.G_GLCD_InitStatus_Ui8 = SET_ZADDRESS;
        break;
        case SET_ZADDRESS:
            G_GlcdWrite_Mth(INSMODE,0xC0);
            graphics.Delay_count_Ui16 = 10;
            graphics.Delay_counter_Ui16 = 0;
            graphics.StartDelayCount = true;
            graphics.G_GLCD_InitStatus_Ui8 = REVERS_DSPLY;
        break;
        case REVERS_DSPLY:
            G_GlcdWrite_Mth(INSMODE,0xC8);
            graphics.Delay_count_Ui16 = 10;
            graphics.Delay_counter_Ui16 = 0;
            graphics.StartDelayCount = true;
            graphics.G_GLCD_InitStatus_Ui8 = DISPLAY_ON;
        break;
        case DISPLAY_ON:
            G_GlcdWrite_Mth(INSMODE,0XAF);
            graphics.Delay_count_Ui16 = 10;
            graphics.Delay_counter_Ui16 = 0;
            graphics.StartDelayCount = true;
            graphics.G_GLCD_InitStatus_Ui8 = INIT_COMPLETE;

        break;
        case INIT_COMPLETE:
            graphics.G_GLCD_InitStatus_Ui8 = 0;
            graphics.Delay_count_Ui16 = 10;
            graphics.InitGraphics = true;
            graphics.Delay_counter_Ui16 = 0;
            graphics.StartDelayCount = true;
        break;
        }
    }
}

void G_GlcdWrite_Mth(uint8_t Rs_Status,uint8_t L_Data_Uch)
{
    DATA_PORT = L_Data_Uch;
	 if (Rs_Status)
	 {
        RS_RE2 = 1;
	 }
	 else
	 {
        RS_RE2 = 0;
	 }
     EN_RE0 = 1;
	 SetDelayUs_Mth(10);
     EN_RE0 = 0;
}

uint8_t G_DrawChar_Mth(uint8_t L_CharData_Ui8)
{
	uint8_t L_FontIndex_Ui8 = L_CharData_Ui8 - ' ';
	uint8_t L_FontSize_Ui8 = (uint8_t)Calibri9x10[L_FontIndex_Ui8][0];
	volatile uint16_t L_FontColData = 0;

	if(graphics.FontsInverted == false)
	{
		for(uint8_t L_ColCounter_Ui8 = 0;L_ColCounter_Ui8 < L_FontSize_Ui8;L_ColCounter_Ui8++)
		{
			L_FontColData = Calibri9x10[L_FontIndex_Ui8][L_ColCounter_Ui8 + 1];
			G_GLCDData64_Ui8Arr[graphics.TotalRowWrite_Ui8][graphics.TotalColWrite_Ui8] = (uint8_t)((L_FontColData >> 8) & 0x00ff);
			if(graphics.TotalColWrite_Ui8 >= 127)
			{
				graphics.TotalColWrite_Ui8 = 0;
				graphics.TotalRowWrite_Ui8++;
			}
			graphics.TotalColWrite_Ui8++;
		}
	}
	return graphics.TotalColWrite_Ui8;
}

uint8_t G_CopyMsg_Mth(uint8_t M_Msg_Ui8)
{
	uint8_t L_MsgLen_Ui8 = AppMessageLen(M_Msg_Ui8);
	for(uint8_t L_MsgCount_Ui8 = 0;L_MsgCount_Ui8 < L_MsgLen_Ui8; L_MsgCount_Ui8 ++)
	{
		G_CharBuffer_Ui8Arr[L_MsgCount_Ui8] = AppMessages[M_Msg_Ui8][L_MsgCount_Ui8];
	}
	return L_MsgLen_Ui8;
}

/**
 * @param Message Number
 * @param Row Address
 * @param Column Address
 * */
void G_WriteMsg_Mth(uint8_t M_Msg_Ui8, uint8_t M_X_Val_Ui8, uint8_t M_Y_Val_Ui8)
{
	uint8_t L_MsgCount_Ui8 = G_CopyMsg_Mth(M_Msg_Ui8);
	graphics.RowStrtAddr_Ui8 = M_X_Val_Ui8;
	graphics.ColStrtAddr_Ui8 = M_Y_Val_Ui8;
	G_GLCDWriteStr_Mth(G_CharBuffer_Ui8Arr,L_MsgCount_Ui8,M_X_Val_Ui8);
}

void G_GLCDWriteStr_Mth(uint8_t str[], uint8_t count,uint8_t L_Xpos_Ui8)
{

    int i = 0;
    for(; i < count; i++)
    {
      L_Xpos_Ui8 = G_DrawChar_Mth(str[i]) + 1;
    }
    graphics.RowEndAddr_Ui8 = 1;//graphics.TotalRowWrite_Ui8;
    graphics.ColEndAddr_Ui8 = L_Xpos_Ui8;
    G_ClearGLCDCharBuffer_Mth();
}

void G_WriteBufferData_Mth(void)
{
	uint8_t L_GLCDData64_Ui8 = 0;
	uint8_t ColCounter = graphics.ColStrtAddr_Ui8;
	if(ColCounter > 63)
	{
		ColCounter -= 64;
	}
	uint8_t L_DataRowCount_Ui8 = 0;
	for(;L_DataRowCount_Ui8 < graphics.RowEndAddr_Ui8; L_DataRowCount_Ui8++)
	{
		G_SetColumn_Mth(graphics.ColStrtAddr_Ui8);
		G_SetRow_Mth(graphics.RowStrtAddr_Ui8);
		ColCounter = graphics.ColStrtAddr_Ui8;
		uint8_t L_DataCount_Ui8 = 0;
		for(;L_DataCount_Ui8 < graphics.ColEndAddr_Ui8; L_DataCount_Ui8++)
		{
			L_GLCDData64_Ui8 = G_GLCDData64_Ui8Arr[L_DataRowCount_Ui8][L_DataCount_Ui8];
			G_GlcdWrite_Mth(DATAMODE,L_GLCDData64_Ui8);
			ColCounter++;
			if(ColCounter >= 64)
			{
				ColCounter = 0;
				G_SetColumn_Mth(64);
				G_SetRow_Mth(graphics.RowStrtAddr_Ui8);
			}
		}
		graphics.RowStrtAddr_Ui8++;
	}
	graphics.TotalColWrite_Ui8 = 0;
	graphics.TotalRowWrite_Ui8 = 0;
	graphics.RowStrtAddr_Ui8   = 0;
	graphics.RowEndAddr_Ui8    = 0;
	graphics.ColStrtAddr_Ui8   = 0;
	graphics.ColEndAddr_Ui8    = 0;
}

void G_SetRow_Mth(uint8_t L_Row_Ui8)
{
	uint8_t L_Data_ui16 = (L_Row_Ui8 | 0xB8) & 0xBF;
	G_GlcdWrite_Mth(INSMODE,L_Data_ui16);
}

void G_SetColumn_Mth(uint8_t L_Column_Ui8)
{
	uint8_t L_Data_ui8 = 0;
	if(L_Column_Ui8 < 64)
	{
		CS1_RC0 = 0;
		SetDelayUs_Mth(5);
		CS2_RC1 = 1;
		L_Data_ui8 = (uint16_t)(L_Column_Ui8 | 0x40) & 0x7F;
		G_GlcdWrite_Mth(INSMODE,L_Data_ui8);
	}
	else
	{
        CS1_RC0 = 1;
		SetDelayUs_Mth(5);
        CS2_RC1 = 0;
		L_Data_ui8 = (uint16_t)((L_Column_Ui8 - 64) | 0x40) & 0x7F;
		G_GlcdWrite_Mth(INSMODE,L_Data_ui8);
	}
}

void G_GLCDClearDisplay_Mth()
{
	uint8_t X_Addrs,j_Addrs;
	uint8_t L_Data_ui16 = 0x00;
    CS1_RC0 = 1;
    CS2_RC1 = 0;
	for(X_Addrs = 0; X_Addrs < 8; X_Addrs++)
	{
		G_GlcdWrite_Mth(INSMODE,(0xB8)+X_Addrs);
		for(j_Addrs=0; j_Addrs < 64 ; j_Addrs++)
		{
			G_GlcdWrite_Mth(DATAMODE,L_Data_ui16);
		}
	}
    CS1_RC0 = 0;
    CS2_RC1 = 1;
	for(X_Addrs=0;X_Addrs<8;X_Addrs++)
	{
		G_GlcdWrite_Mth(INSMODE,(0xB8)+X_Addrs);
		for(j_Addrs=0;j_Addrs<64;j_Addrs++)
		{
			G_GlcdWrite_Mth(DATAMODE,L_Data_ui16);
		}
	}
}

uint8_t AppMessageLen(uint8_t Message_Ui8)
{
    uint8_t MessageLen_Ui8 = 0;
    uint8_t RowCounte = Message_Ui8;
    uint16_t colmn_Counter = 0;
    for (; AppMessages[RowCounte][colmn_Counter] != '\0'; colmn_Counter++)
    {
        MessageLen_Ui8++;
    }
    return MessageLen_Ui8;
}

void G_ClearGLCEDataBuffer_Mth(void)
{
	for(uint8_t L_DataRowCounter_Ui8 = 0; L_DataRowCounter_Ui8 < 4; L_DataRowCounter_Ui8++)
	{
		for(uint8_t L_DataCounter_Ui8 = 0; L_DataCounter_Ui8 < 20; L_DataCounter_Ui8++)
		{
			G_GLCDData64_Ui8Arr[L_DataRowCounter_Ui8][L_DataCounter_Ui8] = 0x00;
		}
	}
}

void G_ClearGLCDCharBuffer_Mth(void)
{

	for(uint8_t L_DataRowCounter_Ui8 = 0; L_DataRowCounter_Ui8 < 22; L_DataRowCounter_Ui8++)
	{
		G_CharBuffer_Ui8Arr[L_DataRowCounter_Ui8] = 0x00;
	}
}

void SetDelayUs_Mth(uint8_t CountVal)
{
	uint8_t L_DelayCount = CountVal;
	uint8_t L_DelayCounter = 0;
	for(; L_DelayCount > L_DelayCounter ; L_DelayCounter++)
	{
		asm("NOP");
	}
}