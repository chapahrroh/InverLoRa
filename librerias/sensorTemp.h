#ifndef INVERLORA_SENSORTEMP_H
#define INVERLORA_SENSORTEMP_H

#include "Hardware/puertoAnalogo.h"

namespace InverLoRa
{
    namespace nodo
    {
        class SensorTemperatura: InverLoRa::hardware::PuertoAnalogo
        {
            public:
                SensorTemperatura(uint8_t puerto);
                float leerTemperatura();
            
        };
    }
}

#endif