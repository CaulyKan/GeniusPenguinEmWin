
#include "globals.h"
#include "dialog.h"
#include "GUI.h"

WM_HWIN GuideMainWindow;
WM_HWIN DataShowWindow;
WM_HWIN StateBarWindow;
WM_HWIN GStep1Window;
WM_HWIN GStep2Window;
WM_HWIN GStep7Window;
WM_HWIN LogoWindow;


void MainTask(void)
{
	
	GUI_Init();//��ʼ��emWin/ucGUI
	//CreateFramewin(WM_HBKWIN); //��������,�����������汳��
	SM_InitMainStateMachine();
	SM_InitGuideStateMachine();
	WM_ShowWindow(LogoWindow); //�����ڵ��Ժ�����ʾ����

	while (1) { GUI_Delay(20); } //����GUI_Delay������ʱ20MS(����Ŀ���ǵ���GUI_Exec()����)
}