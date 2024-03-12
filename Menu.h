#ifndef __MENU_H
#define __MENU_H


typedef struct MenuNode
{
	uint8_t wId;
	struct MenuNode* parentPtr;
	struct MenuNode* *childPtr;
	uint8_t MaxCap;
	uint8_t MLength;
}MenuNode;//菜单树一个节点

typedef struct Menu
{
	MenuNode* Mroot;
	MenuNode* nowNode;
}Menu;//整个菜单目录

void Menu_Init(Menu* m,uint8_t MaxCap);//初始化
void Menu_InsertNode(MenuNode* pos,uint8_t wId,uint8_t MaxCap);//插入菜单节点
void Menu_DeleteNode(Menu* m,MenuNode* pos);//删除节点

#endif
