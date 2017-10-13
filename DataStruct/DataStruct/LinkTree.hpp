//
//  LinkTree.hpp
//  DataStruct
//
//  Created by cjfire on 2017/1/13.
//  Copyright © 2017年 cjfire. All rights reserved.
//

#ifndef LinkTree_hpp
#define LinkTree_hpp

#include <stdio.h>
#include "LinkTreeNode.hpp"

class LinkTree {
private:
    LinkTreeNode *m_root;
public:
    LinkTree(int* data);
    ~LinkTree();
    
    int* search(int position);
    void delNode(int postion);
    void addNode(int postion, int* data, bool isLeft);
    
    void preTraverse();
    void interTraverse();
    void proTraverse();
};

#endif /* LinkTree_hpp */
