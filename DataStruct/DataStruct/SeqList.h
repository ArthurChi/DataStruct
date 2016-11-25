//
//  SeqList.h
//  DataStruct
//
//  Created by cjfire on 16/10/20.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#ifndef SeqList_h
#define SeqList_h

#include <stdio.h>

typedef void SeqList;
typedef void SeqListNode;

// Create
SeqList* SeqList_create(int capacity);
// Destory
void SeqList_destory(SeqList* list);
// Clear
void SeqList_clear(SeqList* list);
// Insert a node in a position
void SeqList_insert(SeqList* list, SeqListNode* node, int position);
// Get node at postion
SeqListNode* SeqList_node(SeqList* list, int position);
// Delete node at postion
void SeqList_delete(SeqList* list, int position);

int SeqList_getlenght(SeqList* list);

#endif /* SeqList_h */
