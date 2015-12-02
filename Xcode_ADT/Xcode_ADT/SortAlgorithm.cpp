//
//  SortAlgorithm.cpp
//  
//
//  Created by wud.li on 15/11/28.
//
//

#include "SortAlgorithm.h"

template <class DataType>
class SortAlgorithm {
public:
    void InsertSort (DataType a[], int);
    
    void ShellSort (DataType, int);
};

template <class DataType>
void SortAlgorithm<DataType>::InsertSort(DataType a[], int n) {
    int j = 0;
    for (int i = 1; i < n; i ++) {
        a[0] = a[i];
        j = i - 1;
        while (a[j] > a[0] && j > 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = a[0];
    }
    
    for (int i = 1; i < n; i ++) {
        cout << a[i] <<endl;
    }
}

