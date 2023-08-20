#ifndef INVERLORA__BATTERY_H
#define INVERLORA__BATTERY_H

#include "Hardware/puertoAnalogo.h"

namespace InverLoRa
{
    namespace nodo
    {
        class Battery: public InverLoRa::hardware::PuertoAnalogo
        {
            uint8_t puertoBattery;

            public:
        
                float Voltage;
                float Corriente;
                
                float leerVoltage();
                float leerConsumo();

                Battery(uint8_t puerto);


        };
    }
}

#endif