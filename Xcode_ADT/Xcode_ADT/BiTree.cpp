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
    BiTree(){
        _LevelStopFlag = 0;
        root = Creat();
    }
    
    ~BiTree(){Release(root);}
    void PreOrder(){preOrder(root);}
    void InOrder(){inOrder(root);}
    void PostOrder(){postOrder(root);}
    
    void tt();
    
    void LeverOrder();
    
    void NoRchildNode() {
        noRchildNode(root);
    }
    
    void PrintLevelNode(int n);
    
    void SearchParents(DataType x) {
        
        searchParents(root, x);
        
        if (_ParentsFlag == 0) {
            cout << "None" << endl;
        }

        
        
    }
    
    void InversePostOrder(){
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
    void inOrder(BiNode<DataType> *bt);
    void postOrder(BiNode<DataType> *bt);
    int biNodeCount(BiNode<DataType> *bt);
    int biTreeDepth(BiNode<DataType> *bt);
    void printN0(BiNode<DataType> *bt);
    void searchParents(BiNode<DataType> *bt, DataType x);
    void noRchildNode(BiNode<DataType> *bt);
    
    
    int _BiTreeDepth;
    int _NodeCount;
    int _ParentsFlag;
    LinkStack<DataType> S1;
    int _LevelStopFlag;
    
    BiNode<DataType>* LevelFirstNode[100];
    void getXLevelFirstUnNULLNode(BiNode<DataType> *bt);
};

template <class DataType>
void BiTree<DataType>::PrintLevelNode(int n) {
    _BiTreeDepth = biTreeDepth(root);
    if (n > _BiTreeDepth) {
        cout << "NULL";
        return;
    }
    getXLevelFirstUnNULLNode(root);
    
    LinkQueue<BiNode<DataType> *> Q;
    BiNode<DataType> *temp;
    
    if (root == NULL) {
        return;
    }
    Q.EnQueue(root);
    
    while (Q.QueueEmpty()) {
        temp = Q.DeQueue();
        if (temp == LevelFirstNode[n - 1]) {
            cout << temp->data << " ";
            Q.PrintQueue();
            return;
        }
        

        if (temp->lchild != NULL) {
            Q.EnQueue(temp->lchild);
        }
        if (temp->rchild != NULL) {
            Q.EnQueue(temp->rchild);
        }
    }
    
    
}


// No Recursion Pre_Order Traversal
template <class DataType>
void BiTree<DataType>::preOrder(BiNode<DataType> *bt) {
    LinkStack<BiNode<DataType>*> S;
    while (bt != NULL || S.StackEmpty()) {
        while (bt != NULL) {
        cout << bt->data << " ";
        S.Pusth(bt);
        bt = bt->lchild;
        }
    
        if (S.StackEmpty()) {
            bt = S.Pop();
            
            bt = bt->rchild;
        }
    }
}

// Post Order + Stack
template <class DataType>
void BiTree<DataType>::postOrder(BiNode<DataType> *bt) {
    
    if (bt == NULL) {
        return;
    } else {
        postOrder(bt->lchild);
        postOrder(bt->rchild);
        cout << bt->data << " ";

        S1.Pusth(bt->data);
    }
}


template <class DataType>
void BiTree<DataType>::inOrder(BiNode<DataType> *bt) {
    
    if (bt == NULL) {
        return;
    } else {
        inOrder(bt->lchild);
        
        cout << bt->data << " ";
        
        inOrder(bt->rchild);

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
                _ParentsFlag = 1;
            }
        }

        if (bt->rchild != NULL) {
            if (bt->rchild->data == x) {
                cout << bt->data << " ";
                _ParentsFlag = 1;
            }
        }
        searchParents(bt->lchild, x);
        
        searchParents(bt->rchild, x);
    }
}

template <class DataType>
void BiTree<DataType>::noRchildNode(BiNode<DataType> *bt) {

    if (bt == NULL) {
        return;
    } else {
        if (bt->lchild != NULL) {
            if (bt->lchild != NULL && bt->rchild == NULL) {
                cout << bt->data << " ";
            }
        }
        noRchildNode(bt->lchild);
        
        noRchildNode(bt->rchild);
    }

}



template <class DataType>
void BiTree<DataType>::getXLevelFirstUnNULLNode(BiNode<DataType> *bt) {

    if (bt == NULL || _LevelStopFlag == _BiTreeDepth) {
        return;
    } else {
        LevelFirstNode[_LevelStopFlag ++] = bt;
        
        getXLevelFirstUnNULLNode(bt->lchild);
        getXLevelFirstUnNULLNode(bt->rchild);
        
        
    }

}



