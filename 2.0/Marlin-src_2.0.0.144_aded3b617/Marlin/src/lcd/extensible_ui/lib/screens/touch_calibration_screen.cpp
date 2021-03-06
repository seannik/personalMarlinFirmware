/********************************
 * touch_calibration_screen.cpp *
 ********************************/

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

#include "../config.h"

#if ENABLED(EXTENSIBLE_UI)

#include "screens.h"

using namespace FTDI;
using namespace Theme;

#define GRID_COLS 4
#define GRID_ROWS 16

void TouchCalibrationScreen::onEntry() {
  CommandProcessor cmd;

  BaseScreen::onEntry();

  if(CLCD::is_touching()) {
    // Ask the user to release the touch before starting,
    // as otherwise the first calibration point could
    // be misinterpreted.
    cmd.cmd(CMD_DLSTART)
       .cmd(CLEAR_COLOR_RGB(bg_color))
       .cmd(CLEAR(true,true,true))
       .cmd(COLOR_RGB(bg_text_enabled))
    #if defined(USE_PORTRAIT_ORIENTATION)
       .font(font_large)
       .text  ( BTN_POS(1,8), BTN_SIZE(4,1), F("Release to begin"))
       .text  ( BTN_POS(1,9), BTN_SIZE(4,1), F("screen calibration"))
    #else
       .font(
        #if defined(LCD_800x480)
          font_large
        #else
          font_medium
        #endif
        )
       .text  ( BTN_POS(1,1), BTN_SIZE(4,16), F("Release to calibrate"))
    #endif
       .cmd(DL::DL_DISPLAY)
       .cmd(CMD_SWAP)
       .execute();

    while(CLCD::is_touching()) {
      #if defined(UI_FRAMEWORK_DEBUG)
        SERIAL_ECHO_START();
        SERIAL_ECHOLNPGM("Waiting for touch release");
      #endif
    }
  }

  // Force a refresh
  cmd.cmd(CMD_DLSTART);
  onRedraw(FOREGROUND);
  cmd.cmd(DL::DL_DISPLAY);
  cmd.execute();
}

void TouchCalibrationScreen::onRefresh() {
  // Don't do the regular refresh, as this would
  // cause the calibration be restarted on every
  // touch.
}

void TouchCalibrationScreen::onRedraw(draw_mode_t) {
  CommandProcessor cmd;
  cmd.cmd(CLEAR_COLOR_RGB(bg_color))
     .cmd(CLEAR(true,true,true))
     .cmd(COLOR_RGB(bg_text_enabled))

  #if defined(USE_PORTRAIT_ORIENTATION)
     .font(font_large)
     .text  ( BTN_POS(1,8), BTN_SIZE(4,1), F("Touch the dots"))
     .text  ( BTN_POS(1,9), BTN_SIZE(4,1), F("to calibrate"))
  #else
     .font(
       #if defined(LCD_800x480)
         font_large
       #else
         font_medium
       #endif
     )
     .text  ( BTN_POS(1,1), BTN_SIZE(4,16), F("Touch the dots to calibrate"))
  #endif
     .cmd(CMD_CALIBRATE);
}

void TouchCalibrationScreen::onIdle() {
  if(!CLCD::is_touching() && !CommandProcessor::is_processing()) {
    GOTO_PREVIOUS();
  }
}

#endif // EXTENSIBLE_UI