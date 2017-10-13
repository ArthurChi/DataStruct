//
//  Sort.cpp
//  DataStruct
//
//  Created by cjfire on 2017/10/13.
//  Copyright © 2017年 cjfire. All rights reserved.
//

#include "Sort.hpp"
#include <iostream>

using namespace std;

void Sort::swap(int &a, int &b) {
    
    a ^= b;
    b ^= a;
    a ^= b;
}

void Sort::show(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}

void Sort::BubbleSort(int *arr, int length) {
    
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    
    show(arr, length);
}

void Sort::InsertSort(int *arr, int length) {
    
    int tmp;
    int i, j;
    
    for (i = 1; i < length; i++) {
        tmp = arr[i];
        
        for (j = i; j > 0 && arr[j - 1] > tmp; j--) {
            arr[j] = arr[j - 1];
        }
        
        arr[j] = tmp;
    }
    
    show(arr, length);
}
