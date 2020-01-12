//
//  main.cpp
//  Graph - Adjacency List Implementation
//
//  Created by Turker Koc on 8.01.2019.
//  Copyright © 2019 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
#include <stack>
#include <queue>
class Node
{
public:
    Node()
    {
        next = NULL;
    }
    Node(int el,Node *n)
    {
        data = el;
        next = n;
    }
    int data;
    Node *next;
    //    bool isVisited = false;
};
class graph
{
public:
    graph(int n)
    {
        VerticeNum = n;
        isVisitedArr = new int[VerticeNum];
        arr = new Node*[VerticeNum];
        ResetIsVisitedArr();
        for(int i=0;i<VerticeNum;i++)
        {
            arr[i]=NULL;
        }
    }
    void ResetIsVisitedArr();
    void addNewEdge(int first, int second);
    void DeleteEdge(int FirstVertice, int SecondVertice);
    void printGraph();
    void BFT(int start);
    void DFT(int start);
    void isCyclic();
    
private:
    int *isVisitedArr;
    Node* *arr;
    int VerticeNum;
    
};

void graph::isCyclic()
{
    ResetIsVisitedArr();
    stack<int> s;
    stack<int> VisitedS;
    s.push(0);
    isVisitedArr[0]=1;
    while(!s.empty())
    {
        int cur = s.top();
        s.pop();
        Node *temp = arr[cur];
        while(temp!=NULL)
        {
            if(isVisitedArr[temp->data]==0)
            {
                s.push(temp->data);
            }
            temp=temp->next;
        }
        isVisitedArr[cur]=1;
        VisitedS.push(cur);
    }
    int size = VisitedS.size();
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
void graph::BFT(int start)
{
    ResetIsVisitedArr();
    cout<<"BFT of graph: ";
    queue<int>q;
    q.push(start);
    isVisitedArr[start]=1;
    while(!q.empty())
    {
        int cur = q.front();
        cout<<q.front()<<" ";
        q.pop();
        Node *temp = arr[cur];
        while(temp!=NULL)
        {
            if(isVisitedArr[temp->data]==0)
            {
                q.push(temp->data);
                isVisitedArr[temp->data]=1;
            }
            temp=temp->next;
        }
    }
    if(start>VerticeNum||start<0)
        return;
    for(int i=0;i<VerticeNum;i++)
    {
        isVisitedArr[i] = 0;
    }
}
void graph::DFT(int start)
{
    ResetIsVisitedArr();
    cout<<"DFT of graph: ";
    stack<int> s;
    s.push(start);
    cout<<s.top()<<" ";
    isVisitedArr[start] = 1;
    while(!s.empty())
    {
        bool check = false;
        Node* temp=arr[s.top()];
        while(temp!=NULL)
        {
            if(isVisitedArr[temp->data]==0)
            {
                cout<<temp->data<<" ";
                s.push(temp->data);
                isVisitedArr[temp->data]=1;
                check = true;
                break;
            }
            temp=temp->next;
        }
        if(!check)
            s.pop();
    }
}
void graph::ResetIsVisitedArr()
{
    for(int i=0;i<VerticeNum;i++)
    {
        isVisitedArr[i]=0;
    }
}

void graph::addNewEdge(int first, int second)
{
    Node* newEdge = new Node(second,NULL);
    if(arr[first]==NULL)
    {
        arr[first]=newEdge;
    }
    else
    {
        Node *temp = arr[first];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newEdge;
    }
    
    
    
    Node* newEdge2 = new Node(first,NULL);
    
    if(arr[second]==NULL)
    {
        arr[second]=newEdge2;
        return;
    }
    Node *temp = arr[second];
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newEdge2;
}
void graph::DeleteEdge(int FirstVertice, int SecondVertice)
{
    if(FirstVertice>VerticeNum-1||FirstVertice<0||SecondVertice>VerticeNum||SecondVertice<0)
    {
        cout<<"unknown vertices!!"<<endl;
        return;
    }
    if(arr[FirstVertice] == NULL){
        cout<<"They are not connected"<<endl;
        return;
    }
    Node*cur = arr[FirstVertice];
    Node *prev = NULL;
    while(cur!=NULL && cur->data!=SecondVertice)
    {
        prev = cur;
        cur = cur->next;
    }
    if(cur==NULL)
    {
        cout<<"They are not connected"<<endl;
        return;
    }
    if(prev == NULL)
        arr[FirstVertice] = cur->next;
    else{
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
        
}
void graph::printGraph()
{
    cout<<"Nodes adjacent to vertices: "<<endl;
    for(int i=0;i<VerticeNum;i++)
    {
        cout<<i<<": ";
        Node *temp = arr[i];
        while(temp!=NULL)
        {
            cout<<"->";
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
        
    }
}
int main()
{
    graph MyGraph(8);
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
    cout<<endl;
    MyGraph.DFT(0);
    cout<<endl;
    MyGraph.isCyclic();
    return 0;
}
