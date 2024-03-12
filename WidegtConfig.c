#include "stm32f10x.h"                  // Device header
#include "WidegtConfig.h"
#include "stdlib.h"

Widegt* Widegt_Load(uint8_t wId)//这个是要展示的页面wid
{
	Widegt* w=(Widegt*)malloc(sizeof(Widegt));
	//根目录
	if(wId==0)
	{
		Widegt_Init(w,"Main Menu");
		Widegt_InsertTextNode(w,"Power Contorl");
		Widegt_InsertTextNode(w,"Tim");
		Widegt_InsertTextNode(w,"ADC");
		Widegt_InsertTextNode(w,"Communicate");
		Widegt_InsertTextNode(w,"Storage");
		Widegt_InsertTextNode(w,"Peripheral");
	}
	//一级目录
	else if(wId==1)
	{
		Widegt_Init(w,"/Power Contorl");
		Widegt_InsertTextNode(w,"BKP");
		Widegt_InsertTextNode(w,"PWR");
		Widegt_InsertTextNode(w,"WDG");
		Widegt_InsertTextNode(w,"RTC");
	}
	else if(wId==2)
	{
		Widegt_Init(w,"/Tim");
		Widegt_InsertTextNode(w,"BKP");
		Widegt_InsertTextNode(w,"PWR");
//		Widegt_InsertTextNode(w,"WDG");
//		Widegt_InsertTextNode(w,"RTC");
	}
	//二级目录
	else if(wId==7)
	{
		Widegt_Init(w,"happy");
		Widegt_InsertTextNode(w,"01");
	}
	return w;
}

void MenuNode_Load(Menu* m,uint8_t wId)//这个是当前页面的id，刷新出当前页的所有下一级menunode
{
	if(wId==0)
	{
		Menu_InsertNode(m->nowNode,1,4);
		Menu_InsertNode(m->nowNode,2,2);
	}
	else if(wId==1)
	{
		Menu_InsertNode(m->nowNode,7,1);
//		Menu_InsertNode(m->nowNode,8,1);
//		Menu_InsertNode(m->nowNode,9,1);
//		Menu_InsertNode(m->nowNode,10,1);
	}
	else if(wId==2)
	{
		
	}
}
