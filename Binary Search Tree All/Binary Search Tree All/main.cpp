//
//  main.cpp
//  Binary Search Tree All
//
//  Created by Turker Koc on 4.01.2019.
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

class BinarySearchTree
{
public:
    BinarySearchTree()
    {
        root = NULL;
        root2 = NULL;
        BTRoot = NULL;
        
        //root2 (BST)
        Node *newEl1 = new Node(9,NULL,NULL);
        root2 = newEl1;

        Node *newEl2 = new Node(6,NULL,NULL);
        root2->left = newEl2;

        Node *newEl3 = new Node(12,NULL,NULL);
        root2->right = newEl3;
        
        //BTRoot
        Node *El1 = new Node(2,NULL,NULL);
        BTRoot = El1;
        
        Node *El2 = new Node(6,NULL,NULL);
        BTRoot->left = El2;
        
        Node *El3 = new Node(1,NULL,NULL);
        BTRoot->right = El3;
        
        Node *El4 = new Node(8,NULL,NULL);
        BTRoot->left->left = El4;
        
        Node *EL5 = new Node(5,NULL,NULL);
        BTRoot->right->left = EL5;
    }
    void insertHelper(int data);
    void LCA_Helper(int n1,int n2); //finding lowest common ancestor of 2 node
    void PrintHelper();     //printing tree
    void FindHeightHelper();
    void printAncestorHelper(int data); //printing all ancestor of node
    void printNodesAtDistanceHelper(int Distance);
    void checkIsSubtreeHelper();     //check given BST is subtree of our tree or not
    void BFT();     //breath first traversal
    void connectNodesAtSameLevel();
    Node* SearchGivenKeyHelper(int key);  //find and return the node which its data = key
    void DeleteHelper(int data);
    void isBinarySearchTreeHelper();
    void findKthSmallestEl(int k);      //find kth smallest element
    void MergedOutputOfTwoBST();        //sorted output of two BST together
    void SumNodesAtDistanceHelper(int Distance);  //sum of nodes at given level
    void isPairPresent(int Sum);        //are there are a pair which their sum = Sum
    void MergeTwoBST();                 //Merge 2 BST (connect nodes at first BST)
    void BTtoBST();
    void findCeilHelper(int key); //node with smallest data larger than or equal to key value.
private:
    Node* root;
    Node *root2; //for MergeTwoBST Func and MergeOutput
    Node *BTRoot; //Binary tree root for conversion from BT->BST

    void findCeil(Node *root, int key);
    
    void arrayToBST(Node *root, int arr[]);
    void selectionSort(int arr[], int n);
    void BTreeToListInorder(Node *BTroot, int arr[]);
    int NodeCountForBT(Node* root2);
    
    void TreeToNodeList(Node *root2,Node *arr[]); //storing tree node adresses in an array
    Node* MergeInsert(Node *root, Node *root2);
    int NodeCount(Node *root2);
    
    int findNodeCount(Node *root);
    void TreeToList(Node *root, int *arr); //into an int arr storing data's of nodes in an array
    
    int SumNodesAtDistance(Node *root, int Distance);
    
    bool IsSubtreeLesser(Node *root, int value);
    bool IsSubtreeGreater(Node *root, int value);
    bool IsBinarySearchTree(Node* root);
    
    Node* DeleteNode(Node *root,int data);
    Node* SearchGivenKey(Node *root,int key);
    Node* insertNode(Node *root,int data);
    Node* LowestCommonAncestor(Node *root,int n1,int n2);  //finding LCA
    int FindHeight(Node *root);
    void PrintAncestors(Node *root,int data);
    void printNodesAtDistance(Node *root, int Distance);
    bool isSubtree(Node *root1,Node *root2);
    bool areIdentical(Node *root1, Node* root2);
    void printTree(Node *root,int space); //print it with tree shape

    
};
void BinarySearchTree::findCeilHelper(int key)
{
    findCeil(root, key);
}
void BinarySearchTree::findCeil(Node *root, int key)
{
    static bool check = true;
    static Node* prev = NULL;
    static Node* cur = root;
    if(check)
    {
        while(cur->left!=NULL)
            cur=cur->left;
        check = false;
    }
    if(root==NULL)
        return;
    findCeil(root->left, key);
    prev = cur;
    cur = root;
    if(cur->data>=key&&prev->data<key)
        cout<<"Your ceil(smallest data larger or equal to "<<key<<"): "<<cur->data<<endl;
    findCeil(root->right, key);
}


void BinarySearchTree::arrayToBST(Node *root, int *arr)
{
    static int x = 0;
    if(root==NULL)
        return;
    arrayToBST(root->left, arr);
    root->data = arr[x];
    x++;
    arrayToBST(root->right, arr);
}

void BinarySearchTree::selectionSort(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int min=arr[i];
        int minIndex=i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    
}
int BinarySearchTree::NodeCountForBT(Node *BTroot)
{
    static int c = 0;
    if(BTroot==NULL)
        return -1;
    NodeCountForBT(BTroot->left);
    c++;
    NodeCountForBT(BTroot->right);
    return c;
}
void BinarySearchTree::BTreeToListInorder(Node *BTroot, int *arr)
{
    static int i = 0;
    if(BTroot==NULL)
        return;
    BTreeToListInorder(BTroot->left, arr);
    arr[i++]=BTroot->data;
    BTreeToListInorder(BTroot->right, arr);
}
void BinarySearchTree::BTtoBST()
{
    int countNode = NodeCountForBT(BTRoot);
    int arr[countNode];
    BTreeToListInorder(BTRoot, arr);
    selectionSort(arr, countNode);
    arrayToBST(BTRoot, arr);
    int x;
}
int BinarySearchTree::NodeCount(Node *root2)
{
    static int c = 0;
    if(root2==NULL)
        return -1;
    NodeCount(root2->left);
    c++;
    NodeCount(root2->right);
    return c;
}
Node* BinarySearchTree::MergeInsert(Node *root, Node *root2)
{
    if(root==NULL)
    {
        root = root2;
        return root;
    }
    else if(root->data > root2->data)
    {
        root->left = MergeInsert(root->left, root2);
    }
    else
        root->right=MergeInsert(root->right, root2);
    return root;
}
void BinarySearchTree::TreeToNodeList(Node *root2, Node *arr[])
{
    static int i=0;
    if(root2==NULL)
        return;
    TreeToNodeList(root2->left, arr);
    arr[i] = root2;
    i++;
    TreeToNodeList(root2->right, arr);
}
void BinarySearchTree::MergeTwoBST()
{
    int count = NodeCount(root2);
    Node* arr[count];
    for(int i=0;i<count;i++)
        arr[i]=NULL;
    TreeToNodeList(root2, arr);
    for(int i=0;i<count;i++)
        arr[i]->left=arr[i]->right=NULL;
    for(int i=0;i<count;i++)
    {
        root = MergeInsert(root, arr[i]);
    }

    
}
int BinarySearchTree::findNodeCount(Node*root)
{
    static int NodeCount = 0;
    if(root==NULL)
        return -1;
    findNodeCount(root->left);
    NodeCount++;
    findNodeCount(root->right);
    return NodeCount;
}
void BinarySearchTree::TreeToList(Node *root, int *arr)
{
    static int i=0;
    if(root==NULL)
        return;

    TreeToList(root->left, arr);
    arr[i]=root->data;
    i++;
    TreeToList(root->right, arr);
}
void BinarySearchTree::isPairPresent(int Sum)
{
    int NodeCount = findNodeCount(root);
    int arr[NodeCount];
    TreeToList(root, arr); //storing all nodes in an array in sorted form
    int end = NodeCount-1;
    int start = 0;
    while(start<end)
    {
        if(arr[start]+arr[end]==Sum)
        {
            cout<<"Yes sum is exist in your tree: "<<arr[start]<<" + "<<arr[end]<<" = "<<Sum<<endl;
            return;
        }
        else if(arr[start]+arr[end]>Sum)
            end--;
        else
            start++;
    }
    cout<<"There is no pair which their sum is "<<Sum<<endl;
}
void BinarySearchTree::SumNodesAtDistanceHelper(int Distance)
{
    cout<<"Sum of nodes at "<<Distance<<". Level: ";
    int result = SumNodesAtDistance(root, Distance);
    cout<<result<<endl;
    
}
int BinarySearchTree::SumNodesAtDistance(Node *root, int Distance)
{
    static int sum=0;
    if(root==NULL)
        return -1;
    if(Distance==0)
        sum+=root->data;
    else
    {
        SumNodesAtDistance(root->left, Distance-1);
        SumNodesAtDistance(root->right, Distance-1);
    }
    return sum;
}
void BinarySearchTree::MergedOutputOfTwoBST()
{
    cout<<"Merged two BST in inorder traversal: ";
    Node *cur1 = root;
    Node *cur2 = root2;
    stack<Node *> s1;
    stack<Node *> s2;
    while((cur1!=NULL || !s1.empty()) || (cur2!=NULL || !s2.empty()))
    {
        while(cur1!=NULL)
        {
            s1.push(cur1);
            cur1=cur1->left;
        }
        while(cur2!=NULL)
        {
            s2.push(cur2);
            cur2=cur2->left;
        }
        if(cur1==NULL&&s1.empty())
        {
            cur2=s2.top();
            cout<<cur2->data<<" ";
            s2.pop();
            cur1=NULL;
            cur2=cur2->right;
        }
        else if(cur2==NULL&&s2.empty())
        {
            cur1=s1.top();
            cout<<cur1->data<<" ";
            s1.pop();
            cur2=NULL;
            cur1=cur1->right;
        }
        else
        {
            cur1=s1.top();
            cur2=s2.top();
            if(cur1->data<cur2->data)
            {
                cout<<cur1->data<<" ";
                s1.pop();
                cur2=NULL;
                cur1=cur1->right;
            }
            else if(cur1->data>cur2->data)
            {
                cout<<cur2->data<<" ";
                s2.pop();
                cur1=NULL;
                cur2=cur2->right;
            }
            else
            {
                cout<<cur1->data<<" ";
                s1.pop();
                s2.pop();
                cur1=cur1->right;
                cur2=cur2->right;
            }
        }
        
    }
    cout<<endl;
}
void BinarySearchTree::findKthSmallestEl(int k)
{
    cout<<"Smallest element of your BST: ";
    int count = 0;
    stack<Node*> s;
    Node *cur = root;
    while(cur!=NULL||!s.empty())
    {
        while(cur!=NULL)
        {
            s.push(cur);
            cur=cur->left;
        }
        cur = s.top();
        count++;
        if(count==k)
        {
            cout<<cur->data<<" "<<endl;
            return;
        }
        s.pop();
        cur = cur->right;
    }
    
    
}
void BinarySearchTree::isBinarySearchTreeHelper()
{
    if(IsBinarySearchTree(root))
        cout<<"Yes BST"<<endl;
    else
        cout<<"No not BST."<<endl;
    
}
bool BinarySearchTree::IsBinarySearchTree(Node *root)
{
    if(root==NULL) return true;
    if(IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))
        return true;
    else
        return false;
}
bool BinarySearchTree::IsSubtreeLesser(Node *root, int value)
{
    if(root==NULL) return true;
    if(root->data<=value && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}
bool BinarySearchTree::IsSubtreeGreater(Node *root, int value)
{
    if(root==NULL) return true;
    if(root->data>=value && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}
void BinarySearchTree::DeleteHelper(int data)
{
    root = DeleteNode(root, data);
}
Node* BinarySearchTree::DeleteNode(Node *root, int data)
{
    if(root==NULL)
        return root;
    else if(root->data>data) root->left = DeleteNode(root->left, data);
    else if(root->data<data) root->right = DeleteNode(root->right, data);
    
    else //we found the key value
    {
        //No child
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        //1 child
        else if(root->left==NULL)
        {
            Node *temp = root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            Node *temp = root;
            root=root->left;
            delete temp;
        }
        //2 Children
        else
        {
            Node *temp=root->right;
            while(temp->left!=NULL)
                temp=temp->left;
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        }
    }
    return root;


}
Node* BinarySearchTree::SearchGivenKeyHelper(int key)
{
    return SearchGivenKey(root, key);
}
Node* BinarySearchTree::SearchGivenKey(Node *root, int key)
{
    if(root==NULL)
        return NULL;
    if(root->data == key)
        return root;
    if(root->data<key)
          return SearchGivenKey(root->right, key);
    if(root->data>key)
        return SearchGivenKey(root->left, key);
    return root;
    
}
void BinarySearchTree::connectNodesAtSameLevel()
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        cur->nextRight = q.front();
        if(cur->left!=NULL)
        {
            q.push(cur->left);
        }
        if(cur->right!=NULL)
        {
            q.push(cur->right);
        }
    }
        cout<<endl;
}
void BinarySearchTree::BFT()
{
    cout<<"BFT Traversal: ";
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
void BinarySearchTree::checkIsSubtreeHelper()
{
    Node *root2 = NULL;
    Node *newEL = new Node(10,NULL,NULL);
    root2 = newEL;
    
    Node *newEl2 = new Node(8,NULL,NULL);
    root2->left=newEl2;
    
    Node*newEL3 = new Node(13,NULL,NULL);
    root2->right = newEL3;
    
    bool result = isSubtree(root,root2);
    if(result)
        cout<<"Yes it is subtree"<<endl;
    else
        cout<<"No it is not a subtree"<<endl;
    
}
bool BinarySearchTree::isSubtree(Node *root1, Node *root2)
{
    if(root1==NULL)
        return true;
    if(root2==NULL)
        return false;
    
    if(areIdentical(root1, root2))
        return true;
    return isSubtree(root1->left, root2);
    return isSubtree(root1->right, root2);
    
}
bool BinarySearchTree::areIdentical(Node *root1, Node *root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL||root2==NULL)
        return false;
    
    return ((root1->data==root2->data)&&areIdentical(root1->left, root2->left)&&areIdentical(root1->right, root2->right));
}
void BinarySearchTree::printNodesAtDistanceHelper(int data)
{
    cout<<"Nodes at a distance "<<data<<": ";
    printNodesAtDistance(root, data);
    cout<<endl;
}
void BinarySearchTree::printNodesAtDistance(Node *root, int Distance)
{
    if(root==NULL)
        return;
    if(Distance==0)
        cout<<root->data<<" ";
    printNodesAtDistance(root->left, Distance-1);
    printNodesAtDistance(root->right, Distance-1);
}
void BinarySearchTree::printAncestorHelper(int data)
{
    cout<<"Ancestors of "<<data<<": ";
    PrintAncestors(root, data);
    cout<<endl;
}
void BinarySearchTree::PrintAncestors(Node *root, int data)
{
    if(root==NULL)
        return;
    if(root->data<data)
        PrintAncestors(root->right, data);
    if(root->data>data)
        PrintAncestors(root->left, data);
    cout<<root->data<<" ";
    
}
void BinarySearchTree::FindHeightHelper()
{
    int MaxHeight = FindHeight(root);
    cout<<"Max Height of your BST: "<<MaxHeight<<endl;
}
int BinarySearchTree::FindHeight(Node *root)
{
    if(root==NULL)
        return -1;
    int x = FindHeight(root->left);
    int y = FindHeight(root->right);
    if(x>y)
        return x+1;
    else
        return y+1;
}
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
void BinarySearchTree::LCA_Helper(int n1, int n2)
{
    Node *LCA_Node = LowestCommonAncestor(root,n1,n2);
    cout<<"Lowest Common Ancestor of "<<n1<<" and "<<n2<<" is: "<<LCA_Node->data<<endl;
}
Node* BinarySearchTree::LowestCommonAncestor(Node *root,int n1, int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data>n1&&root->data>n2)
        return LowestCommonAncestor(root->left, n1, n2);
    if(root->data<n1&&root->data<n2)
        return LowestCommonAncestor(root->right, n1, n2);
    return root;
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
    myBST.insertHelper(18);
    myBST.insertHelper(88);
    myBST.insertHelper(17);
    myBST.insertHelper(19);
    myBST.insertHelper(16);

    myBST.PrintHelper();
    myBST.LCA_Helper(17, 18);
    myBST.FindHeightHelper();
    myBST.printAncestorHelper(10);
    myBST.printNodesAtDistanceHelper(2);
    myBST.checkIsSubtreeHelper();
    myBST.BFT();
    //myBST.connectNodesAtSameLevel();
    cout<<"Your key: ";
    Node *key = myBST.SearchGivenKeyHelper(10);
    cout<<key->data<<endl;
    myBST.isBinarySearchTreeHelper();
    myBST.findKthSmallestEl(5);
    myBST.SumNodesAtDistanceHelper(2);
//    myBST.MergedOutputOfTwoBST();
    myBST.isPairPresent(32);
    myBST.MergeTwoBST();
    myBST.PrintHelper();
    myBST.BTtoBST();  //conversion done change print function to print!!
    myBST.findCeilHelper(11);
//    myBST.DeleteHelper(20);
//    myBST.PrintHelper();
    return 0;
}
