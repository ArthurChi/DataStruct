//
//  main.c
//  DataStruct
//
//  Created by cjfire on 16/10/20.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "SeqList.h"

typedef struct Person {
    char* name;
    int age;
} Person;

void SeqListAPI();
void LinkListAPI();

int main(int argc, const char * argv[]) {
    
    SeqListAPI();
//    LinkListAPI();
    
    return 0;
}

void SeqListAPI() {

    Person p1, p2, p3;
    
    SeqList* list = NULL;
    
    list = SeqList_create(10);
    
    Person *pp = (malloc(sizeof(Person)));
    pp->age = 29;
    pp->name = "pp";
    
    p1.name = "p1";
    p1.age = 25;
    p2.name = "p2";
    p2.age = 37;
    p3.name = "p3";
    p3.age = 40;

    SeqList_insert(list, pp, 0);
    
//    printf("%p\n", pp);
//    printf("%d\n", pp->age);
//    printf("%s\n", pp->name);
    SeqList_insert(list, &p1, 0);
    SeqList_insert(list, &p2, 1);
    SeqList_insert(list, &p3, 2);
    
    for (int i = 0; i < SeqList_getlenght(list); i++) {
        
        Person* p = SeqList_node(list, i);
        
        printf("%d\n", i);
        printf("%d\n", p->age);
        printf("%s\n", p->name);
        //        printf("%d", p1.age);
        //        printf("%s", p->name);
    }
    
    printf("before del\n");
    
    SeqList_delete(list, 0);
    
    for (int i = 0; i < SeqList_getlenght(list); i++) {
        
        Person* p = SeqList_node(list, i);
        
        printf("%d\n", i);
        printf("%d\n", p->age);
        printf("%s\n", p->name);
        //        printf("%d", p1.age);
        //        printf("%s", p->name);
    }
    
    printf("\n");
}

void LinkListAPI() {
    
    Person p1, p2, p3;
    LinkList* list = NULL;
    
    p1.name = "p1";
    p1.age = 25;
    p2.name = "p2";
    p2.age = 37;
    p3.name = "p3";
    p3.age = 40;
    
//    Person *pp = (malloc(sizeof(Person)));
//    pp->age = 29;
//    pp->name = "pp";
    
    list = LinkList_create();
    
    LinkList_insert(list, &p1, 0);
    LinkList_insert(list, &p2, 0);
    LinkList_insert(list, &p3, 0);
//    LinkList_insert(list, pp, 0);
    
    LinkList_delete(list, 1);
    
    for (int i = 0; i < LinkList_getlenght(list); i++) {
        
        Person* p = LinkList_node(list, i);
        
        //        printf("%p\n", p1);
        printf("%d\n", p->age);
        printf("%s\n", p->name);
        //        printf("%d", p1.age);
        //        printf("%s", p->name);
    }
    
    printf("\n");

}
