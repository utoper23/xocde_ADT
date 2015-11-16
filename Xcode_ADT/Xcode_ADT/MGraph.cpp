//
//  MGraph.cpp
//  
//
//  Created by wud.li on 15/11/16.
//
//

#include "MGraph.h"
#include "SeqQueue.cpp"

template <class DataType>

class MGraph {
public:
    MGraph(DataType a[], int n, int e);
    ~MGraph(){}
    
    void DFSTraverse(int v) {
        initVisited();
        dFSTraverse(v);
    };
    
    void BFSTraverse(int v) {
        initVisited();
        bFSTraverse(v);
    }
    
private:
    DataType vertex[MaxSize];
    int arc[MaxSize][MaxSize];
    int vertexNum, arcNum;
    int vistited[MaxSize];
    
    void dFSTraverse(int v);
    void bFSTraverse(int v);
    void initVisited();
};


template <class DataType>
MGraph<DataType>::MGraph(DataType a[], int n, int e) {
    vertexNum = n;  arcNum = e;
    int x1, x2;
    
    //init vertex info
    for (int i = 0; i < vertexNum; i ++) {
        vertex[i] = a[i];
    }
    
    //let arc[][] init with zero
    for (int i = 0; i < arcNum; i ++) {
        for (int j = 0; j < arcNum; j ++) {
            arc[i][j] = 0;
        }
    }
    
    //user input arc info
    for (int i = 0; i < arcNum; i ++) {
        cin >> x1 >> x2;
        
        arc[x1][x2] = 1;    arc[x2][x1] = 1;
    }
    
}


template <class DataType>
void MGraph<DataType>::initVisited() {
    for (int i = 0;  i < vertexNum; i ++) {
        vistited[i] = 0;
    }
}

template <class DataType>
void MGraph<DataType>::dFSTraverse(int v) {
    cout << vertex[v]; vistited[v] = 1;
    
    for (int i = 0; i < vertexNum; i ++) {
        if (vistited[i] == 0 && arc[v][i] == 1) {
            dFSTraverse(i);
        }
    }
    
}


template <class DataType>
void MGraph<DataType>::bFSTraverse(int v) {
    SeqQueue<int> Q;
    cout << vertex[v]; vistited[v] = 1;
    Q.EnQueue(v);
    
    while (Q.QueueEmpty()) {
        v = Q.DeQueue();
        for (int i = 0; i < vertexNum; i ++) {
            if (arc[v][i] == 1 && vistited[i] == 0) {
                cout << vertex[i]; vistited[i] = 1; Q.EnQueue(i);
            }
        }
    }
    
    
}





