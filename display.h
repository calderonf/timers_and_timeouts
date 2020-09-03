
#if !defined(DISPLAY_H)
#define DISPLAY_H
#ifdef __cplusplus
extern "C" {
#endif
//#include <stddef.h>
typedef struct D_Display D_Display;

#define UNIDADES // si e estado esta en este muestro unidades
#define DECENAS  // si el estado esta en este muestro decenas

struct D_Display
{
    int8_t *tempUnidades;
    int8_t *tempDecenas;
    int8_t mostrando;
};

//funciones para  procesar tiempo
void Tm_Procese_tiempo (Tm_Periodico *ctp);


//funciones de tiempos periodicos para timers
void Tm_Inicie_periodico (Tm_Periodico *ctp,unsigned int periodo);
char Tm_Hubo_periodico (Tm_Periodico *ctp);
void Tm_Baje_periodico (Tm_Periodico *ctp);
void Tm_Termine_periodico (Tm_Periodico *ctp);

//funciones de timeout
void Tm_Inicie_timeout (Tm_Periodico *ctp,unsigned int tiempo);
char Tm_Hubo_timeout (Tm_Periodico *ctp);
void Tm_Baje_timeout (Tm_Periodico *ctp);
#ifdef __cplusplus
} // extern "C"
#endif
#endif
