#ifndef __WIDEGT_H
#define __WIDEGT_H

typedef struct TextNode
{
	char text[16];
	struct TextNode* nextNode;
	struct TextNode* lastNode;
	uint8_t textId;
}TextNode;//选项文本链表结点

typedef struct Widegt
{
	TextNode* TextList;
	uint8_t textLength;
	TextNode* nowText;
	char head[16];
}Widegt;//单个界面的文本链表

void Widegt_Show(Widegt* w);//显示文本
void Widegt_Refresh(Widegt* w,uint8_t dir);//更新当前选中
void Widegt_InsertTextNode(Widegt* w,char* newNode);//插入新的元素
void Widegt_Init(Widegt* w,char* headName);//初始化
void Widegt_DeInit(Widegt* w);//回收内存

#endif
