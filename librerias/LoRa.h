#ifndef INVERLORA_LORA_H
#define INVERLORA_LORA_H

#include "pico/stdlib.h"
#include "Hardware/spi.h"

namespace Inverlora
{
    namespace nodo
    {
        struct LoRaDescritor
        {
            uint8_t pinReset;
            uint8_t pinDio0;
            float frecuencia;
            uint8_t packetIndex;
            uint8_t implicitHeaderMode;
            uint8_t onReceive;
            uint8_t onTxDone;
        };
        
        class LoRa
        {
            private:
                
                LoRaDescritor LoRaTransmisor;
                Inverlora::hardware::SpiPortConfig spiPort;

            public:
                LoRa(Inverlora::hardware::SpiPortConfig spiPort, LoRaDescritor LoRaIn);
                ~LoRa();

                uint8_t encender(float frecuencia);
                uint8_t leerReguistro(uint8_t direccion);
                uint8_t transmicionSimple(uint8_t direccion, uint8_t valor);

        };
    }
}

#endif