#ifndef INVERLORA_SPI_H
#define INVERLORA_SPI_H

#include "pico/stdlib.h"
#include "hardware/adc.h"

namespace Inverlora
{
    namespace hardware
    {
        class Spi
        {
                uint8_t cs;
                
            public:
                Spi();

        };
    }
}

#endif