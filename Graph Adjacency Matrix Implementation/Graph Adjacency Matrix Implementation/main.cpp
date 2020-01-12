//
//  main.cpp
//  Graph Adjacency Matrix Implementation
//
//  Created by Turker Koc on 7.01.2019.
//  Copyright © 2019 Turker Koc. All rights reserved.
//

#include <iostream>
#include<queue>
#include<stack>
using namespace std;
class graph
{
public:
    graph(int n)
    {
        VerticeNum = n;
        
        isVisitedArr = new int[VerticeNum];
        ResetIsVisitedArr(); //set all nodes to 0
        
        arr = new int*[VerticeNum];    //Initilize arr[][] size=Verticenum
        for(int i = 0; i < VerticeNum; ++i)
            arr[i] = new int[VerticeNum];
        
        
        for (int i=0; i<VerticeNum; i++)            //assiginin 0 for nonedged vertices
        {
            for (int j=0; j<VerticeNum; j++)
            {
                arr[i][j]=0;
            }
        }
        
        
    }
    void ResetIsVisitedArr(); //set all nodes 0
    void addNewEdge(int first,int second); //adding edge between 1 and 2 (undirected)
    void printGraph();
    void DeleteEdge(int first, int second);
    void BFT(int start);
    void DFT(int start);
    void isCyclic(); //Is there any cycle in graph
private:
    int VerticeNum;
    int **arr;
    int *isVisitedArr;
    
};
void graph::isCyclic()
{
    stack<int> VisitedS;
    ResetIsVisitedArr();
    stack<int> s;
    s.push(0);
    isVisitedArr[0]=1;
    while(!s.empty())
    {
        int cur=s.top();
        s.pop();
        for(int i=0;i<VerticeNum;i++)
        {
            if(arr[cur][i]==1&&isVisitedArr[i]==0)
                s.push(i);
        }
        isVisitedArr[cur]=1;
        VisitedS.push(cur);
    }
    
    int size=VisitedS.size();
    int CylcleArr[size];
    int i=0;
    while(!VisitedS.empty())
    {
        CylcleArr[i]=VisitedS.top();
        VisitedS.pop();
        i++;
    }
    for(int i=0;i<size;i++)
    {
        int count=0;
        for(int j=0;j<size;j++)
        {
            if(CylcleArr[j]==CylcleArr[i])
                count++;
        }
        if(count>=2)
        {
            cout<<"There is a cylce in graph."<<endl;
            return;
        }
    }
    cout<<"No cycle"<<endl;

}
void graph::ResetIsVisitedArr()
{
    for(int i=0;i<VerticeNum;i++)
        isVisitedArr[i]=0;
}
void graph::DFT(int start)
{
    ResetIsVisitedArr();
    stack<int> s;
    s.push(start);
    isVisitedArr[start]=1;
    cout<<start<<" ";
    while(!s.empty())
    {
        bool check=false; //check is there any unvisited adjacent
        for(int i=0;i<VerticeNum;i++)
        {
            if(arr[s.top()][i]==1&&isVisitedArr[i]==0)
            {
                s.push(i);
                isVisitedArr[i]=1;
                cout<<i<<" ";
                check=true;
            }
        }
        if(!check)
            s.pop();
    }
    cout<<endl;
    
}

void graph::BFT(int start)
{
    ResetIsVisitedArr();
    queue<int> q;
    q.push(start);
    isVisitedArr[start]=1;
    cout<<start<<" ";
    while(!q.empty())
    {
        for(int i=0;i<VerticeNum;i++)
        {
            if(arr[q.front()][i]==1 && isVisitedArr[i]==0)
            {
                q.push(i);
                isVisitedArr[i]=1;
                cout<<i<<" ";
            }
        }
        q.pop();
    }
    cout<<endl;
}

void graph::addNewEdge(int first, int second)
{
    //1 if there is edge
    //0 if there is no edge
    arr[first][second]=1;
    arr[second][first]=1;
}
void graph::DeleteEdge(int first, int second)
{
    arr[first][second]=arr[second][first]=0;
}
void graph::printGraph()
{
    cout<<"Nodes and their adjacent nodes: "<<endl;
    for(int row=0;row<VerticeNum;row++)
    {
        cout<<row<<": ";
        for(int col=0;col<VerticeNum;col++)
        {
            if(arr[row][col]==1)
            {
                cout<<col<<" ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    graph MyGraph(6);
//    MyGraph.addNewEdge(0, 1);
//    MyGraph.addNewEdge(0, 2);
//    MyGraph.addNewEdge(0, 3);
//    MyGraph.addNewEdge(1, 4);
//    MyGraph.addNewEdge(1, 5);
//    MyGraph.addNewEdge(2, 6);
//    MyGraph.addNewEdge(3, 7);
//    MyGraph.addNewEdge(4, 7);
//    MyGraph.addNewEdge(5, 7);
//    MyGraph.addNewEdge(6, 7);

    MyGraph.addNewEdge(1, 2);
    MyGraph.addNewEdge(1, 3);
    MyGraph.addNewEdge(2, 4);
    MyGraph.addNewEdge(2, 5);
    
    MyGraph.printGraph();

    MyGraph.BFT(0);
    MyGraph.DFT(0);
    cout<<endl;
    MyGraph.isCyclic();
    return 0;
}
