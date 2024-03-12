#include "stm32f10x.h"                  // Device header
#include "Menu.h"
#include "stdlib.h"

void Menu_Init(Menu* m,uint8_t MaxCap)
{
	m->Mroot=(MenuNode*)malloc(sizeof(MenuNode));
	m->nowNode=m->Mroot;
	m->Mroot->MLength=0;
	m->Mroot->wId=0;
	m->Mroot->MaxCap=MaxCap;
}

void Menu_InsertNode(MenuNode* pos,uint8_t wId,uint8_t MaxCap)
{
	if(pos->childPtr==NULL)
		pos->childPtr=(MenuNode**)malloc(sizeof(MenuNode*)*pos->MaxCap);
	pos->childPtr[pos->MLength]=(MenuNode*)malloc(sizeof(MenuNode));
	pos->childPtr[pos->MLength]->parentPtr=pos;
	pos->childPtr[pos->MLength]->wId=wId;
	pos->childPtr[pos->MLength]->MaxCap=MaxCap;
	pos->MLength+=1;
}

void Menu_DeleteNode(Menu* m,MenuNode* pos)
{
	while(pos->MLength-->0)
	{
		free(pos->childPtr[pos->MLength]);
	}
	free(pos);
}
