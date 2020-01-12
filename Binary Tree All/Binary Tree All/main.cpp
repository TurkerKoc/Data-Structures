//
//  main.cpp
//  Binary Tree All
//
//  Created by Turker Koc on 29.12.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
using std::queue;
using namespace std;
class Node
{
public:
    Node()
    {
        left = right = NULL;
    }
    Node(int d,Node* l, Node* r)
    {
        data = d;
        left = l;
        right = r;
    }
    int data;
    Node *left;
    Node *right;
};

class BinaryTree
{
public:
    BinaryTree()
    {
        root = NULL;
    }
    void insertNode(int data); //inserting node in level order (first available position in level order)
    void deleteNode();  //last node in level order
    void BFT();  //breath first traversal
    void PrintHelper();
    void PreHelp();
    void InHelp();
    void PostHelp();
    void findHeightHelp();
    void findDiameter(); //number of nodes on the longest path between two end nodes.
    
    void BuildTreeFromInPreHelper(int *in, int *pre, int inStart, int inEnd);  //Building Binary from given Preorder and Inorder
    int search(int arr[], int strt, int end, int data);   //funtion to find index in inorder array
    
    void InorderTr_Stack(); //Inorder traversal without recursion, using stack
private:
    Node *root;
    Node *BuildTreeFromInPre(int in[],int pre[],int inStart,int inEnd);
    int findHeight(Node *root); //max height (root ,leaf)
    void PreOrderTraversal(Node *root);
    void InorderTraversal(Node *root);
    void PostOrderTraversal(Node *root);
    void printTree(Node *root,int space); //print it with tree shape

};

void BinaryTree::InorderTr_Stack()
{
    cout<<"Your BT by Inorder Tr. without recursion: ";
    stack<Node *> s;
    Node *cur = root;
    while(cur!=NULL||!s.empty())
    {
        while(cur!=NULL)
        {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        
        cout<<cur->data<<" ";
        
        cur=cur->right;
        
    }
    cout<<endl;
}
int BinaryTree::search(int *arr, int strt, int end, int data)
{
    for(int i=strt;i<=end;i++)
    {
        if(arr[i]==data)
            return i;
    }
    return -1;
}
void BinaryTree::BuildTreeFromInPreHelper(int *in, int *pre, int inStart, int inEnd)
{
    root = BuildTreeFromInPre(in, pre, inStart, inEnd);
}
Node* BinaryTree::BuildTreeFromInPre(int *in, int *pre, int inStart, int inEnd)
{
    static int preIndex = 0;
    
    if(inStart>inEnd)
        return NULL;
    
    Node *newNode = new Node(pre[preIndex],NULL,NULL);
    preIndex++;
    
    if(inStart==inEnd)
        return newNode;
    
    int inIndex = search(in, inStart, inEnd, newNode->data);
    
    newNode->left = BuildTreeFromInPre(in, pre, inStart, inIndex-1);
    newNode->right = BuildTreeFromInPre(in, pre, inIndex+1, inEnd);
    
    return newNode;
}

void BinaryTree::findDiameter()
{
    if(root==NULL)
        return;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    cout<<"Your Longest path between 2 end nodes: "<<leftHeight+rightHeight+2<<endl;
    
}
void BinaryTree::findHeightHelp()
{
    int x = findHeight(root);
    cout<<"Height of your binary tree: "<<x<<endl;
}
int BinaryTree::findHeight(Node *root)
{
    if(root==NULL)
        return -1;
    int x = findHeight(root->left);
    int y = findHeight(root->right);
    if(x>y)
        return x+1;
    else
        return y+1;
    
}
void BinaryTree::PostHelp()
{
    cout<<"Your Binary tree by Postorder traversal: ";
    PostOrderTraversal(root);
    cout<<endl;
}
void BinaryTree::PostOrderTraversal(Node *root)
{
    if(root==NULL)
        return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}
void BinaryTree::InHelp()
{
    cout<<"Your Binary tree by Inorder traversal: ";
    InorderTraversal(root);
    cout<<endl;
}
void BinaryTree::InorderTraversal(Node *root)
{
    if(root==NULL)
        return;
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
    
}
void BinaryTree::PreHelp()
{
    cout<<"Yout Binary tree by Preorder traversal: ";
    PreOrderTraversal(root);
    cout<<endl;
}
void BinaryTree::PreOrderTraversal(Node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
void BinaryTree::PrintHelper()
{
    cout<<"Your binary tree: "<<endl;
    printTree(root, 0);
    cout<<endl;
}
void BinaryTree::printTree(Node *root, int space)
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
void BinaryTree::BFT()
{
    cout<<"Your Binary tree by BFT: ";
    if(root==NULL)
    {
        cout<<"Empty Binary Tree"<<endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *cur = q.front();
        cout<<cur->data<<" ";
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
        q.pop();
    }
    cout<<endl;
}
void BinaryTree::deleteNode()
{
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL) //if root has one element
    {
        Node *temp = root;
        delete temp;
        root = NULL;
        return;
    }
    
    
    queue<Node*> q;
    q.push(root);
    Node*lastEl=NULL;
    while(!q.empty())           //first BFT for finding last element in a tree.
    {
        Node *cur = q.front();
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
        lastEl = q.back();
        q.pop();
    }
    
    
    q.push(root);
    Node *ParentOfLastEl=NULL;
    
    while(!q.empty())               // then BFT for finding parent of last element
    {
        Node *cur = q.front();
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
        if(cur->left->data==lastEl->data||cur->right->data==lastEl->data)
        {
            ParentOfLastEl = cur;
            break;
        }
        q.pop();
    }
    
    if(ParentOfLastEl->right == lastEl)
        ParentOfLastEl->right = NULL;
    else
        ParentOfLastEl->left = NULL;
    delete lastEl;

        
        
}
void BinaryTree::insertNode(int data)
{
    Node *newEl = new Node(data,NULL,NULL);
    if(root==NULL)
    {
        root=newEl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())               //inserting node in lever order form by using BFT
    {
        Node*cur=q.front();
        bool check = false;
        if(cur->left!=NULL)
            q.push(cur->left);
        else
        {
            cur->left = newEl;
            check = true;
            return;
        }
        
        if(cur->right!=NULL)
            q.push(cur->right);
        else if(check==false)
        {
            cur->right = newEl;
            return;
        }
        q.pop();
            
    }
}


int main()
{
    // insert code here...
    BinaryTree myBT;
//    myBT.insertNode(1);
//    myBT.insertNode(2);
//    myBT.insertNode(3);
//    myBT.insertNode(4);
//    myBT.insertNode(5);
//    myBT.insertNode(6);
//    myBT.insertNode(7);
//    myBT.insertNode(8);
//    myBT.insertNode(9);
//    myBT.insertNode(10);
//    myBT.insertNode(11);
//    myBT.insertNode(12);
//    myBT.insertNode(13);
//    myBT.insertNode(14);
//    myBT.insertNode(15);
////    myBT.insertNode(16);
//    myBT.PrintHelper();
//    myBT.BFT();
//    myBT.PreHelp();
//    myBT.InHelp();
//    myBT.PostHelp();
//    myBT.findHeightHelp();
//    myBT.findDiameter();
//    myBT.BFT();
    
    int in[] = {4,2,8,5,9,1,6,3,7};
    int pre[] = {1,2,4,5,8,9,3,6,7};
    myBT.BuildTreeFromInPreHelper(in, pre, 0, 8);
    myBT.PrintHelper();
    
    myBT.InHelp();
    myBT.InorderTr_Stack();
    myBT.BFT();
    return 0;
    
}
