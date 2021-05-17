/************
 * config.h *
 ************/

/****************************************************************************
 *   Written By Marcio Teixeira 2018 - Aleph Objects, Inc.                  *
 *                                                                          *
 *   This program is free software: you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published by   *
 *   the Free Software Foundation, either version 3 of the License, or      *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   This program is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU General Public License for more details.                           *
 *                                                                          *
 *   To view a copy of the GNU General Public License, go to the following  *
 *   location: <http://www.gnu.org/licenses/>.                              *
 ****************************************************************************/

#pragma once

// Define the display board used (see "ftdi_eve_boards.h" for definitions)

//#define LCD_FTDI_VM800B35A        // FTDI 3.5" 320x240 with FT800
//#define LCD_4DSYSTEMS_4DLCD_FT843 // 4D Systems 4.3" 480x272
//#define LCD_HAOYU_FT800CB         // Haoyu with 4.3" or 5" 480x272
#define LCD_HAOYU_FT810CB         // Haoyu with 5" 800x480
//#define LCD_ALEPHOBJECTS_CLCD_UI  // Aleph Objects Color LCD User Interface

// Leave the following commented out to use a board's default resolution.
// If you have changed the LCD panel, you may override the resolution
// below (see "ftdi_eve_resolutions.h" for definitions):

//#define TOUCH_UI_320x240
//#define TOUCH_UI_480x272
#define TOUCH_UI_800x480

// Select interfacing pins, the following pin specifiers are supported:
//
//     ARDUINO_DIGITAL_1  - Arduino pin via digitalWrite/digitalRead
//     AVR_A1             - Fast AVR port access via PORTA/PINA/DDRA
//     1                  - When compiling Marlin, use Marlin pin IDs.

// The pins for CS and MOD_RESET (PD) must be chosen.
    #define CLCD_MOD_RESET      ARDUINO_DIGITAL_9
    #define CLCD_SPI_CS         ARDUINO_DIGITAL_10

// If using software SPI, specify pins for SCLK, MOSI, MISO
//#define CLCD_USE_SOFT_SPI
#if defined(CLCD_USE_SOFT_SPI)
    #define CLCD_SOFT_SPI_SCLK  ARDUINO_DIGITAL_13
    #define CLCD_SOFT_SPI_MOSI  ARDUINO_DIGITAL_11
    #define CLCD_SOFT_SPI_MISO  ARDUINO_DIGITAL_12
#endif

// Defines how to orient the display. An inverted (i.e. upside-down) display
// is supported on the FT800. The FT810 or better also support a portrait
// and mirrored orientation.
//#define TOUCH_UI_INVERTED
//#define TOUCH_UI_PORTRAIT
//#define TOUCH_UI_MIRRORED

// Enable this to debug the event framework
//#define UI_FRAMEWORK_DEBUG

// Sets the SPI speed in Hz

#define SPI_FREQUENCY 8000000