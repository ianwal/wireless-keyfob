# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.3.1)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico2_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(wireless-keyfob C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

set(PICO_CXX_ENABLE_RTTI 1)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_compile_options(-fdiagnostics-color)

# Add executable. Default name is the project name, version 0.1

add_executable(wireless-keyfob 
    wireless-keyfob.cpp
    # server.cpp
)

pico_set_program_name(wireless-keyfob "wireless-keyfob")
pico_set_program_version(wireless-keyfob "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(wireless-keyfob 0)
pico_enable_stdio_usb(wireless-keyfob 1)

# Add the standard library to the build
target_link_libraries(wireless-keyfob
        pico_btstack_ble
        pico_btstack_cyw43
        pico_stdlib
        pico_cyw43_arch_none
        hardware_adc # TODO: Remove, only needed for server example
)

# Add the standard include files to the build
target_include_directories(wireless-keyfob PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

target_compile_definitions(wireless-keyfob PRIVATE
    #WANT_HCI_DUMP=1
)

pico_btstack_make_gatt_header(wireless-keyfob PRIVATE "${CMAKE_CURRENT_LIST_DIR}/temp_sensor.gatt")

pico_add_extra_outputs(wireless-keyfob)
