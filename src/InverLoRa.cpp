#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/adc.h"

#include <battery.h>
#include <sensorTemp.h>

using namespace InverLoRa::nodo;


int main()
{
    Battery bateria(26);
    SensorTemperatura SensTemp(27);

    float carga = bateria.leerVoltage();
    float temp = SensTemp.leerTemperatura();
    
    stdio_init_all();

    

    printf("ESTA VIVOOOO");
    printf("temperatura: {} C",temp);
    printf("voltage: {} V",carga);
    

    return 0;
}