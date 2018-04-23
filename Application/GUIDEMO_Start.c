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
File        : GUIDEMO_Start.c
Purpose     : GUIDEMO initialization
----------------------------------------------------------------------
*/

//#include "GUIDEMO.h"

/*********************************************************************
*
*       MainTask
*/
//void MainTask(void) {
//  #if GUI_WINSUPPORT
//    WM_SetCreateFlags(WM_CF_MEMDEV);
//  #endif
//  GUI_Init();
//  #if GUI_WINSUPPORT
//    WM_MULTIBUF_Enable(1);
//  #endif
//  GUIDEMO_Main();
//}

/*************************** End of file ****************************/

#include "globals.h"
#include "dialog.h"
#include "GUI.h"

WM_HWIN GuideMainWindow;
WM_HWIN DataShowWindow;
WM_HWIN GStep1Window;
WM_HWIN GStep2Window;
WM_HWIN GStep7Window;


static U8 motor_open_flag; //������ر�־ 0-�� 1-��
static U8 sound_disable_flag; //������־ 0-���� 1-����
static U8 sound_level; //���������ȼ� 0-�ޱ��� 1-�͵ȼ� 2-�еȼ� 3-�ߵȼ�
static U8 SD_OK_Flag; //SD��״̬ 0-�쳣 1-����
static U32 motor_open_time; //����ϵ�ʱ�䣬��sΪ��λ��RTCʱ��
static U32 timestamp; //ʱ���
static U16 ADC_FLOW = 0; //����ԭʼ����
static U16 ADC_MOTORSPEED = 0; //ת��ԭʼ����
static struct calendar //����
{
	U8 hour;
	U8 min;
	U8 sec;
	U16 w_year;
	U8 w_month;
	U8 w_date;
	U8 week;
};



void MainTask(void)
{
	
	GUI_Init();//��ʼ��emWin/ucGUI
	//CreateFramewin(WM_HBKWIN); //��������,�����������汳��

	SM_InitMainStateMachine();
	SM_InitGuideStateMachine();

	while (1) { GUI_Delay(20); } //����GUI_Delay������ʱ20MS(����Ŀ���ǵ���GUI_Exec()����)
}