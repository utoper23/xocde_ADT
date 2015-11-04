//
//  SeqQueue.cpp
//  ADT
//
//  Created by computer on 15/10/7.
//  Copyright © 2015年 wud.li. All rights reserved.
//

#include "SeqQueue.hpp"

const int MaxSize = 100;
template <class DataType>
class SeqQueue {
public:
    SeqQueue(){lenght = 0;}
    
    int QueueEmpty();
    
    void EnQueue(DataType x);
    
    DataType DeQueue();
    
    DataType GetTop();
    
    void Clear() {lenght = 0;}
    
private:
    int lenght;
    DataType data[MaxSize];
};


template <class DataType>
int SeqQueue<DataType>::QueueEmpty() {
    int result;
    if (lenght == 0) {
        result = 0;
    } else {
        result = 1;
    }
    
    return result;
}

template <class DataType>
void SeqQueue<DataType>::EnQueue(DataType x) {
    if (lenght >= MaxSize) {
        cout << "Queue Full" <<endl;
    } else {
        int tail = lenght;
        data[tail] = x;
        lenght ++;
    }
    
    
}

template <class DataType>
DataType SeqQueue<DataType>::DeQueue() {
    int result = -1;
    int i;
    if (lenght > 0) {
        result = data[0];
        
        for (i = 0; i < lenght - 1; ++ i) {
            data[i] = data[i + 1];
        }
        
        
        lenght --;
    }
    
    return result;
}

template <class DataType>
DataType SeqQueue<DataType>::GetTop() {
    DataType result;
    if (lenght > 0) {
        cout << data[0] << endl;;
        result = data[0];
    }
    
    
    return result;
}
