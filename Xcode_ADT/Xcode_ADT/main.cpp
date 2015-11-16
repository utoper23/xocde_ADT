//
//  main.cpp
//  ADT
//
//  Created by computer on 15/10/7.
//  Copyright © 2015年 wud.li. All rights reserved.
//

#include<iostream>
#include "MGraph.cpp"

using namespace std;

int main() {
    char a[4] = {'A', 'B', 'C' ,'D'};
    
    
    MGraph<char> mg(a, 4, 4);
    mg.DFSTraverse(0);
    
    
    return 0;
}



//2014083408
//2014083110
//2013250428
//2014081218
//2014081611
//2014083203
//2014083325
//2014083120
//2014083404
//2013250706

