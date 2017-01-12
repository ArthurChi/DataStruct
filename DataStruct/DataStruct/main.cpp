//
//  main.c
//  DataStruct
//
//  Created by cjfire on 16/10/20.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#include <stdio.h>
#include <iostream>
//#include <stdlib.h>
//#include "LinkList.h"
//#include "SeqList.h"
#include "SeqStack.hpp"
#include "LinkStack.hpp"
#include "SeqQueue.hpp"
#include "SeqTree.hpp"

using namespace std;

//typedef struct Person {
//    char* name;
//    int age;
//} Person;
//
//void SeqListAPI();
//void LinkListAPI();

void SeqStackAPI();
void LinkStackAPI();
void SeqQueueAPI();
void SeqTreeAPI();

int main(int argc, const char * argv[]) {
    
//    SeqListAPI();
//    LinkListAPI();
    
//    SeqStackAPI();
//    LinkStackAPI();
    
//    SeqQueueAPI();
    SeqTreeAPI();
    
    return 0;
}

//void SeqListAPI() {
//
//    Person p1, p2, p3;
//    
//    SeqList* list = NULL;
//    
//    list = SeqList_create(10);
//    
//    Person *pp = (malloc(sizeof(Person)));
//    pp->age = 29;
//    pp->name = "pp";
//    
//    p1.name = "p1";
//    p1.age = 25;
//    p2.name = "p2";
//    p2.age = 37;
//    p3.name = "p3";
//    p3.age = 40;
//
//    SeqList_insert(list, pp, 0);
//    
////    printf("%p\n", pp);
////    printf("%d\n", pp->age);
////    printf("%s\n", pp->name);
//    SeqList_insert(list, &p1, 0);
//    SeqList_insert(list, &p2, 1);
//    SeqList_insert(list, &p3, 2);
//    
//    for (int i = 0; i < SeqList_getlenght(list); i++) {
//        
//        Person* p = SeqList_node(list, i);
//        
//        printf("%d\n", i);
//        printf("%d\n", p->age);
//        printf("%s\n", p->name);
//        //        printf("%d", p1.age);
//        //        printf("%s", p->name);
//    }
//    
//    printf("before del\n");
//    
//    SeqList_delete(list, 0);
//    
//    for (int i = 0; i < SeqList_getlenght(list); i++) {
//        
//        Person* p = SeqList_node(list, i);
//        
//        printf("%d\n", i);
//        printf("%d\n", p->age);
//        printf("%s\n", p->name);
//        //        printf("%d", p1.age);
//        //        printf("%s", p->name);
//    }
//    
//    printf("\n");
//}
//
//void LinkListAPI() {
//    
//    Person p1, p2, p3;
//    LinkList* list = NULL;
//    
//    p1.name = "p1";
//    p1.age = 25;
//    p2.name = "p2";
//    p2.age = 37;
//    p3.name = "p3";
//    p3.age = 40;
//    
////    Person *pp = (malloc(sizeof(Person)));
////    pp->age = 29;
////    pp->name = "pp";
//    
//    list = LinkList_create();
//    
//    LinkList_insert(list, &p1, 0);
//    LinkList_insert(list, &p2, 0);
//    LinkList_insert(list, &p3, 0);
////    LinkList_insert(list, pp, 0);
//    
//    LinkList_delete(list, 1);
//    
//    for (int i = 0; i < LinkList_getlenght(list); i++) {
//        
//        Person* p = LinkList_node(list, i);
//        
//        //        printf("%p\n", p1);
//        printf("%d\n", p->age);
//        printf("%s\n", p->name);
//        //        printf("%d", p1.age);
//        //        printf("%s", p->name);
//    }
//    
//    printf("\n");
//
//}

void each(int* node) {
    cout<<*(int*)(node)<<endl;
}

void SeqStackAPI() {
    
    int a = 10;
    
    SeqStack<int> *s = new SeqStack<int>(10);
    s->push(a);
//    s->traverse(each);
    cout<< "length is " << s->length() << endl;
    int tmpa = s->pop();
    cout<< "node is " << tmpa << endl;
    cout<< "length is " << s->length() << endl;
    delete s;
}

void LinkStackAPI() {
    
    int a = 10;
    int b = 20;
    int c = 30;
    
    LinkStack<int> *s = new LinkStack<int>();
    s->push(a);
    s->push(b);
    s->push(c);
    s->traverse();
    cout << s->pop() << endl;
    delete s;
}

void SeqQueueAPI() {
    
    int a = 10;
    int b = 20;
    int c = 30;
    
    SeqQueue<int> *q = new SeqQueue<int>(5);
    q->enQueue(a);
    q->enQueue(b);
    q->enQueue(c);
    
    cout<< q->deQueue() << endl;
    cout << q->deQueue() << endl;
    
    q->clearQueue();
    q->enQueue(40);
    
    cout << q->deQueue() << endl;
    
    q->enQueue(50);
    q->enQueue(60);
    
    cout << q->deQueue() << endl;
    cout << q->deQueue() << endl;
}

void SeqTreeAPI() {
    
    int rootNode = 10;
    SeqTree<int*> *pTree = new SeqTree<int*>(10, &rootNode);
    
    int rootLeft = 9;
    pTree->addNode(0, &rootLeft, true);
    
    int rootLeftLeft = 8;
    
    pTree->addNode(1, &rootLeftLeft, true);
    
    int rootLeftLeftLeft = 7;
    pTree->addNode(3, &rootLeftLeftLeft, true);
    
    int rootLeftLeftLeftLeft = 6;
    pTree->addNode(7, &rootLeftLeftLeftLeft, true);
    
    int rootRight = 5;
    pTree->addNode(0, &rootRight, false);
    
    int rootRightRight = 4;
    pTree->addNode(2, &rootRightRight, false);
    
    pTree->TreeTraverse();
    
    pTree->deleteNode(3);
    cout << endl;
    
    pTree->TreeTraverse();
}
