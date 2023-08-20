#include "spi.h"

using namespace::Inverlora::hardware;


Spi::Spi(SpiPortConfig SpiPConfig)
{

    SPIPortConfig = SpiPConfig;

    spi_init(SpiPConfig.spiPort,12500);
    gpio_set_function(SpiPConfig.pinMISO, GPIO_FUNC_SPI);
    gpio_set_function(SpiPConfig.pinsSCK, GPIO_FUNC_SPI);
    gpio_set_function(SpiPConfig.pinMOSI, GPIO_FUNC_SPI);
    gpio_set_function(SpiPConfig.pinCS, GPIO_FUNC_SPI);
}

Spi::~Spi()
{
    spi_deinit(SPIPortConfig.spiPort);
}



