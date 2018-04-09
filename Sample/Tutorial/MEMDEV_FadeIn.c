/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2014  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.26 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : MEMDEV_FadeIn.c
Purpose     : Demonstrates how to use memory devices for fade in effect
Requirements: WindowManager - ( )
              MemoryDevices - (x)
              AntiAliasing  - ( )
              VNC-Server    - ( )
              PNG-Library   - ( )
              TrueTypeFonts - ( )
----------------------------------------------------------------------
*/

#include "GUI.h"

/*******************************************************************
*
*       Static data
*
********************************************************************
*/
#include "GUI.h"

static const GUI_COLOR _ColorsSeggerLogoBlue16[] = {
     0x000000
  ,  0x000080
  ,  0x008000
  ,  0x008080
  ,  0x800000
  ,  0x800080
  ,  0x808000
  ,  0x808080
  ,  0xC0C0C0
  ,  0x0000FF
  ,  0x00FF00
  ,  0x00FFFF
  ,  0xFF0000
  ,  0xFF00FF
  ,  0xFFFF00
  ,  0xFFFFFF
};

static const GUI_LOGPALETTE _PalSeggerLogoBlue16 = {
  16,	// number of entries
  0, 	// No transparency
  &_ColorsSeggerLogoBlue16[0]
};

static const unsigned char _acSeggerLogoBlue16[] = {
  0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77,
  0x77, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77,
  0x70, 0x00, 0x03, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x70, 0x00, 0x07,
  0x70, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCC, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x77, 0x00, 0x07, 0x7F, 0xFF, 0xFF, 0xF7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF8, 0x77, 0x00, 0x07, 0x8F, 0xFF, 0xFF, 0xFF, 0xF8, 0x77, 0x00, 0x07, 0x8F, 0xFF, 0xFF, 0xFF, 0x70, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x70, 0x00, 0x00, 0x00, 0x07, 0x8F, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x8F, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0x70, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x70, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0x70, 0x07, 0xFF, 0xF8, 0x00, 0x0F, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x00, 0x78, 0xFF, 0x87, 0x00, 0x0F, 0xFF, 0xF7, 0x00, 0x78, 0xFF, 0x87, 0x00, 0x0F, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0x70, 0x07, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0x80, 0x7F, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x07, 0xFF, 0xFF, 0xFF, 0x70, 0x7F, 0xFF, 0x80, 0x07, 0xFF, 0xFF, 0xFF, 0x70, 0x7F, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0x70, 0x07, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x08, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x08, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x07, 0x7F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0x70, 0x07, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x70, 0x00, 0x00, 0x7F, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x00, 0x0F, 0xFF, 0xF7, 0x00, 0x00, 0x07, 0xFF, 0x00, 0x0F, 0xFF, 0xF7, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0x8C, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x00, 0x07, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xF7, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x0F, 0xFF, 0xF7, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xF8, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x8F, 0xFF, 0xFF, 0x80, 0x00, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x08, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0xFF, 0x70, 0x08, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0x70, 0x07, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0xCC, 0xCC, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xF0, 0x00, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x07, 0xFF, 0xFF, 0xFF, 0x70, 0x00, 0xFF, 0x80, 0x07, 0xFF, 0xFF, 0xFF, 0x70, 0x00, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x00, 0x8F, 0xFF, 0x70, 0x07, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x00, 0x78, 0xFF, 0xF7, 0x00, 0x00, 0xFF, 0xF7, 0x00, 0x78, 0xFF, 0xF7, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xC8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0x70, 0x00, 0x00, 0x00, 0x07, 0x00, 0xFF, 0xFF, 0x70, 0x00, 0x00, 0x00, 0x07, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xF7, 0x00, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x70, 0x00, 0x78, 0xFF, 0xFF, 0xF7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF8, 0x77, 0x00, 0x77, 0xF8, 0x07, 0xFF, 0xFF, 0xF8, 0x77, 0x00, 0x77, 0xF8, 0x07, 0xFF, 0xFF, 0x70, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x70, 0x7F, 0xFF, 0xFF, 0xF8, 0x07, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x07,
  0x70, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x07,
  0x70, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x07,
  0x70, 0x00, 0x07, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x70, 0x00, 0x07,
  0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77,
  0x77, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x77,
  0x77, 0x77, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x77, 0x77
};

static const GUI_BITMAP _bmSeggerLogoBlue = {
 138,                   // XSize
 65,                    // YSize
 69,                    // BytesPerLine
 4,                     // BitsPerPixel
 _acSeggerLogoBlue16,   // Pointer to picture data (indices)
 &_PalSeggerLogoBlue16  // Pointer to palette
};

/*******************************************************************
*
*       Static code
*
********************************************************************
*/
/*******************************************************************
*
*       _DemoFade
*/
static void _DemoFade(void) {
  GUI_MEMDEV_Handle hMem0;
  GUI_MEMDEV_Handle hMem1;
  GUI_RECT          Rect = {0};
  int               x;
  int               y;
  int               xSize;
  int               ySize;

  xSize = LCD_GetXSize();
  ySize = LCD_GetYSize();
  hMem0 = GUI_MEMDEV_CreateFixed(0, 0, 138, 65, GUI_MEMDEV_NOTRANS, GUI_MEMDEV_APILIST_32, GUICC_888); // Contains the text
  hMem1 = GUI_MEMDEV_CreateFixed(0, 0, 138, 65, GUI_MEMDEV_NOTRANS, GUI_MEMDEV_APILIST_32, GUICC_888); // Contains the bitmap
  x = (xSize - _bmSeggerLogoBlue.XSize) / 2;
  y = (ySize - _bmSeggerLogoBlue.YSize) / 3 * 2;
  Rect.x1 = _bmSeggerLogoBlue.XSize - 1;
  Rect.y1 = _bmSeggerLogoBlue.YSize - 1;
  //
  // Fill memory device with some text
  //
  GUI_MEMDEV_Select(hMem0);
  GUI_SetColor(GUI_RED);
  GUI_SetFont(&GUI_Font32B_ASCII);
  GUI_SetTextMode(GUI_TM_TRANS);
  GUI_DispStringInRect("Fade in", &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
  GUI_DrawRectEx(&Rect);
  //
  // Fill memory device with bitmap
  //
  GUI_MEMDEV_Select(hMem1);
  GUI_DrawBitmap(&_bmSeggerLogoBlue, 0, 0);
  //
  // Set device positions
  //
  GUI_MEMDEV_SetOrg(hMem0, x, y);
  GUI_MEMDEV_SetOrg(hMem1, x, y);
  GUI_MEMDEV_Select(0);
  //
  // Fading loop
  //
  while (1) {
    GUI_MEMDEV_FadeDevices(hMem0, hMem1, 1000);
    GUI_MEMDEV_FadeDevices(hMem1, hMem0, 1000);
  }
}

/*******************************************************************
*
*       Public code
*
********************************************************************
*/
/*******************************************************************
*
*       MainTask
*/
void MainTask(void) {
  int xSizeH;

  GUI_Init();
  xSizeH = LCD_GetXSize() / 2;
  GUI_SetColor(GUI_WHITE);
  GUI_SetFont(&GUI_Font24_ASCII);
  GUI_DispStringHCenterAt("Fading sample", xSizeH, 5);
  GUI_SetFont(&GUI_Font16B_ASCII);
  GUI_DispStringHCenterAt("Shows how to use memory devices\nfor a fading effect", xSizeH, 40);
  _DemoFade();
  while (1) {
    GUI_Delay(100);
  }
}

/*************************** End of file ****************************/
