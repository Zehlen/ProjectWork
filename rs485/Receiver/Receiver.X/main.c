#include "main.h"

int main(void)
{
    G_PwrOn_Mth();
    PORTEbits.RE0 = 0;
    while(1)
    {
        
    }
    return 0;
}
