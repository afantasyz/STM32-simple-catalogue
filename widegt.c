#include "stm32f10x.h"                  // Device header
#include "widegt.h"
#include "stdlib.h"
#include "OLED.h"
#include "string.h"

#define HeadLine 1
#define Line01 2
#define Line02 3
#define Line03 4

void Widegt_Init(Widegt* w,char* headName)
{
	w->textLength=0;
	strcpy(w->head,headName);
	w->TextList=(TextNode*)malloc(sizeof(TextNode));
	w->nowText=w->TextList;
	OLED_ShowString(HeadLine,1,w->head);
	OLED_ShowString(Line01,1,">>>");
}

void Widegt_Show(Widegt* w)
{
	OLED_ShowString(Line01,3,"                ");
	OLED_ShowString(Line01,1,">>>");
	OLED_ShowString(Line01,3,w->nowText->text);
	if(w->nowText->nextNode!=NULL)
	{
		OLED_ShowString(Line02,3,"                ");
		OLED_ShowString(Line02,3,w->nowText->nextNode->text);
		if(w->nowText->nextNode->nextNode!=NULL)
		{
			OLED_ShowString(Line03,3,"                ");
			OLED_ShowString(Line03,3,w->nowText->nextNode->nextNode->text);
		}
		else
			OLED_ShowString(Line03,3,"              ");		
	}
	else
		OLED_ShowString(Line02,3,"              ");

}

void Widegt_Refresh(Widegt* w,uint8_t dir)
{
	if(dir==1&&w->nowText->nextNode!=NULL)
		w->nowText=w->nowText->nextNode;
	else if(dir==0&&w->nowText->lastNode!=NULL)
		w->nowText=w->nowText->lastNode;
	Widegt_Show(w);
}

void Widegt_InsertTextNode(Widegt* w,char* newNode)
{
	TextNode* tepPtr=(TextNode*)malloc(sizeof(TextNode));
	strcpy(tepPtr->text,newNode);
	tepPtr->textId=w->textLength;
	w->textLength+=1;
	if(w->TextList->nextNode!=NULL)
		w->TextList->nextNode->lastNode=tepPtr; //不能放这里，nextNode可能是空的，也就没有下一个lastNode可言
	tepPtr->nextNode=w->TextList->nextNode;
	tepPtr->lastNode=w->TextList;
	w->TextList->nextNode=tepPtr;
}

void Widegt_DeInit(Widegt* w)
{
	while(w->textLength-->0)
	{
		TextNode* tep=w->TextList->nextNode;
		w->TextList->nextNode=tep->nextNode;
		free(tep);
	}
	free(w->TextList);
	free(w);
}
