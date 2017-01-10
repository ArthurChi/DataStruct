//
//  SeqQueue.hpp
//  DataStruct
//
//  Created by cjfire on 2016/12/24.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#ifndef SeqQueue_hpp
#define SeqQueue_hpp

#include <stdio.h>

template <typename T>
class SeqQueue {

private:
    int m_capacity;
    int m_length;
    T *m_container;
    int m_head, m_tail;
public:
    SeqQueue(int queueCapacity);
    ~SeqQueue();
    
    void clearQueue();
    bool isEmpty();
    bool isFull();
    int length();
    void enQueue(T node);
    T deQueue();
    void queueTraverse();
};

template <typename T>
SeqQueue<T>::SeqQueue(int queueCapacity) {
    m_length = 0;
    m_capacity = queueCapacity;
    m_container = new T[queueCapacity];
    m_head = m_tail = 0;
}

template <typename T>
SeqQueue<T>::~SeqQueue() {
    delete m_container;
    m_container = nullptr;
}

template <typename T>
void SeqQueue<T>::clearQueue() {
    m_head = m_tail = 0;
    m_length = 0;
}

template <typename T>
bool SeqQueue<T>::isEmpty() {
    return m_length == 0;
}

template <typename T>
bool SeqQueue<T>::isFull() {
    return m_length == m_capacity;
}

template <typename T>
int SeqQueue<T>::length() {
    return m_length;
}

template <typename T>
void SeqQueue<T>::enQueue(T node) {
    if (isFull()) {
        throw "is full";
    }
    
    m_container[m_tail++%m_capacity] = node;
    m_length += 1;
}

template <typename T>
T SeqQueue<T>::deQueue() {
    if (isEmpty()) {
        throw "is empty";
    }
    
    m_length -= 1;
    return m_container[(m_capacity-m_head--)%m_capacity];
}

#endif /* SeqQueue_hpp */
