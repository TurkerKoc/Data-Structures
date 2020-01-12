//
//  main.cpp
//  Sparse Array
//
//  Created by Turker Koc on 24.10.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
using std::vector;

vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
    int lengthOfQuerie = queries.size();
    int lengthOfString = strings.size();
    
    vector<int> result(lengthOfQuerie);
    
    for(int i=0;i<lengthOfQuerie;i++)
    {
        int count;
        count = 0;
        for(int j=0;j<lengthOfString;j++)
        {
            if(queries[i]==strings[j])
            {
                count++;
            }
        }
        result[i]=count;
    }
    return result;
    
}

int main()
{
    int strings_count;
    cin >> strings_count;
    
    vector<string> strings(strings_count);
    
    for (int i = 0; i < strings_count; i++)
    {
        string strings_item;
        cin>>strings_item;
        
        strings[i] = strings_item;
    }
    
    int queries_count;
    cin >> queries_count;
    
    vector<string> queries(queries_count);
    
    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        cin>>queries_item;
        
        queries[i] = queries_item;
    }
    vector<int> res = matchingStrings(strings, queries);
    
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }

    return 0;
}

//#include <bits/stdc++.h>
//#include<vector>
//using std::vector;
//using namespace std;
//
//// Complete the matchingStrings function below.
//vector<int> matchingStrings(vector<string> strings, vector<string> queries)
//{
//    int lengthOfQuerie = queries.size;
//    int lengthOfString = strings.size();
//
//    vector<int> result(lengthOfQuerie);
//
//    for(int i=0;i<lengthOfQuerie;i++)
//    {
//        vector<int> count=0;
//        for(int j=0;j<lengthOfString;j++)
//        {
//            if(queries[i]==strings[j])
//            {
//                count++;
//            }
//        }
//        result[i]=count;
//    }
//    return result;
//
//
//
//}
//
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    int strings_count;
//    cin >> strings_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    vector<string> strings(strings_count);
//
//    for (int i = 0; i < strings_count; i++) {
//        string strings_item;
//        getline(cin, strings_item);
//
//        strings[i] = strings_item;
//    }
//
//    int queries_count;
//    cin >> queries_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    vector<string> queries(queries_count);
//
//    for (int i = 0; i < queries_count; i++) {
//        string queries_item;
//        getline(cin, queries_item);
//
//        queries[i] = queries_item;
//    }
//
//    vector<int> res = matchingStrings(strings, queries);
//
//    for (int i = 0; i < res.size(); i++) {
//        fout << res[i];
//
//        if (i != res.size() - 1) {
//            fout << "\n";
//        }
//    }
//
//    fout << "\n";
//
//    fout.close();
//
//    return 0;
//}
//

