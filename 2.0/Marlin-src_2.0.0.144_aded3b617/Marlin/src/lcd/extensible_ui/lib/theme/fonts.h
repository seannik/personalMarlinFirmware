/***********
 * fonts.h *
 ***********/

/****************************************************************************
 *   Written By Mark Pelletier  2017 - Aleph Objects, Inc.                  *
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

namespace Theme {
  #if defined(LCD_800x480)
    #if defined(USE_PORTRAIT_ORIENTATION)
      constexpr int16_t  font_tiny     = 26;
      constexpr int16_t  font_xsmall   = 28;
      constexpr int16_t  font_small    = 29;
      constexpr int16_t  font_medium   = 30;
      constexpr int16_t  font_large    = 30;
      constexpr int16_t  font_xlarge   = 31;
    #else
      constexpr int16_t  font_tiny     = 27;
      constexpr int16_t  font_xsmall   = 29;
      constexpr int16_t  font_small    = 30;
      constexpr int16_t  font_medium   = 30;
      constexpr int16_t  font_large    = 31;
      constexpr int16_t  font_xlarge   = 31;
    #endif
    constexpr float      icon_scale    = 1.0;
  #elif defined(LCD_480x272)
    #if defined(USE_PORTRAIT_ORIENTATION)
    constexpr int16_t  font_tiny     = 26;
    constexpr int16_t  font_xsmall   = 26;
    constexpr int16_t  font_small    = 26;
    constexpr int16_t  font_medium   = 27;
    constexpr int16_t  font_large    = 28;
    constexpr int16_t  font_xlarge   = 29;
    constexpr float    icon_scale    = 0.7;
    #else
    constexpr int16_t  font_tiny     = 26;
    constexpr int16_t  font_xsmall   = 26;
    constexpr int16_t  font_small    = 27;
    constexpr int16_t  font_medium   = 28;
    constexpr int16_t  font_large    = 30;
    constexpr int16_t  font_xlarge   = 31;
    constexpr float    icon_scale    = 0.6;
    #endif
  #elif defined(LCD_320x240)
    #if defined(USE_PORTRAIT_ORIENTATION)
    constexpr int16_t  font_tiny     = 26;
    constexpr int16_t  font_xsmall   = 26;
    constexpr int16_t  font_small    = 26;
    constexpr int16_t  font_medium   = 27;
    constexpr int16_t  font_large    = 27;
    constexpr int16_t  font_xlarge   = 28;
    constexpr float    icon_scale    = 0.6;
    #else
    constexpr int16_t  font_tiny     = 26;
    constexpr int16_t  font_xsmall   = 26;
    constexpr int16_t  font_small    = 26;
    constexpr int16_t  font_medium   = 27;
    constexpr int16_t  font_large    = 29;
    constexpr int16_t  font_xlarge   = 30;
    constexpr float    icon_scale    = 0.5;
    #endif
  #endif
}