//
//  main.cpp
//  Array Manipulation
//
//  Created by Turker Koc on 24.10.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
#include<vector>
using std::vector;

int main()
{
    string nm_temp;
    cin>>nm_temp;
    
    vector<string> nm = split_string(nm_temp);

    return 0;
}
