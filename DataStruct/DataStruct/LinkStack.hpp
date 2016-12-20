//
//  LinkStack.hpp
//  DataStruct
//
//  Created by cjfire on 2016/12/20.
//  Copyright © 2016年 cjfire. All rights reserved.
//

#ifndef LinkStack_hpp
#define LinkStack_hpp

using namespace std;

#ifdef __cplusplus

template <typename T>
struct LinkNode {
    T data;
    LinkNode *next;
};

template <typename T>
class LinkStack {
    
private:
    int m_length;
    LinkNode<T>* m_bottom;
    LinkNode<T>* m_top;
public:
    LinkStack();
    ~LinkStack();
    // 判空
    bool isEmpty();
    // 清空
    void clear();
    // 长度
    int length();
    // 入栈
    void push(T node);
    // 出栈
    T pop();
    // 遍历
    void traverse();
};

template <typename T>
LinkStack<T>::LinkStack() {
    
    m_length = 0;
    m_bottom = new LinkNode<T>();
    m_top = m_bottom;
}

template <typename T>
LinkStack<T>::~LinkStack() {
    
    clear();
    delete m_bottom;
}

template <typename T>
bool LinkStack<T>::isEmpty() {
    return m_length == 0;
}

template <typename T>
void LinkStack<T>::clear() {
    
    if (m_length != 0) {
        
        m_length = 0;
        
        LinkNode<T> *p, *q;
        p = m_bottom->next;
        
        cout << "top is " << m_top << endl;
        
        while (p->next) {
            q = p->next;
            delete p;
            p = q;
        }
        
        delete m_top;
        
        m_top = m_bottom;
    }
}

template <typename T>
int LinkStack<T>::length() {
    return m_length;
}

template <typename T>
void LinkStack<T>::push(T node) {
    LinkNode<T>* tmpNode = new LinkNode<T>();
    tmpNode->data = node;
    m_top->next = tmpNode;
    m_top = tmpNode;
    
    cout << "insert address is " << tmpNode << endl;
    
    m_length += 1;
}

template <typename T>
T LinkStack<T>::pop() {
    
    if (isEmpty()) {
        throw "is empty";
    }
    
    T data = m_top->data;
    LinkNode<T>* nodeBeforeTop = m_bottom;
    
    while (nodeBeforeTop->next != m_top) {
        nodeBeforeTop = nodeBeforeTop->next;
    }
    
    cout << "will pop address is " << m_top << endl;
    
    delete nodeBeforeTop->next;
    m_length -= 1;
    
    m_top = nodeBeforeTop;
    nodeBeforeTop->next = nullptr;
    
    return data;
}

template <typename T>
void LinkStack<T>::traverse() {
    
    LinkNode<T>* tmpNode = m_bottom->next;
    
    while (tmpNode) {
        cout << tmpNode->data << endl;
        tmpNode = tmpNode->next;
    }
}

#endif

#endif /* LinkStack_hpp */
