#ifndef INVERLORA_SPI_H
#define INVERLORA_SPI_H

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/spi.h"

namespace Inverlora
{
    namespace hardware
    {
        struct SpiPortConfig
        {
            spi_inst_t* spiPort ;
            uint8_t     pinMISO ;
            uint8_t     pinMOSI ;
            uint8_t     pinCS ; ;
            uint8_t     pinsSCK ; 
        };
        
        
        class Spi
        {
            SpiPortConfig SPIPortConfig;
            public:
                

                Spi(SpiPortConfig spiPConfig);
                ~Spi();

        };
    }
}

#endif