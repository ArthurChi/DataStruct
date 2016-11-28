//
//  LinkList.h
//  DataStruct
//
//  Created by cjfire on 2016/11/28.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>

typedef void LinkList;
typedef void LinkListNode;

// Create
LinkList* LinkList_create();
// Destory
void LinkList_destory(LinkList* list);
// Clear
void LinkList_clear(LinkList* list);
// Insert a node in a position
void LinkList_insert(LinkList* list, LinkListNode* node, int position);
// Get node at postion
LinkListNode* LinkList_node(LinkList* list, int position);
// Delete node at postion
void LinkList_delete(LinkList* list, int position);

int LinkList_getlenght(LinkList* list);

#endif /* LinkList_h */
