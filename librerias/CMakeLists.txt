add_library(
    battery
    battery.h
    battery.cpp
)

add_library(
    puertoAnalogo
    Hardware/puertoAnalogo.h
    Hardware/puertoAnalogo.cpp
)

add_library(
    sensorTemp
    sensorTemp.h
    sensorTemp.cpp
)

add_library(
    spi
    Hardware/spi.h
    Hardware/spi.cpp
)

add_library(
    LoRa
    LoRa.h
    LoRa.cpp
)

target_link_libraries(battery pico_stdlib hardware_adc puertoAnalogo)
target_link_libraries(puertoAnalogo pico_stdlib hardware_adc)
target_link_libraries(sensorTemp pico_stdlib hardware_adc)
target_link_libraries(spi pico_stdlib hardware_adc hardware_spi)
target_link_libraries(LoRa pico_stdlib hardware_adc hardware_spi spi)


target_include_directories(
    battery PUBLIC ${CMAKE_CURRENT_LIST_DIR} 
    puertoAnalogo PUBLIC ${CMAKE_CURRENT_LIST_DIR} 
    sensorTemp PUBLIC ${CMAKE_CURRENT_LIST_DIR} 
    spi PUBLIC ${CMAKE_CURRENT_LIST_DIR} 
)