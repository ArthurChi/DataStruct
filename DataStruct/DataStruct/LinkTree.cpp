//
//  LinkTree.cpp
//  DataStruct
//
//  Created by cjfire on 2017/1/13.
//  Copyright © 2017年 cjfire. All rights reserved.
//

#include "LinkTree.hpp"

LinkTree::LinkTree(int* data) {
    m_root = new LinkTreeNode;
    m_root->data = data;
}

LinkTree::~LinkTree() {
    m_root->delNode();
}

int* LinkTree::search(int position) {
    return m_root->search(position)->data;
}

void LinkTree::delNode(int postion) {
    
    LinkTreeNode* searchNode = m_root->search(postion);
    LinkTreeNode* searchParentNode = searchNode->parent;
    
    searchNode->delNode();
    
    if (searchParentNode->leftChild != nullptr && searchParentNode->leftChild->index == postion) {
        searchParentNode->leftChild = nullptr;
    }
    
    if (searchParentNode->rightChild != nullptr && searchParentNode->rightChild->index == postion) {
        searchParentNode->rightChild = nullptr;
    }
    
    delete searchNode;
}

void LinkTree::addNode(int position, int* data, bool isLeft) {
    
    if (m_root->search(position) != nullptr) {
        m_root->search(position)->addNode(isLeft, data);
    } else {
        throw "bad postion";
    }
}

void LinkTree::preTraverse() {
    m_root->preTraverse();
}

void LinkTree::interTraverse() {
    m_root->interTraverse();
}

void LinkTree::proTraverse() {
    m_root->proTraverse();
}
