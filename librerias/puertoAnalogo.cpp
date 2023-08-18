#include  "puertoAnalogo.h"

using namespace InverLoRa::hardware;

PuertoAnalogo::PuertoAnalogo(uint8_t puertoA)
{
    puerto = puertoA;
    // seleccionar canal correcto para el puerto 
    switch(puertoA)
    {
        case 26:
            PuertoAnalogo::canal = 0;
            break;
        case 27:
            PuertoAnalogo::canal = 1;
            break;
        case 28:
            PuertoAnalogo::canal = 2;
            break;
        case 29:
            PuertoAnalogo::canal = 3;
            break;
    }
    adc_init();
    adc_gpio_init(puertoA);
    adc_select_input(canal);
}

uint16_t PuertoAnalogo::leerPuerto()
{
    if(adc_get_selected_input() != PuertoAnalogo::canal)
    {
        adc_select_input(PuertoAnalogo::canal);
    }

    return adc_read();
}