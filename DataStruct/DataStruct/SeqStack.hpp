//
//  SeqStack.hpp
//  DataStruct
//
//  Created by cjfire on 2016/12/18.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#ifndef SeqStack_hpp
#define SeqStack_hpp

typedef void StackNode;

#include <stdio.h>

#ifdef __cplusplus

class SeqStack {
  
private:
    // 容量
    int m_capacity;
    // 存储空间
    unsigned long *m_nodes;
    // 栈顶
    int m_top;
    
public:
    
    SeqStack(int capacity);
    ~SeqStack();
    // 判空
    bool isEmpty();
    // 判满
    bool isFull();
    // 清空
    void clear();
    // 长度
    int length();
    // 入栈
    void push(StackNode *node);
    // 出栈
    StackNode* pop();
};

#endif

#endif /* SeqStack_hpp */
