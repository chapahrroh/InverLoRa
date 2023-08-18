#include "sensorTemp.h"

using namespace InverLoRa::hardware;
using namespace InverLoRa::nodo;

SensorTemperatura::SensorTemperatura(uint8_t puerto):PuertoAnalogo(puerto)
{

}

float SensorTemperatura::leerTemperatura()
{
    uint16_t lecturaPuerto = leerPuerto();
    
    float adc = (float)adc_read() * factorConversionVoltage;
    float result = 27.0f - (adc - 0.706f) / 0.001721f;

    return result;
}