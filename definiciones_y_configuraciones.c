#include "display.h"

void DyC_Procese_ADC(int8_t *temperatura,int8_t *tempUnidades,int8_t *tempDecenas)
{
    short adcval=leaADC();
    *temperatura=convierta_a_Celsius(adcval);
    *tempUnidades=saqueUnidades(*temperatura);
    *tempDecenas=saqueDecenas(*temperatura);
    *tempUnidades=num2BCD(*tempUnidades);
    *tempDecenas=num2BCD(*tempDecenas);

    //no tengo retun :P
}