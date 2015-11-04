//
//  DecimalTrueOctal.cpp
//  ADT
//
//  Created by computer on 15/10/7.
//  Copyright © 2015年 wud.li. All rights reserved.
//

#include "DecimalTrueOctal.hpp"
#include "LinkStack.cpp"


class DecimalTrueOctal {
public:
    DecimalTrueOctal(int x) {
        int flag = 1;
        while (flag >= 1) {
            a.Pusth(x % 8);
            x /= 8;
            flag = x;
        }
        
        a.PrintStack();
    }
    
private:
    LinkStack<int> a;
};
