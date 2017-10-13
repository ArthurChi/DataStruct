//
//  Sort.hpp
//  DataStruct
//
//  Created by cjfire on 2017/10/13.
//  Copyright © 2017年 cjfire. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>

class Sort {
public:
    // 冒泡排序
    static void BubbleSort(int *arr, int length);
    // 插入排序
    static void InsertSort(int *arr, int length);
private:
    static void swap(int &a, int &b);
    static void show(int *arr, int length);
};


#endif /* Sort_hpp */
