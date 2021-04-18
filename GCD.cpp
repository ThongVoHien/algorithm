//
//  main.cpp
//  GCD
//
//  Created by Mac on 5/25/17.
//  Copyright © 2017 Mac. All rights reserved.
//

#include <iostream>
using namespace std;

int GCD(int x,int y)
{
    if (x <= y) return GCD(y,x);
    if (y == 0) return x;
    return GCD(y,x%y);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int x, y;
    cin >> x >> y;
    cout << GCD(x,y) << endl;
    return 0;
}
