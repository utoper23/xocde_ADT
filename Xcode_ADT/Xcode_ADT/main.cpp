//
//  main.cpp
//  ADT
//
//  Created by computer on 15/10/7.
//  Copyright © 2015年 wud.li. All rights reserved.
//

#include<iostream>
#include "BiTree.cpp"

using namespace std;

int main() {
    
    
    BiTree<char> b;
    
    //b.BiNodeCount();
    //b.BiTreeDepth();
    
    b.SearchParents('A');
    return 0;
}