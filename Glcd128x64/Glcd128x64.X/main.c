/*
 * File:   main.c
 * Author: 91865
 *
 * Created on December 29, 2024, 8:22 AM
 */


#include "main.h"

void main(void) {
    G_PowrOn_Mth();
    G_initgraphicsVriables_Mth();
    while(1)
    {
        M_SystemFlow_Mth();
    }
    
}
