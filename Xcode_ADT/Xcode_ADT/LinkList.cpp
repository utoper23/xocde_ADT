//
//  LinkList.cpp
//  ADT
//
//  Created by computer on 15/9/21.
//  Copyright © 2015年 wud.li. All rights reserved.
//

#include "LinkList.hpp"

template <class DataType>

struct Node {
    DataType data;
    Node<DataType> * next;
};



template <class DataType>
class LinkList {
    
public:
    LinkList();
    LinkList(DataType a[], int n);
    ~LinkList();
    int Length();
    DataType Get(int i);
    int Location(DataType x);
    void Insert(int i, DataType x);
    DataType Delete(int i);
    void PrintList();
    
    
    
    
private:
//    Node<DataType>;
    Node<DataType> * first;
    Node<DataType> * p;
};


template <class DataType>
void LinkList<DataType>::PrintList()
{
    
    p = first->next;
    
    while (p != NULL) {
        cout<<p->data;
        p = p->next;
    }

}


template <class DataType>
int LinkList<DataType>::Length()
{
    int count;
    p = first->next;
    count = 0;

}
