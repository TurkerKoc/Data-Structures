//
//  main.cpp
//  Build Minimum Height BST
//
//  Created by Turker Koc on 8.01.2019.
//  Copyright © 2019 Turker Koc. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
class Node
{
public:
    Node()
    {
        right=left=nextRight=NULL;
    }
    Node(int el,Node *l, Node *r)
    {
        data = el;
        left = l;
        right = r;
    }
    int data;
    Node *right;
    Node *left;
    Node *nextRight;
};
class BST
{
public:
    BST()
    {
        treePtr=NULL;
    }
    void readTreeHelper();
    void PrintHelper();

private:
    void printTree(Node *root, int space);
    Node* readTree(Node *treePtr,int *arr, int n);
    Node *treePtr;
    int arr[8]={10,20,25,30,40,50,60,70};
};
void BST::readTreeHelper()
{
    treePtr=readTree(treePtr, arr, 8);
}
Node* BST::readTree(Node *treePtr, int *arr, int n)
{
    static int count=0;
    if(n>0)
    {
        Node *newNode = new Node(-1,NULL,NULL);
        treePtr = newNode;
        treePtr->left=readTree(treePtr->left, arr, n/2);
        treePtr->data=arr[count++];
        treePtr->right=readTree(treePtr->right, arr, (n-1)/2);
    }
    return treePtr;

}


void BST::PrintHelper()
{
    cout<<"Your binary tree: "<<endl;
    printTree(treePtr, 0);
    cout<<endl;
}
void BST::printTree(Node *root, int space)
{
    if(root==NULL)
        return;
    space+=10;
    printTree(root->right, space);
    
    cout<<endl;
    for(int i=10;i<space;i++)
        cout<<" ";
    cout<<root->data;
    
    printTree(root->left, space);
}
int main()
{
    BST MyBST;
    MyBST.readTreeHelper();
    MyBST.PrintHelper();
    return 0;
}
