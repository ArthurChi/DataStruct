//
//  SeqStack.cpp
//  DataStruct
//
//  Created by cjfire on 2016/12/18.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#include "SeqStack.hpp"

SeqStack::SeqStack(int capacity) {
 
    m_capacity = capacity;
    m_nodes = new unsigned long[capacity];
    m_top = 0;
}

SeqStack::~SeqStack() {
    
    delete []m_nodes;
}

bool SeqStack::isEmpty() {
    return 0 == m_top;
}

// 判满
bool SeqStack::isFull() {
    return m_top == m_capacity;
}

// 清空
void SeqStack::clear() {
    m_top = 0;
}

// 长度
int SeqStack::length() {
    return m_top;
}

// 入栈
void SeqStack::push(StackNode *node) {
    if (!isFull()) {
        
        m_nodes[m_top] = (unsigned long)node;
        m_top += 1;
    } else {
        throw "is full";
    }
}

// 出栈
StackNode* SeqStack::pop() {
    if (!isEmpty()) {
        return (StackNode*)m_nodes[--m_top];
    } else {
        throw "is empty";
    }
}
