#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "widegt.h"
#include "Menu.h"
#include "WidegtConfig.h"
#include "Key.h"
#include "stdlib.h"

static Menu MainMenu;

void Program_Init(void);
	
int main(void)
{
	OLED_Init();
	Key_Init('B',GPIO_Pin_15);
	Key_Init('B',GPIO_Pin_12);
	Key_Init('A',GPIO_Pin_9);
	Key_Init('A',GPIO_Pin_12);//四个按键分别代表确定，取消，上，下
	Program_Init();
	
	while(1)
	{
		if(KeyValue('B',GPIO_Pin_15)==1)
		{
			Widegt_Refresh(MainMenu.nowNode->w,1);
		}
		
		if(KeyValue('B',GPIO_Pin_12)==1)
		{
			Menu_EnterWidegt(&MainMenu,MainMenu.nowNode->w->nowText->textId);
		}
		
		if(KeyValue('A',GPIO_Pin_9)==1)
		{
			Widegt_Refresh(MainMenu.nowNode->w,0);
		}
		
		if(KeyValue('A',GPIO_Pin_12)==1)
		{
			Menu_ExitWidegt(&MainMenu);
		}
		
	}
}

void Program_Init(void)
{	
	//根目录
	Menu_Init(&MainMenu,6);
	MainMenu.Mroot->w=Widegt_Load(0);
	Widegt_Show(MainMenu.Mroot->w);
}
