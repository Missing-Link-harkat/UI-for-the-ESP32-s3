# UI for ESP32-S3

In this project, an esp32-s3 user interface with a touchscreen has been designed and built. The operating logic of the user interface comes from the WattMatti project, which has not yet been integrated into this project.

## Hardware

This project uses ESP-S3 microcontroller usens the ESP32-S3R8 chip as the main controller. All the settings in platformio.ini file has been configured for this board in particular.

## Features

- toucsreen
- rotation knob
- saves and deletes the settings
- dimmens the screen for sleep mode

## Software

- PlatformIO with Arduino
- EEZ Studio

## Libraries

- lvgl v8.4
- ESP32_Display_Panel v1.0.1
- ESP32_IO_Expander v1.1.0
- eps_lib_utils
