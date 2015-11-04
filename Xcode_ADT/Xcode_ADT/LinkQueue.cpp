//
//  LinkQueue.cpp
//  ADT
//
//  Created by computer on 15/10/7.
//  Copyright © 2015年 wud.li. All rights reserved.
//

#include "LinkQueue.hpp"
const int MaxSize = 100;

template<class DataType>
struct Node {
    DataType data;
    Node<DataType> * next;
    Node<DataType> * head;
};


template<class DataType>
class LinkQueue {
public:
    LinkQueue(){
        lenght = 0;
        first = new Node<DataType>;
        first->head = NULL;
        first->next = NULL;
        temp = first;
    }
    
    int QueueEmpty();
    
    void EnQueue(DataType x);
    
    DataType DeQueue();
    
    DataType GetTop();
    
    void Clear(){
        while (temp->head != NULL) {
            temp = temp->head;
            delete temp->next;
            lenght = 0;
        }
    }
private:
    int lenght;
    Node<DataType> * first;
    Node<DataType> * temp;
    
};


template<class DataType>
int LinkQueue<DataType>::QueueEmpty() {
    int result;
    if (lenght == 0) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}

template<class DataType>
void LinkQueue<DataType>::EnQueue(DataType x) {
    if (lenght == 0) {
        temp = first;
    }
    
    if (lenght <= MaxSize) {
        Node<DataType> * p = new Node<DataType>;
        p->head = NULL;
        p->next = NULL;
        p->data = x;
        temp->next = p;
        p->head = temp;
        temp = temp->next;
        lenght ++;
    } else {
        cout << "Queue Full" << endl;
    }
    
}




template<class DataType>
DataType LinkQueue<DataType>::DeQueue() {
    DataType result;
    Node<DataType> * p1;
    if (temp->head != NULL && lenght > 1) {
        result = first->next->data;
        p1 = first->next;
        
        first->next = first->next->next;
        first->next->head = first;
        delete p1;
        lenght --;
    } else if (temp->head != NULL && lenght == 1) {
        result = first->next->data;
        delete first->next;
        first->next = NULL;
        lenght --;
    }
    
    return result;
}





template<class DataType>
DataType LinkQueue<DataType>::GetTop() {
    DataType result = -1;
    if (first->next != NULL) {
        cout << first->next->data << endl;
        result = first->next->data;
    } else {
        cout << "None" <<endl;
    }
    
    return result;
}


