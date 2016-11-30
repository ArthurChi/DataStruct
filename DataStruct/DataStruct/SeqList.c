//
//  SeqList.c
//  DataStruct
//
//  Created by cjfire on 16/10/20.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#include "SeqList.h"
#include <stdlib.h>
#include <string.h>

typedef struct _tag_SeqList {
    
    unsigned long *node;
    int length;
    int capacity;
    
} TSeqList;

// Create
SeqList* SeqList_create(int capature) {
    
    TSeqList* list = NULL;
    
    if (capature < 0) {
        return NULL;
    }
    
    list = (TSeqList*)malloc(sizeof(TSeqList) * capature);
    
    if (list == NULL) {
        printf("内存分配失败");
        return NULL;
    }
    
    memset(list, 0, sizeof(TSeqList));
    
    list->node = malloc(sizeof(SeqListNode*) * capature);
    
    if (list->node == NULL) {
        printf("内存分配失败");
        return NULL;
    }
    
    memset(list->node, 0, sizeof(unsigned long) * capature);
    
    list->length = 0;
    list->capacity = capature;
    
    return list;
}

// Destory
void SeqList_destory(SeqList* list) {
    
    if (list == NULL) {
        return;
    }
    
    free(list);
}
// Clear
void SeqList_clear(SeqList* list) {
    
    if (list == NULL) {
        return;
    }
    
    TSeqList* tList = list;
    tList->length = 0;
}

// Insert a node in a position
void SeqList_insert(SeqList* list, SeqListNode* node, int position) {

    if (list == NULL || node == NULL) {
        return;
    }
    
    TSeqList* tList = list;
    
    if (position >= tList->capacity || position < 0) {
        return;
    }
    
    if (tList->length == tList->capacity) {
        return;
    }
    
    if (position > tList->length) {
        return;
    }
    
    for (int i = tList->length; i > position; i--) {
        tList->node[i] = tList->node[i-1];
    }
    
    tList->node[position] = (unsigned long)node;
    tList->length ++;
}

// Get node at postion
SeqListNode* SeqList_node(SeqList* list, int position) {
    
    SeqListNode* ret = NULL;
    TSeqList* tList = list;
    
    if (tList == NULL || position >= tList->length || position < 0) {
        return NULL;
    }
    
    ret = (SeqListNode*)tList->node[position];
    
    return ret;
}

// Delete node at postion
void SeqList_delete(SeqList* list, int position) {
    
    TSeqList* tList = list;
    
    if (tList == NULL || position >= tList->length || position < 0) {
        return;
    }
    
    for (int i=position; i < tList->length; i++) {
        tList->node[i] = tList->node[i+1];
    }
    
    tList->length --;
}

int SeqList_getlenght(SeqList* list) {
    
    TSeqList* tList = list;
    
    if (tList == NULL) {
        return 0;
    }
    
    return tList->length;
}
