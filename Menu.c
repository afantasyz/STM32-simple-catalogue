#include "stm32f10x.h"                  // Device header
#include "Menu.h"
#include "stdlib.h"
#include "WidegtConfig.h"

void Menu_Init(Menu* m,uint8_t cap)
{
	m->Mroot=(MenuNode*)malloc(sizeof(MenuNode));
	m->nowNode=m->Mroot;
	m->Mroot->isLeaf=1;
	m->Mroot->MLength=0;
	m->Mroot->wId=0;
	m->Mroot->MaxCap=cap;
}

void Menu_InsertNode(MenuNode* pos,uint8_t wId,uint8_t cap)
{
	if(pos->childPtr==NULL)
		pos->childPtr=(MenuNode**)malloc(sizeof(MenuNode*)*pos->MaxCap);
	pos->isLeaf=0;
	pos->childPtr[pos->MLength]=(MenuNode*)malloc(sizeof(MenuNode));//正确的，前面只是开辟的数组指针的空间，每个元素的空间得new
	pos->childPtr[pos->MLength]->isLeaf=1;
	pos->childPtr[pos->MLength]->parentPtr=pos;
	pos->childPtr[pos->MLength]->wId=wId;	
	pos->childPtr[pos->MLength]->MaxCap=cap;
	pos->MLength+=1;
}

void Menu_DeleteNode(Menu* m,MenuNode* pos)
{
	while(pos->MLength-->0)
	{
		free(pos->childPtr[pos->MLength]);
	}
//	free(pos->childPtr);
	pos->isLeaf=1;
	pos->MLength=0;
}

void Menu_EnterWidegt(Menu* m,uint8_t Pnum)
{
	if(m->nowNode->MLength==0)
		MenuNode_Load(m,m->nowNode->wId);
	if(m->nowNode->isLeaf==0)
	{
		if(Pnum<m->nowNode->MLength)
		{
			Widegt_DeInit(m->nowNode->w);
			m->nowNode=m->nowNode->childPtr[Pnum];			
			m->nowNode->w=Widegt_Load(m->nowNode->wId);
			Widegt_Show(m->nowNode->w);
		}
	}
}

void Menu_ExitWidegt(Menu* m)
{
	if(m->nowNode!=m->Mroot)
	{
		Widegt_DeInit(m->nowNode->w);
		m->nowNode=m->nowNode->parentPtr;
		Menu_DeleteNode(m,m->nowNode);
		m->nowNode->w=Widegt_Load(m->nowNode->wId);
		Widegt_Show(m->nowNode->w);
	}
}
