//#include <iostream>
//using namespace std;
//#include <vector>
//using std::vector;
//#include <stack>
//
//vector<string> split_string(string);
//
///*
// * Complete the twoStacks function below.
// */
//int twoStacks(int x, vector<int> a, vector<int> b)
//{
//    stack<int> aStack;
//    for (int i=a.size()-1; i>-1; i--) //push array to the stack
//        aStack.push(a[i]);
//    stack<int> bStack;
//    for (int i=b.size()-1; i>-1; i--) //push array to the stack
//        bStack.push(b[i]);
//    int sum=0;
//    int iteration=0;
//    while(sum<x)
//    {
//        if(sum+aStack.top()<x)
//        {
//            sum+=aStack.top();
//            aStack.pop();
//            iteration++;
//        }
//        else
//        {
//            break;
//        }
//    }
//    while(sum<x)
//    {
//        if(sum+bStack.top()<x)
//        {
//            sum+=bStack.top();
//            bStack.pop();
//            iteration++;
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    return iteration;
//
//
//}
//
//int main()
//{
//
//    int g;
//    cin >> g;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    for (int g_itr = 0; g_itr < g; g_itr++) {
//        string nmx_temp;
//        getline(cin, nmx_temp);
//
//        vector<string> nmx = split_string(nmx_temp);
//
//        int n = stoi(nmx[0]);
//
//        int m = stoi(nmx[1]);
//
//        int x = stoi(nmx[2]);
//
//        string a_temp_temp;
//        getline(cin, a_temp_temp);
//
//        vector<string> a_temp = split_string(a_temp_temp);
//
//        vector<int> a(n);
//
//        for (int a_itr = 0; a_itr < n; a_itr++) {
//            int a_item = stoi(a_temp[a_itr]);
//
//            a[a_itr] = a_item;
//        }
//
//        string b_temp_temp;
//        getline(cin, b_temp_temp);
//
//        vector<string> b_temp = split_string(b_temp_temp);
//
//        vector<int> b(m);
//
//        for (int b_itr = 0; b_itr < m; b_itr++) {
//            int b_item = stoi(b_temp[b_itr]);
//
//            b[b_itr] = b_item;
//        }
//
//        int result = twoStacks(x, a, b);
//
//        cout << result << "\n";
//    }
//
//
//    return 0;
//}
//
//vector<string> split_string(string input_string) {
//    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
//        return x == y and x == ' ';
//    });
//
//    input_string.erase(new_end, input_string.end());
//
//    while (input_string[input_string.length() - 1] == ' ') {
//        input_string.pop_back();
//    }
//
//    vector<string> splits;
//    char delimiter = ' ';
//
//    size_t i = 0;
//    size_t pos = input_string.find(delimiter);
//
//    while (pos != string::npos) {
//        splits.push_back(input_string.substr(i, pos - i));
//
//        i = pos + 1;
//        pos = input_string.find(delimiter, i);
//    }
//
//    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
//
//    return splits;
//}
//
//
#include <iostream>
using namespace std;
#include <vector>
using std::vector;
#include <stack>

using namespace std;

int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        int m;
        int x;
        cin >> n >> m >> x;
        
        vector<int> a(n);
        for(int a_i = 0; a_i <n; a_i++){
            cin >> a[a_i];
        }
        
        vector<int> b(m);
        for(int b_i =0; b_i <m; b_i++){
            cin >> b[b_i];
        }
        
        int sum=0,count=0,temp=0,i=0,j=0;
        
        while(i<n && sum+a[i]<=x){    //considering only first stack and calculating count
            sum+=a[i];
            i++;
        }
        count=i;
        
        while(j<m && i>=0){          //now adding one element of second stack at a time and subtracting the top element of first stack and calculating the count
            sum+=b[j];
            j++;
            while(sum>x && i>0){
                i--;
                sum-=a[i];
            }
            if(sum<=x && i+j>count)
                count=i+j;
        }
        cout<<count<<endl;
    }
    return 0;
}
