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
    BiTree(){root = Creat();}
    
    ~BiTree(){Release(root);}
    void PreOrder(){preOrder(root);}
    void InOrder(){inOrder(root);}
    void LeverOrder();
    void SearchParents(DataType x) {
        searchParents(root, x);
    }
    
    void PostOrder(){
        if (biNodeCount(root) == 0) {
            cout << "NULL";
        } else {
            postOrder(root);
            while (S1.StackEmpty()) {
                cout << S1.Pop() << " ";
            }
        }
    }
    
    void BiNodeCount(){
        _NodeCount =  biNodeCount(root);
        if (_NodeCount > 0) {
            cout << "Node_COUNT: " << _NodeCount <<endl;
        } else {
            cout << "NULL" << endl;
        }

    }
    
    void BiTreeDepth(){
        if (biNodeCount(root) == 0) {
            cout << "NULL";
        } else {
            _BiTreeDepth = biTreeDepth(root);
            cout << "BiTreeDepth:" << _BiTreeDepth << endl;
        }
        
        
    }
    
    void PrintN0(){
        if (biNodeCount(root) == 0) {
            cout << "NULL";
        } else {
            printN0(root);
        }
    }
    
private:
    BiNode<DataType> *root; //指向根节点的头指针
    BiNode<DataType> *Creat();
    void Release(BiNode<DataType> *bt);
    void preOrder(BiNode<DataType> *bt);
    void onOrder(BiNode<DataType> *bt);
    void postOrder(BiNode<DataType> *bt);
    int biNodeCount(BiNode<DataType> *bt);
    int biTreeDepth(BiNode<DataType> *bt);
    void printN0(BiNode<DataType> *bt);
    void searchParents(BiNode<DataType> *bt, DataType x);
    
    int _BiTreeDepth;
    int _NodeCount;
    int _ParentsFlag;
    LinkStack<DataType> S1;
    
};


// No Recursion Pre_Order Traversal
template <class DataType>
void BiTree<DataType>::preOrder(BiNode<DataType> *bt) {
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
void BiTree<DataType>::postOrder(BiNode<DataType> *bt) {
    
    if (bt == NULL) {
        return;
    } else {
        postOrder(bt->lchild);
        postOrder(bt->rchild);
        S1.Pusth(bt->data);
    }
}


template <class DataType>
int BiTree<DataType>::biNodeCount(BiNode<DataType> *bt) {
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
    return NodeCount;
    

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
BiNode<DataType> *BiTree<DataType>::Creat() {
    DataType x;
    BiNode<DataType> *bt;
    cin >> x;
    if (x == '#') {
        bt = NULL;
    } else {
        bt = new BiNode<DataType>;
        
        bt->data = x;
        
        bt->lchild = Creat();
        bt->rchild = Creat();
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
int BiTree<DataType>::biTreeDepth(BiNode<DataType> *bt) {
    int i = 0, j = 0;
    if (bt == NULL) {
        return 0;
    }
    
    if (bt->lchild != NULL) {
        i = biTreeDepth(bt->lchild);
    }
        
    if (bt->rchild != NULL) {
        j = biTreeDepth(bt->rchild);
    }
        
    return i > j ? i + 1 : j + 1;
}

template <class DataType>
void BiTree<DataType>::printN0(BiNode<DataType> *bt) {
    if (bt == NULL) {
        return;
    } else {
        if (bt->lchild == NULL && bt->rchild == NULL) {
            cout << bt->data << " ";
        }
        printN0(bt->lchild);
        
        printN0(bt->rchild);
        
    }
}


template <class DataType>
void BiTree<DataType>::searchParents(BiNode<DataType> *bt, DataType x) {
    if (bt == NULL) {
        return;
    } else {
        if (bt->lchild != NULL) {
            if (bt->lchild->data == x) {
                cout << bt->data << " ";
            }
        }

        searchParents(bt->lchild, x);
        
        searchParents(bt->rchild, x);
        
    }


}
