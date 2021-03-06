/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Font Converter (Demoversion) for emWin version 5.46         *
*        Compiled Dec 12 2017, 16:37:03                              *
*                                                                    *
*        (c) 1998 - 2017 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: 333.c                                                 *
* Font:        ����                                                  *
* Height:      33                                                    *
*                                                                    *
**********************************************************************
*                                                                    *
* Initial font height:  33                                           *
* Range disabled:       0000 - FFFF                                  *
* Character enabled:   0x81E3 (33251)                                *
*                                                                    *
**********************************************************************
*/

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

/* The following line needs to be included in any file selecting the
   font.
*/
extern GUI_CONST_STORAGE GUI_FONT GUI_Font333;

/* Start of unicode area <CJK Unified Ideographs> */
GUI_CONST_STORAGE unsigned char acGUI_Font333_81E3[165] = { /* code 81E3 */
  XXXXXXXX,XXXXXXXX,XXXXXXXX,XXXXXXXX,XXXXXXXX,
  X_______,________,________,________,_X______,
  X_______,________,________,________,_X______,
  X___XXXX,XXXXXXXX,XXXXXXXX,XXXXXX__,_X______,
  X___XXXX,XXXXXXXX,XXXXXXXX,XXXXXX__,_X______,
  X___XXX_,________,_XX_____,________,_X______,
  X___XXX_,________,_XX_____,________,_X______,
  X____XX_,________,_XX_____,________,_X______,
  X____XX_,________,_XX_____,________,_X______,
  X____XX_,________,_XX_____,________,_X______,
  X____XX_,________,_XX_____,________,_X______,
  X____XXX,XXXXXXXX,XXXXXXXX,XXXX____,_X______,
  X____XXX,XXXXXXXX,XXXXXXXX,XXXX____,_X______,
  X____XX_,________,________,_XXX____,_X______,
  X____XX_,________,________,_XXX____,_X______,
  X____XX_,________,________,_XXX____,_X______,
  X____XX_,________,________,_XXX____,_X______,
  X____XX_,________,________,_XXX____,_X______,
  X____XX_,________,________,_XXX____,_X______,
  X____XXX,XXXXXXXX,XXXXXXXX,XXXX____,_X______,
  X____XXX,XXXXXXXX,XXXXXXXX,XXXX____,_X______,
  X____XX_,________,_XX_____,________,_X______,
  X____XX_,________,_XX_____,________,_X______,
  X____XX_,________,_XX_____,________,_X______,
  X____XX_,________,_XX_____,________,_X______,
  X____XX_,________,_XX_____,________,_X______,
  X___XXX_,________,_XX_____,________,_X______,
  X___XXXX,XXXXXXXX,XXXXXXXX,XXXXXXX_,_X______,
  X___XXXX,XXXXXXXX,XXXXXXXX,XXXXXXX_,_X______,
  X___XXXX,XXXXXXXX,XXXXXXXX,XXXXXXX_,_X______,
  X_______,________,________,________,_X______,
  X_______,________,________,________,_X______,
  XXXXXXXX,XXXXXXXX,XXXXXXXX,XXXXXXXX,XXXXXXXX};

GUI_CONST_STORAGE GUI_CHARINFO GUI_Font333_CharInfo[1] = {
   {  34,  34,  5, acGUI_Font333_81E3 } /* code 81E3 */
};

GUI_CONST_STORAGE GUI_FONT_PROP GUI_Font333_Prop1 = {
   0x81E3 /* first character */
  ,0x81E3 /* last character  */
  ,&GUI_Font333_CharInfo[  0] /* address of first character */
  ,(GUI_CONST_STORAGE GUI_FONT_PROP *)0 /* pointer to next GUI_FONT_PROP */
};

GUI_CONST_STORAGE GUI_FONT GUI_Font333 = {
   GUI_FONTTYPE_PROP /* type of font    */
  ,33 /* height of font  */
  ,33 /* space of font y */
  ,1 /* magnification x */
  ,1 /* magnification y */
  ,{&GUI_Font333_Prop1}
  ,28 /* Baseline */
  ,15 /* Height of lowercase characters */
  ,23 /* Height of capital characters */
};

