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
            Tm_Procese_tiempo (sondeoDisplay);
        }
        if(Tm_Hubo_periodico (&tyt))// condicion de 100 ms
        {
            Tm_Baje_periodico (&tyt);//reset de condicion
            /*atencion de lo que requiere que se haga cada 100 ms*/
            //...
        }
        //if (/*apague el timer tyt*/)
        //    Tm_Termine_periodico (&tyt);
    }
// Nunca deberia llegar aquí
}


