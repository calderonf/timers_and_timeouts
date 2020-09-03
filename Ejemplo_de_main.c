#include "nuestrostimers.h"
#include "definiciones_y_configuraciones.h"

// En nuestra implementacion esta deberia ser un global 
// si vamos a trabajar por interrupción o deberia estar en el
// espacio de memoria del main.


void main (void)
{
    Tm_Periodico sondeoADC,sondeoDisplay;
    // suponemos que int8_t es un typedef de char entero con sigo de 8 bits
    
    int8_t temperatura;//ya va a estar en celsius

    int8_t tempUnidades;//vamos a guardar el BCD de unidades
    int8_t tempDecenas;//vamos a guardar el BCD de decenas    
    Tm_Inicie_periodico (&sondeoADC,TIEMPOADC);// iniciar periodico de ADC
    Tm_Inicie_periodico (&sondeoDisplay,TIEMPODISPLAY);// iniciar periodico de Display

    for(;;)
    {
        //loop(..);
        if(/*Condicion1 periodica de 1 ms*/)// supongamos que tenemos un timer por hardware de 1 ms
        {
            /*Atencion 1*/
            //reseteamos el timer
            Tm_Procese_tiempo (&sondeoADC);
            Tm_Procese_tiempo (&sondeoDisplay);
        }
        if(Tm_Hubo_periodico (&sondeoADC))// condicion de ADC
        {
            Tm_Baje_periodico (&sondeoADC);//reset de condicion ADC
            /*en este lugar leemos el ADC y convertimos el valor leido a 
             grados y a unidades y decenas para el display
            */
            DyC_Procese_ADC(&temperatura,&tempUnidades,&tempDecenas);
        }
        if(Tm_Hubo_periodico (&sondeoDisplay))// condicion de Display entra cada 
        //TIEMPODISPLAY 10 milisegundos
        {
            Tm_Baje_periodico (&sondeoDisplay);//reset de condicion
            DyC_Procese_Display(&tempUnidades,&tempDecenas);
        }
        //if (/*apague el timer tyt*/)
        //    Tm_Termine_periodico (&tyt);
    }
// Nunca deberia llegar aquí
}