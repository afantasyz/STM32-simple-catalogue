#ifndef __WIDEGTCONFIG_H
#define __WIDEGTCONFIG_H

#include "widegt.h"
#include "Menu.h"

Widegt* Widegt_Load(uint8_t wId);
//当前为了节约堆空间采用的策略是每次切换页面后把不展示的widegt释放掉，如果要进一步节约空间
//可以每次加载至当前节点的下一层，而不是加载整个目录树

void MenuNode_Load(Menu* m,uint8_t wId);

#endif
