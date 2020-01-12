//
//  main.cpp
//  Threaded Binary Tree
//
//  Created by Turker Koc on 4.01.2019.
//  Copyright © 2019 Turker Koc. All rights reserved.
//



//IDEA OF THREADED BİNARY TREE IS MAKING all right child pointers that would normally be NULL point to the inorder successor of the node (if it exists).



#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    Node()
    {
        right=left=NULL;
        rightThreaded = false;
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
    bool rightThreaded;
};

class BinarySearchTree
{
public:
    BinarySearchTree()
    {
        root = NULL;
    }
    void insertHelper(int data);
    Node* insertNode(Node *root,int data);

    
    Node* findInorderSuccessor(int data);
    void MakeThreaded();
    void MakeUnThreaded();
    Node *findNode(int data);
    
    void PrintHelper();
    void printTree(Node *root,int space); //print it with tree shape
    
    void InorderTraversal();
private:
    Node* root;
};
void BinarySearchTree::PrintHelper()
{
    cout<<"Your binary tree: "<<endl;
    printTree(root, 0);
    cout<<endl;
}
void BinarySearchTree::printTree(Node *root, int space)
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
void BinarySearchTree::InorderTraversal()
{
    MakeThreaded();
    Node *cur = root;
    while(cur->left!=NULL)
        cur=cur->left;
    while(cur != NULL)
    {
        cout<<cur->data<<" ";
        if(cur->rightThreaded)
            cur=cur->right;
        else
        {
            cur = cur->right;
            while(cur->left!=NULL)
                cur=cur->left;
        }
    }
    MakeUnThreaded();
}
void BinarySearchTree::MakeUnThreaded()
{
    queue<Node*> q;             //finding node with BFT
    q.push(root);
    while(!q.empty())
    {
        Node *cur = q.front();
        if(cur->rightThreaded)
        {
            cur->right = NULL;
            cur->rightThreaded = false;
        }
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL&&!cur->rightThreaded)
            q.push(cur->right);
        q.pop();
    }
}
void BinarySearchTree::MakeThreaded()
{
    queue<Node*> q;             //finding node with BFT
    q.push(root);
    while(!q.empty())
    {
        Node *cur = q.front();
        if(cur->right==NULL)
        {
            Node *successor = findInorderSuccessor(cur->data);
            cur->right = successor;
            cur->rightThreaded = true;
        }
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL&&!cur->rightThreaded)
            q.push(cur->right);
        q.pop();
    }
}

Node* BinarySearchTree::findNode(int data)
{
    if(root==NULL)
        return NULL;
    
    queue<Node*> q;             //finding node with BFT
    q.push(root);
    while(!q.empty())
    {
        Node *cur = q.front();
        if(cur->data==data)
            return cur;
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
        q.pop();
    }
    return NULL;
}
Node* BinarySearchTree::findInorderSuccessor(int data)
{
    Node* cur = findNode(data);
    if(cur==NULL) return NULL;
    if(cur->right!=NULL)
    {
        Node *temp=cur->right;
        while(temp->left!=NULL)
            temp=temp->left;
        return temp;
    }

    Node *successor = NULL;
    Node *ancestor = root;
    while(ancestor!=cur)
    {
        if(cur->data<ancestor->data)
        {
            successor=ancestor;
            ancestor=ancestor->left;
        }
        else
            ancestor=ancestor->right;
    }
    return successor;
}
void BinarySearchTree::insertHelper(int data)
{
    root = insertNode(root, data);
}
Node* BinarySearchTree::insertNode(Node *root,int data)
{
    Node *newNode = new Node(data,NULL,NULL);
    if(root==NULL)
    {
        root = newNode;
        return root;
    }
    else if(data<=root->data)
    {
        root->left = insertNode(root->left,data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}


int main()
{
    BinarySearchTree myBST;
    myBST.insertHelper(15);
    myBST.insertHelper(10);
    myBST.insertHelper(20);
    myBST.insertHelper(8);
    myBST.insertHelper(13);
    myBST.insertHelper(6);
    myBST.insertHelper(88);
    myBST.MakeThreaded();
    myBST.InorderTraversal();
    myBST.PrintHelper();
    return 0;
}
