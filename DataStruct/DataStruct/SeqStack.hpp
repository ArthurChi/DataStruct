//
//  SeqStack.hpp
//  DataStruct
//
//  Created by cjfire on 2016/12/18.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#ifndef SeqStack_hpp
#define SeqStack_hpp

using namespace std;

#ifdef __cplusplus

template <typename T>
class SeqStack {
  
private:
    // 容量
    int m_capacity;
    // 存储空间
    T *m_nodes;
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
    void push(T node);
    // 出栈
    T pop();
    
    void traverse();
};


template <typename T>
SeqStack<T>::SeqStack(int capacity) {
    m_capacity = capacity;
    m_nodes = new T[capacity];
    m_top = 0;
}

template <typename T>
SeqStack<T>::~SeqStack() {
    delete []m_nodes;
}

template <typename T>
bool SeqStack<T>::isEmpty() {
    return 0 == m_top;
}

template <typename T>
bool SeqStack<T>::isFull() {
    return m_top == m_capacity;
}

template <typename T>
void SeqStack<T>::clear() {
    m_top = 0;
}

template <typename T>
int SeqStack<T>::length() {
    return m_top;
}

template <typename T>
void SeqStack<T>::push(T node) {
    
    if (!isFull()) {
        
        m_nodes[m_top] = node;
        m_top += 1;
    } else {
        throw "is full";
    }
}

template <typename T>
T SeqStack<T>::pop() {
    if (!isEmpty()) {
        return m_nodes[--m_top];
    } else {
        throw "is empty";
    }
}

template <typename T>
void SeqStack<T>::traverse() {
    for (int i = m_top - 1; i >= 0; i--) {
        cout<< m_nodes[i] << endl;
    }
}

#endif

#endif /* SeqStack_hpp */
