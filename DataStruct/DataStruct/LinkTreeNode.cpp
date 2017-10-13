//
//  LinkTreeNode.cpp
//  DataStruct
//
//  Created by cjfire on 2017/1/13.
//  Copyright © 2017年 cjfire. All rights reserved.
//

#include "LinkTreeNode.hpp"
#include <iostream>

using namespace std;

LinkTreeNode::LinkTreeNode() {
    index = 0;
    data = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
    parent = nullptr;
}

LinkTreeNode::~LinkTreeNode() {
    index = -1;
}

LinkTreeNode* LinkTreeNode::search(int postion) {
    
    if (this->index == postion) {
        return this;
    }
    
    if (this->leftChild != nullptr) {
        
        if (this->leftChild->index == postion) {
            return this->leftChild;
        } else if (this->leftChild->search(postion)) {
            return this->leftChild->search(postion);
        }
    }
    
    if (this->rightChild != nullptr) {
        
        if (this->rightChild->index == postion) {
            return this->rightChild;
        } else {
            return this->rightChild->search(postion);
        }
    }
    
    return nullptr;
}

void LinkTreeNode::addNode(bool isLeft, int* data) {
    
    LinkTreeNode* tmpNode = new LinkTreeNode;
    tmpNode->data = data;
    tmpNode->parent = this;
    
    if (isLeft) {
        tmpNode->index = this->index * 2 + 1;
        this->leftChild = tmpNode;
    } else {
        tmpNode->index = this->index * 2 + 2;
        this->rightChild = tmpNode;
    }
}

void LinkTreeNode::delNode() {
    
    if (this->leftChild != nullptr) {
        delete this->leftChild;
        this->leftChild = nullptr;
    }
    
    if (this->rightChild != nullptr) {
        delete this->rightChild;
        this->rightChild = nullptr;
    }
}

void LinkTreeNode::preTraverse() {
    
    cout << "index is " <<this->index << " data is " << *this->data << endl;
    
    if (this->leftChild != nullptr) {
        this->leftChild->preTraverse();
    }
    
    if (this->rightChild != nullptr) {
        this->rightChild->preTraverse();
    }
}

void LinkTreeNode::interTraverse() {
    
    if (this->leftChild != nullptr) {
        this->leftChild->interTraverse();
    }
    
    cout << this->index << *this->data << endl;
    
    if (this->rightChild != nullptr) {
        this->rightChild->interTraverse();
    }
}

void LinkTreeNode::proTraverse() {
    if (this->leftChild != nullptr) {
        this->leftChild->proTraverse();
    }
    
    if (this->rightChild != nullptr) {
        this->rightChild->proTraverse();
    }
    
    cout << this->index << *this->data << endl;
}
