//
//  main.c
//  DataStruct
//
//  Created by cjfire on 16/10/20.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#include <stdio.h>
#include "SeqList.h"

typedef struct Person {
    char* name;
    int age;
} Person;

int main(int argc, const char * argv[]) {
    
    Person p1, p2, p3;
    SeqList* list = NULL;
    
    p1.name = "p1";
    p1.age = 25;
    p2.name = "p2";
    p2.age = 37;
    p3.name = "p3";
    p3.age = 40;
    
    list = SeqList_create(10);
    
    SeqList_insert(list, &p1, 0);
    
    
    for (int i = 0; i < SeqList_getlenght(list); i++) {
        
        Person* p = SeqList_node(list, i);
        printf("%d", p->age);
        printf("%s", p->name);
    }
    
    printf("\n");
    
    return 0;
}
