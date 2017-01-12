//
//  SeqTree.hpp
//  DataStruct
//
//  Created by cjfire on 2017/1/10.
//  Copyright © 2017年 cjfire. All rights reserved.
//

#ifndef SeqTree_hpp
#define SeqTree_hpp

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

template <typename T>
class SeqTree {
private:
    int m_capacity;
    int m_length;
    T *m_nodes;
    void printNode(int position);
public:
    SeqTree(int capacity, T rootNode);
    ~SeqTree();
    T searchNode(int position);
    void addNode(int nodeIndex ,T node, bool isLeft);
    void deleteNode(int postion);
    void TreeTraverse();
};

template <typename T>
SeqTree<T>::SeqTree(int capacity, T rootNode) {
    m_nodes = new T[capacity];
    memset(m_nodes, 0, sizeof(T)*capacity);
    m_capacity = capacity;
    m_nodes[0] = rootNode;
    m_length = 1;
}

template <typename T>
SeqTree<T>::~SeqTree(){
    delete m_nodes;
    m_nodes = nullptr;
}

template <typename T>
T SeqTree<T>::searchNode(int position) {
    if (position < 0 || position > m_capacity) {
        return 0;
    }
    
    return m_nodes[position];
}

template <typename T>
void SeqTree<T>::addNode(int nodeIndex ,T node, bool isLeft) {
    
    if (nodeIndex < 0 || nodeIndex > m_capacity) {
        throw "wrong nodeIndex";
    }
    
    if (m_nodes[nodeIndex] == nullptr) {
        throw "wrong nodeIndex";
    }
    
    int position = nodeIndex * 2;
    if (isLeft) {
        position += 1;
    } else {
        position += 2;
    }
    
    if (position < 0) {
        throw "wrong position";
    }
    
    if (m_nodes[position] != nullptr) {
        throw "wrong position";
    }
    
    m_length++;
    m_nodes[position] = node;
}

template <typename T>
void SeqTree<T>::deleteNode(int postion) {
    
    if (postion < 0 || postion > m_capacity) {
        throw "wrong postion";
    }
    
    if (m_nodes[postion] == nullptr) {
        throw "wrong postion";
    }
    
    int leftChildPosition = postion * 2 + 1;
    
    if (searchNode(leftChildPosition) != 0) {
        deleteNode(leftChildPosition);
    } else {
//        cout << "没东西" <<endl;
    }
    
    int rightChildPosition = postion * 2 + 2;
    
    if (searchNode(rightChildPosition) != 0) {
        deleteNode(rightChildPosition);
    } else {
//        cout << "没东西" <<endl;
    }
    
    m_length--;
    memset(&m_nodes[postion], 0, sizeof(m_nodes[postion]));
}

template <typename T>
void SeqTree<T>::TreeTraverse() {
    
    int row = 0;
    int col = 0;
    
    for (int i = 0; i < m_capacity; i++) {
        printNode(i);
        col += 1;
        if (col == pow(2, row)) {
            cout << endl;
            row += 1;
            col = 0;
        }
    }
    
    cout << endl;
}

template <typename T>
void SeqTree<T>::printNode(int position) {
    if (m_nodes[position] == nullptr) {
        cout << "0 ";
    } else {
        cout << *m_nodes[position] << " ";
    }
}

#endif /* SeqTree_hpp */
