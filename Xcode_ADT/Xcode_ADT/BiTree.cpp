//
//  BiTree.cpp
//  ADT
//
//  Created by computer on 15/10/28.
//  Copyright © 2015年 wud.li. All rights reserved.
//

#include "BiTree.hpp"
#include "LinkQueue.cpp"
#include "LinkStack.cpp"


template <class DataType>
struct BiNode {
    DataType data;
    BiNode<DataType> *lchild, *rchild;
};


template <class DataType>
class BiTree {
public:
    BiTree(){root = Creat(root);}
    
    ~BiTree(){Release(root);}
    void PreOrder(){PreOrder(root);}
    void InOrder(){InOrder(root);}
    void PostOrder(){PostOrder(root);}
    void LeverOrder();
    void BiNodeCount(){biNodeCount(root);}
    void BiTreeDepth(){biTreeDepth(root);}
    
private:
    BiNode<DataType> *root; //指向根节点的头指针
    BiNode<DataType> *Creat(BiNode<DataType> *bt);
    void Release(BiNode<DataType> *bt);
    void PreOrder(BiNode<DataType> *bt);
    void InOrder(BiNode<DataType> *bt);
    void PostPrder(BiNode<DataType> *bt);
    void biNodeCount(BiNode<DataType> *bt);
    void biTreeDepth(BiNode<DataType> *bt);
    
};

template <class DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType> *bt) {
    LinkStack<BiNode<DataType>*> S;
    while (bt != NULL || S.StackEmpty()) {
        while (bt != NULL) {
        cout << bt->data;
        S.Pusth(bt);
        bt = bt->lchild;
        }
    
        if (S.StackEmpty()) {
            bt = S.Pop();
        
            bt = bt->rchild;
        }
    }
}

template <class DataType>
void BiTree<DataType>::biNodeCount(BiNode<DataType> *bt) {
    LinkStack<BiNode<DataType>*> S;
    int NodeCount = 0;
    while (bt != NULL || S.StackEmpty()) {
        while (bt != NULL) {
            NodeCount ++;
            S.Pusth(bt);
            bt = bt->lchild;
        }
        
        if (S.StackEmpty()) {
            bt = S.Pop();
            if (bt == root) {
                
            }
            bt = bt->rchild;
        }
    }
    if (NodeCount > 0) {
        cout << "Node_COUNT: " << NodeCount <<endl;
    } else {
        cout << "NULL" << endl;
    }
    

}



template <class DataType>
void BiTree<DataType>::LeverOrder() {
    
    LinkQueue<BiNode<DataType> *> Q;
    BiNode<DataType> *temp;
    
    if (root == NULL) {
        return;
    }
    Q.EnQueue(root);
    
    while (Q.QueueEmpty()) {
        temp = Q.DeQueue();
        cout << temp->data << " ";
        
        if (temp->lchild != NULL) {
            Q.EnQueue(temp->lchild);
        }
        if (temp->rchild != NULL) {
            Q.EnQueue(temp->rchild);
        }
    }
    
}




template <class DataType>
BiNode<DataType> *BiTree<DataType>::Creat(BiNode<DataType> *bt) {
    DataType x;
    cin >> x;
    if (x == '#') {
        bt = NULL;
    } else {
        bt = new BiNode<DataType>;
        
        bt->data = x;
        
        bt->lchild = Creat(bt->lchild);
        bt->rchild = Creat(bt->rchild);
    }
    return bt;
}

template <class DataType>
void BiTree<DataType>::Release(BiNode<DataType> *bt) {
    if (bt != NULL) {
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}


template <class DataType>
void BiTree<DataType>::biTreeDepth(BiNode<DataType> *bt) {
    LinkStack<BiNode<DataType>*> S;
    int BiTreeDepth = 0;
    while (bt != NULL || S.StackEmpty()) {
        while (bt != NULL) {
            S.Pusth(bt);
            bt = bt->lchild;
        }
        
        if (S.StackEmpty()) {
            bt = S.Pop();
            if (bt == root) {
                
            }
            bt = bt->rchild;
        }
    }

}


