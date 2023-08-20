#include "LoRa.h"

using namespace Inverlora::hardware;
using namespace Inverlora::nodo;

LoRa::LoRa(SpiPortConfig spiPortt, LoRaDescritor LoRaIn)
{
    LoRaTransmisor = LoRaIn;
    spiPort = spiPortt;
}

uint8_t LoRa::encender(float frecuencia)
{
    if(LoRaTransmisor.pinReset != -1)
    {
        gpio_init(LoRaTransmisor.pinReset);
        gpio_set_dir(LoRaTransmisor.pinReset, GPIO_OUT);
    }

        gpio_put(LoRaTransmisor.pinReset, 0);
        sleep_ms(10);
        gpio_put(LoRaTransmisor.pinReset, 1);
        sleep_ms(10);

        Spi spiport(spiport);

        uint8_t version = leerReguistro(0x42);
        if (version != 0x12) 
        {
            return 1;
        }


    return 0;
}

uint8_t LoRa::leerReguistro(uint8_t direccion)
{
    return transmicionSimple(direccion & 0x7f, 0x00);
}

uint8_t LoRa::transmicionSimple(uint8_t direccion, uint8_t valor)
{
    uint8_t respuesta;

    // gpio_put(_ss, 0);

    spi_write_blocking(spiPort.spiPort, &direccion, 1);
    spi_write_read_blocking(spiPort.spiPort, &valor, &respuesta, 1);

    // gpio_put(_ss, 1);

    return respuesta;
}