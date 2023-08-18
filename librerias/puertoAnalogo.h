#ifndef INVERLOTA__PUERTOANALOGO_H
#define INVERLOTA__PUERTOANALOGO_H

#include "pico/stdlib.h"
#include "hardware/adc.h"

namespace InverLoRa
{
    namespace hardware
    {
        class PuertoAnalogo
        {
                uint8_t puerto;
                uint8_t canal;

            public:
                const float factorConversionVoltage = 3.3f / (1 << 12);
                PuertoAnalogo(uint8_t puerto);
                uint16_t leerPuerto();
        };

    }
}

#endif