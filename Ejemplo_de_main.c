
#include "nuestrostimers.h"


// En nuestra implementacion esta deberia ser un global 
// si vamos a trabajar por interrupción o deberia estar en el
// espacio de memoria del main.


void main (void)
{
    Tm_Periodico casita;
    Tm_Periodico *tyt;
    tyt=&casita;

    //setup(..);
    Tm_Inicie_periodico (tyt,100);

    for(;;)
    {
        //loop(..);
        if(/*Condicion1 periodica de 1 ms*/)// supongamos que tenemos un timer por hardware de 1 ms
        {
            /*Atencion 1*/
            //reseteamos el timer
            Tm_Procese_tiempo (tyt);
        }
        if(Tm_Hubo_periodico (tyt))// condicion de 100 ms
        {
            Tm_Baje_periodico (tyt);//reset de condicion
            /*atencion de lo que requiere que se haga cada 100 ms*/
            //...
        }
        //if (/*apague el timer tyt*/)
        //    Tm_Termine_periodico (&tyt);
    }
// Nunca deberia llegar aquí
}


