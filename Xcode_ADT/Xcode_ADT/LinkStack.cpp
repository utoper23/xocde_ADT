//
//  LinkStack.cpp
//  ADT
//
//  Created by computer on 15/10/7.
//  Copyright © 2015年 wud.li. All rights reserved.
//

#include "LinkStack.hpp"


template <class DataType>

struct SaNode {
    DataType data;
    SaNode<DataType> * next;
    SaNode<DataType> * head;
};





template <class DataType>
class LinkStack {
public:
    LinkStack(){
        lenght = 0;
        first = new SaNode<DataType>;
        first->head = NULL;
        first->next = NULL;
        temp = first;
    }
    
    ~LinkStack(){}
    
    int StackEmpty();
    
    void Pusth(DataType x);
    
    DataType Pop();
    
    DataType GetTop();
    
    void PrintStack();

    void Clear(){
        while (temp->head != NULL) {
            temp = temp->head;
            delete temp->next;
            lenght = 0;
            
        }
    }
    
    
private:
    SaNode<DataType> * first;
    SaNode<DataType> * temp;
    int lenght;
};

template <class DataType>
int LinkStack<DataType>::StackEmpty(){
    int result;
    if (lenght == 0) {
        result = 0;
    } else {
        result = 1;
    }
    
    return result;
}


template <class DataType>
void LinkStack<DataType>::Pusth(DataType x){
    SaNode<DataType> * p = new SaNode<DataType>;
    p->head = NULL;
    p->next = NULL;
    p->data = x;
    temp->next = p;
    p->head = temp;
    temp = temp->next;
    lenght ++;
}

template <class DataType>
DataType LinkStack<DataType>::Pop(){
    DataType result;
    if (temp->head != NULL) {
        result = temp->data;
        temp = temp->head;
        delete temp->next;
        temp->next = NULL;
        
        lenght --;
    }    
    
    
    return result;
}

template <class DataType>
DataType LinkStack<DataType>::GetTop(){
    DataType result = -1;
    if (temp->head != NULL) {
        cout << temp->data << endl;
        result = temp->data;
    } else {
        cout << "None" <<endl;
    }
    
    return result;
}

template <class DataType>
void LinkStack<DataType>::PrintStack() {
    SaNode<DataType> * p1 = temp;
    while (p1->head != NULL) {
        cout << p1->data;
        p1 = p1->head;
    }
    cout << endl;
}

