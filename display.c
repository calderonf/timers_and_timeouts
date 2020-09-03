

void D_inicie_display (D_Display *disp,int8_t *tempUnidades,int8_t *tempDecenas)
{
    disp->tempUnidades=tempUnidades;
    disp->tempDecenas=tempDecenas;
    disp->mostrando=UNIDADES;
}


void D_Procese_display (D_Display *disp)
{
    switch(disp->mostrando){
        case UNIDADES://mostramos unidades
            disp->mostrando=DECENAS;// cambiar estado
            //muestro la conversión a unidades leidas por el ADC y convertidas
            muestre_en_display(*disp->tempUnidades,UNIDADES ); 

        break;
        case DECENAS://mostrar decenas
            disp->mostrando=UNIDADES;// cambiar estado
            muestre_en_display(*disp->tempDecenas,DECENAS ); 
        default:
            disp->mostrando=DECENAS;
    }
}

void muestre_en_display(uint8_t digito  , uint8_t display )
{
    /*configura el puerto o los puertos que esten usando para si display*/

    /*primero bajar todos los bits del display en el puerto*/    
    PORTA=;
    /*subir solo los necesarios*/
    
    /*primero bafar todos los bits del display en el puerto*/    
    PORTA=;
    /*subir solo los necesarios*/

    /*y dependiendo del valor de display enciende el transistor correspondiente*/
    if(display==UNIDADES){
        PUERTOBDISPDECENAS &= ~TRANDISPDECENAS;
        PUERTODISPUNIDADES |= TRANDISPUNIDADES;
    }
    if(display==DECENAS){
        PUERTODISPUNIDADES &= ~TRANDISPUNIDADES;
        PUERTOBDISPDECENAS |= TRANDISPDECENAS;
    }
}




/*
     a
     _
f | g_  | b
e |  _  | c
     d
anodo o catodo?? prende con 1 o con 0??? prende con 1
0=0b00111111  // muestro un 0
1=0b00000110  // muestro un 1

*/
tablaBCD[12]={0b0011111,0b00000110,...};/*del 0 al 9 y menos y error*/

int8_t num2BCD(int8_t num)
{
    if(num>=12||num<0)
        return tablaBCD[11];/*en la pos 11 de la tabla esta el error*/
    return tablaBCD[num];
}





