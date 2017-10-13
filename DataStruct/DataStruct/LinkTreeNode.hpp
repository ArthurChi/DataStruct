//
//  LinkTreeNode.hpp
//  DataStruct
//
//  Created by cjfire on 2017/1/13.
//  Copyright © 2017年 cjfire. All rights reserved.
//

#ifndef LinkTreeNode_hpp
#define LinkTreeNode_hpp

#include <stdio.h>

class LinkTreeNode {
public:
    int index;
    int* data;
    LinkTreeNode* leftChild;
    LinkTreeNode* rightChild;
    LinkTreeNode* parent;
    
    LinkTreeNode();
    ~LinkTreeNode();
    LinkTreeNode* search(int postion);
    void addNode(bool isLeft, int* data);
    void delNode();
    
    void preTraverse();
    void interTraverse();
    void proTraverse();
};

#endif /* LinkTreeNode_hpp */
