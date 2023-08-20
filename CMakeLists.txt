# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/chapahrroh/Documentos/Proyectos/RPPICO/pico-sdk")

set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(InverLoRa C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()


# Add executable. Default name is the project name, version 0.1
add_executable(InverLoRa src/InverLoRa.cpp )

pico_set_program_name(InverLoRa "InverLoRa")
pico_set_program_version(InverLoRa "0.1")

pico_enable_stdio_uart(InverLoRa 1)
pico_enable_stdio_usb(InverLoRa 0)


pico_add_extra_outputs(InverLoRa)

# librerias standar de RP2040
target_link_libraries(InverLoRa pico_stdlib hardware_adc hardware_spi)


#LIBRERIAS EXCLUSIBAS DE inVERLORA  
target_link_libraries(InverLoRa battery sensorTemp spi LoRa)


# Add the standard include files to the build
target_include_directories(InverLoRa PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)
add_subdirectory(librerias)



