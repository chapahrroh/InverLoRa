#include "battery.h"

using namespace InverLoRa::nodo;
using namespace InverLoRa::hardware;

Battery::Battery(uint8_t puerto): PuertoAnalogo(puerto)
{

    Voltage   = leerVoltage();
    Corriente = leerConsumo();
}


float Battery::leerVoltage()
{
    float result;
    uint16_t lecturaAnaloga = leerPuerto();
    result = lecturaAnaloga * factorConversionVoltage;
    return result;
}

// [ ] configurar para tomar consumo del dispositivo
float Battery::leerConsumo()
{
    const float conversion_factor = 3.3f / (1 << 12);
    uint16_t result = leerPuerto();
    return result;
}