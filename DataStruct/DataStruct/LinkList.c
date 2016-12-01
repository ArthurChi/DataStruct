//
//  LinkList.c
//  DataStruct
//
//  Created by cjfire on 2016/11/28.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

typedef unsigned long Data;

typedef struct _link_node {
    
    Data* data;
    struct _link_node* next;
    
} Node;

typedef Node* _LinkList;

// Create
LinkList* LinkList_create() {
    
    Node* head = (malloc(sizeof(Node)));
    head->data = NULL;
    
    if (head == NULL) {
        return NULL;
    }
    
    memset(head, 0, sizeof(Node));
    
    return head;
}

// Destory
void LinkList_destory(LinkList* list) {
    
    Node *p = list, *q = p->next;
    
    while (p != NULL) {
        free(p);
        p = q;
        q = p->next;
    }
}

// Clear
void LinkList_clear(LinkList* list) {
    
    Node* head = list, *p = head->next, *q = p->next;
    
    while (p != NULL) {
        free(p);
        p = q;
        q = p->next;
    }
}

// Insert a node in a position
void LinkList_insert(LinkList* list, LinkListNode* node, int position) {
    
    Node *p = list;
    
    if (p == NULL || node == NULL) {
        return;
    }
    
    int index;
    
    for (index = 0; index < position; index ++) {
        if (p == NULL) {
            return;
        }
        
        p = p->next;
    }
    
    Node* insertNode = (malloc(sizeof(Node)));
    
    if (insertNode == NULL) {
        return;
    }
    
    memset(insertNode, 0, sizeof(Node));
    insertNode->data = node;
    insertNode->next = p->next;
    p->next = insertNode;
}

// Get node at postion
LinkListNode* LinkList_node(LinkList* list, int position) {
    
    Node *p = list;
    
    if (p == NULL) {
        return NULL;
    }
    
    int index;
    
    for (index = 0; index < position; index ++) {
        p = p->next;
        
        if (p == NULL) {
            return NULL;
        }
    }
    
    return p->next->data;
}

// Delete node at postion
void LinkList_delete(LinkList* list, int position) {
    
    Node *p = list, *q;
    
    if (p == NULL) {
        return;
    }
    
    int index;
    for (index = 0; index < position; index ++) {
        if (p == NULL) {
            return;
        }
        
        p = p->next;
    }
    
    q = p->next;
    
    p->next = q->next;
    q->next = NULL;
    free(q);
}

int LinkList_getlenght(LinkList* list) {
    
    Node *p = list;
    int length = 0;
    
    while (p->next != NULL) {
        p = p->next;
        length+=1;
    }
    
    return length;
}
