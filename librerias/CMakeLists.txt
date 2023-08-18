add_library(
    battery
    battery.h
    battery.cpp
)

add_library(
    puertoAnalogo
    puertoAnalogo.h
    puertoAnalogo.cpp
)

add_library(
    sensorTemp
    sensorTemp.h
    sensorTemp.cpp
)

add_library(
    spi
    spi.h
    spi.cpp
)

target_link_libraries(battery pico_stdlib hardware_adc puertoAnalogo)
target_link_libraries(puertoAnalogo pico_stdlib hardware_adc)
target_link_libraries(sensorTemp pico_stdlib hardware_adc)
target_link_libraries(spi pico_stdlib hardware_adc)


target_include_directories(
    battery PUBLIC ${CMAKE_CURRENT_LIST_DIR} 
)