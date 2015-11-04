//
//  SeqList.cpp
//  ADT
//
//  Created by computer on 15/9/21.
//  Copyright © 2015年 wud.li. All rights reserved.
//

#include "SeqList.hpp"


template <class DataType>
class SeqList {
public:
    SeqList(){ lenght = 0; }
    SeqList(DataType a[], int n);
    ~SeqList(){ }
    int Length(){ return lenght;}
    
    DataType Get(int i);
    
    int Location(DataType x);
    
    void Insert(int i, DataType x);
    DataType Delete(int i);
    
    void PrintList();
    
    
    
private:
    DataType data[Maxsize];
    int lenght;
};







template <class DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {
    
    char s[] = "illegal parameter!";
    
    if (n > Maxsize) {
        throw s;
    }
    for (int i = 0; i < n; i ++) {
        data[i] = a[i];
    }
    
    lenght = n;
}

template <class DataType>
DataType SeqList<DataType>::Get(int i)
{
    
    char s [] = "illegal location!";
    if (i < 1 && i > lenght) {
        throw s;
    } else {
        return data[i - i];
    }
    
}

template <class DataType>
int SeqList<DataType>::Location(DataType x)
{
    for (int i = 0; i < lenght; i ++) {
        if (data[i] == x) {
            return i + 1;
        }
    }
    return 0;
    
    
}

template <class DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
    if(lenght >= Maxsize)
        throw "up over!";
    if (i < 1 || i > lenght + 1) {
        throw "down over";
    }
    for (int j = lenght; j >= i ; i --) {
        data[j] = data[j - 1];
    }
    
    
    data[i - 1] = x;
    lenght ++;
}



template <class DataType>
DataType SeqList<DataType>::Delete(int i)
{
    DataType x;
    if (lenght == 0) {
        throw "down over";
    }
    
    if (i < 1 && i > lenght) {
        x = data[i - 1];
    }
    
    for (int j = i;j < lenght; j++) {
        data[j - 1] = data[j];
    }
    
    lenght --;
    
    return x;
    
}

template <class DataType>
void SeqList<DataType>::PrintList()
{
    for (int i = 0; i < lenght; i ++) {
        cout<<data[i]<<endl;
    }
    
}
































