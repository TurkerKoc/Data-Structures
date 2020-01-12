//
//  main.cpp
//  Term Project(Operations with Big Numbers)
//
//  Created by Turker Koc on 20.12.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class DLLNode
{
public:
    DLLNode()
    {
        next = prev = NULL;
    }
    DLLNode(int el, DLLNode* n, DLLNode* p)
    {
        data = el;
        next = n;
        prev = p;
    }
    int data;
    DLLNode *next, *prev;
};

class BigNumber
{
public:
    BigNumber(string filename)
    {
        findingNumberCount(filename);
        if(NumberCount>10)
        {
            cout<<"There should be at most 10 numbers. Enter valid input."<<endl;
        }
        else
        {
            ResultHead = ResultTail = NULL;
            tempResHead = tempResTail = NULL;
            NumbersHead = new DLLNode*[NumberCount]; //initilize an array for head pointers
            NumbersTail = new DLLNode*[NumberCount]; //initilize an array for tail pointers
            for(int i=0;i<NumberCount;i++) //set all heads = NULL
            {
                NumbersHead[i] = NULL;
            }
            for(int i=0;i<NumberCount;i++) //set all tails = NULL
            {
                NumbersTail[i] = NULL;
            }
            for(int i=0;i<10;i++)  //fill with -1 to understand operations
            {
                OperationArr[i] = -1;  //i will put '0' for '+'  and  '1' for '*'
            }
            
            createBigInt(filename);  //assigning numbers into linked lists.

        }
        
        
    }

    void printAll(int Number) const;
    void addToHead(int data, int Number);
    void addToTail(int, int Number);
    int  deleteFromHead(int Number); // delete the head and return its data;
    int  deleteFromTail(int Number); // delete the tail and return its data;

    void createBigInt(string filename);
    void findingNumberCount(string filename); //finding number count for head array
    void UpdateBigInt(string filename);
    void addBigInt(int Num1,int Num2);
    void MultiplyBigInt(int Num1,int Num2);
    int findLength(int Number); //for result list
    void createEmptyList(int size, int Number); //creating max size tempresult with -1's
    void freeBigInt(int Number);
    void copyLists(int Num1,int Num2);
    
private:
    DLLNode **NumbersHead; //putting all heads into an array (different head will be initilized for each number)
    DLLNode **NumbersTail; //doing the same thing for tails. To reach number from the tail.
    int NumberCount; //Number count in file
    int OperationArr[10]; //let 0 = '+'     and     1 = '*'
    DLLNode *ResultHead;   //linked list which result will be stored
    DLLNode *ResultTail;
    DLLNode *tempResHead;  //temporary linked list which operation results will be stored
    DLLNode *tempResTail;
    bool isOperationTrue = true; //to check is input file include valid operations
};


void BigNumber::UpdateBigInt(string filename)
{
    if(isOperationTrue&&NumberCount<=10)
    {
        while(true)             //first we should done with  multiplications
        {
            bool check = false;
            for(int i=0;i<10;i++)
            {
                if(OperationArr[i]==1)
                {
                    MultiplyBigInt(i,i+1);
                    check = true;
                    copyLists(-1, i);   //copying result to tempHead
                    freeBigInt(i+1);    //deleting second Number
                    
                    for(int j=i+1;j<NumberCount;j++) //we should assign result to the first number and shift the numbers in the right in array of head pointers
                    {
                        if(j==NumberCount-1)
                        {
                            freeBigInt(j);
                        }
                        else
                        {
                            copyLists(j+1, j);
                        }
                    }
                    for(int j=i;j<10;j++)       //we should delete the operation we did;
                    {
                        if(j==9)
                            break;
                        else
                            OperationArr[j]=OperationArr[j+1];
                    }
                    break;
                }
            }
            if(check==false)
                break;
        }
        while(true)             //now we can do additions in same way
        {
            bool check = false;
            for(int i=0;i<10;i++)
            {
                if(OperationArr[i]==0)
                {
                    addBigInt(i,i+1);
                    check = true;
                    copyLists(-1, i);
                    freeBigInt(i+1);
                    
                    for(int j=i+1;j<NumberCount;j++) //we should assign result to the first number and shift the numbers in the right
                    {
                        if(j==NumberCount-1)
                        {
                            freeBigInt(j);
                        }
                        else
                        {
                            copyLists(j+1, j);
                        }
                    }
                    for(int j=i;j<10;j++)
                    {
                        if(j==9)
                            break;
                        else
                            OperationArr[j]=OperationArr[j+1];
                    }
                    break;
                }
            }
            
            if(check==false)
                break;
        }
        
        copyLists(0, -2);  //after all operations done the result will be stored in first linked list so we can copy our result into result linked list
        
        //since we are done with other bigIntegers (we copied our result into result List)
        freeBigInt(0);
        freeBigInt(-1);
        
        //print result
        cout<<"Your Result: ";
        printAll(-2);
        
        
        ofstream myFile(filename);   //writing our result to the output file.
        int digit;
        DLLNode *cur = ResultHead;
        while(cur!=NULL)
        {
            digit=cur->data;
            cur=cur->next;
            myFile<<digit;
        }
        
        
    }
    else                //if operations are not valid we shouldnt do any calculation
    {
        ofstream myFile(filename);
        myFile<<"Wrong Operation";
    }
        
    
}
void BigNumber::MultiplyBigInt(int Num1, int Num2)
{
    freeBigInt(-1);             //first we should free temp Linked list because we will store our result in this list
    if(NumbersHead[Num1]->data==0||NumbersHead[Num2]->data==0)
    {
        DLLNode*newEl=new DLLNode(0,NULL,NULL);
        tempResHead = tempResTail = newEl;
        return;
        
    }
    int len1=findLength(Num1);
    int len2=findLength(Num2);
    createEmptyList(len1+len2+1,-1); //creating a list with length max result with all 0's
    
    DLLNode *firstPtr,*resPtr2;
    DLLNode *secPtr=NumbersTail[Num2];
    DLLNode *resPtr=tempResTail;
    
    //secPtr is staying in one digit in second number while firstPtr traversing first number. and doing multiplications
    //then we are doing the same thing with other digits in Second Number
    while(secPtr)
    {
        int carry=0;
        resPtr2 = resPtr;
        firstPtr = NumbersTail[Num1];
        while(firstPtr)
        {
            int mul = firstPtr->data*secPtr->data+carry;
            resPtr2->data += mul%10;
            carry = mul/10+resPtr2->data/10;
            resPtr2->data = resPtr2->data%10;
            firstPtr=firstPtr->prev;
            resPtr2=resPtr2->prev;
        }
        if(carry>0)
        {
            resPtr2->data += carry;
        }
        resPtr=resPtr->prev;
        secPtr=secPtr->prev;
    }
    
    DLLNode* del = tempResHead;
    DLLNode* delNext = tempResHead;
    while(delNext->data==0)
    {
        delNext=delNext->next;
        delete del;
        del = delNext;
    }
    delNext->prev=NULL;
    tempResHead = delNext;
}


void BigNumber::addBigInt(int Num1, int Num2)
{
    if(NumbersHead[Num1]->data==0)
    {
        copyLists(Num2, -1);
        return;
    }
    if(NumbersHead[Num2]->data==0)
    {
        copyLists(Num1, -1);
        return;
    }
    freeBigInt(-1);
    DLLNode *cur1,*cur2,*curResult;
    cur1=NumbersTail[Num1];
    cur2=NumbersTail[Num2];
    curResult=ResultHead;
    int carry=0;
    while(true)
    {
        if(cur1==NULL&&cur2==NULL&&carry!=0)
        {
            addToHead(carry, -1);
        }
        if(cur1==NULL)
        {
            while(cur2!=NULL)
            {
                int sum = cur2->data + carry;
                addToHead(sum%10, -1);        //-1 for adding tempResHead;
                carry = sum/10;
                cur2=cur2->prev;
            }
            break;
        }
        if(cur2==NULL)
        {
            while(cur1!=NULL)
            {
                int sum = cur1->data + carry;
                addToHead(sum%10, -1);          //-1 for adding tempResHead
                carry = sum/10;
                cur1=cur1->prev;
            }
            break;
        }
        
        int sum=cur1->data+cur2->data+carry;
        addToHead(sum%10, -1);                  //-1 for adding tempResHead
        carry=sum/10;
        cur1=cur1->prev;
        cur2=cur2->prev;
    }
    
}


void BigNumber::freeBigInt(int Number)
{
    DLLNode *cur,*next;
    if(Number==-1)     //to free tempResHead
    {
        if(tempResHead == NULL)
            return;
        cur = tempResHead;
        next = cur;
        while(next!=NULL)
        {
            next = next->next;
            delete cur;
            cur=next;
        }
        tempResHead = tempResTail = NULL;
    }
    else if(Number == -2)       //free Result
    {
        if(ResultHead == NULL)
            return;
        cur = ResultHead;
        next = cur;
        while(next!=NULL)
        {
            next = next->next;
            delete cur;
            cur=next;
        }
        ResultHead = ResultTail = NULL;
    }
    else            //to free Numbers
    {
        if(NumbersHead[Number]==NULL)
            return;
        cur = NumbersHead[Number];
        next = cur;
        while(next!=NULL)
        {
            next = next->next;
            delete cur;
            cur=next;
        }
        NumbersHead[Number] = NumbersTail[Number] = NULL;
    }
}


void BigNumber::copyLists(int Num1, int Num2)
{
    if(Num1==-1&&Num2==-2)          //copy tempResult to result
    {
        freeBigInt(-2); //free result
        if(tempResHead == NULL)
            return;
        DLLNode *tempcur = tempResHead;
        DLLNode *newEl = new DLLNode(tempcur->data,NULL,NULL);
        ResultHead = ResultTail = newEl;
        DLLNode *ResCur = ResultHead;
        tempcur = tempcur->next;
        while(tempcur!=NULL)
        {
            DLLNode *newEl = new DLLNode(tempcur->data,NULL,ResCur);
            ResCur->next = newEl;
            ResCur = newEl;
            ResultTail = newEl;
            tempcur = tempcur->next;
        }
        
    }
    else if(Num1==-1&&Num2>=0)           //copy temp result to Num
    {
        freeBigInt(Num2); //free result
        if(tempResHead == NULL)
            return;
        DLLNode *tempcur = tempResHead;
        DLLNode *newEl = new DLLNode(tempcur->data,NULL,NULL);
        NumbersHead[Num2] = NumbersTail[Num2] = newEl;
        DLLNode *ResCur = NumbersHead[Num2];
        tempcur = tempcur->next;
        while(tempcur!=NULL)
        {
            DLLNode *newEl = new DLLNode(tempcur->data,NULL,ResCur);
            ResCur->next = newEl;
            ResCur = newEl;
            NumbersTail[Num2] = newEl;
            tempcur = tempcur->next;
        }
    }
    else if(Num1>=0&&Num2==-2)          //copy Number to result
    {
        freeBigInt(-2); //free result
        if(NumbersHead[Num1] == NULL)
            return;
        DLLNode *tempcur = NumbersHead[Num1];
        DLLNode *newEl = new DLLNode(tempcur->data,NULL,NULL);
        ResultHead = ResultTail = newEl;
        DLLNode *ResCur = ResultHead;
        tempcur = tempcur->next;
        while(tempcur!=NULL)
        {
            DLLNode *newEl = new DLLNode(tempcur->data,NULL,ResCur);
            ResCur->next = newEl;
            ResCur = newEl;
            ResultTail = newEl;
            tempcur = tempcur->next;
        }
    }
    else if(Num1>0&&Num2>=0)            //copy number to number
    {
        freeBigInt(Num2); //free result
        if(NumbersHead[Num1] == NULL)
            return;
        DLLNode *tempcur = NumbersHead[Num1];
        DLLNode *newEl = new DLLNode(tempcur->data,NULL,NULL);
        NumbersHead[Num2] = NumbersTail[Num2] = newEl;
        DLLNode *ResCur = NumbersHead[Num2];
        tempcur = tempcur->next;
        while(tempcur!=NULL)
        {
            DLLNode *newEl = new DLLNode(tempcur->data,NULL,ResCur);
            ResCur->next = newEl;
            ResCur = newEl;
            NumbersTail[Num2] = newEl;
            tempcur = tempcur->next;
        }
    }
    else if(Num1>=0&&Num2==-1)          //copy number to tempResult
    {
        freeBigInt(-1); //free result
        if(NumbersHead[Num1] == NULL)
            return;
        DLLNode *tempcur = NumbersHead[Num1];
        DLLNode *newEl = new DLLNode(tempcur->data,NULL,NULL);
        tempResHead = tempResTail = newEl;
        DLLNode *ResCur = tempResHead;
        tempcur = tempcur->next;
        while(tempcur!=NULL)
        {
            DLLNode *newEl = new DLLNode(tempcur->data,NULL,ResCur);
            ResCur->next = newEl;
            ResCur = newEl;
            tempResTail = newEl;
            tempcur = tempcur->next;
        }
    }
}


int BigNumber::findLength(int Number)  //finding length of a linked list
{
    DLLNode *cur = NumbersHead[Number];
    int len=0;
    while(cur)
    {
        len++;
        cur=cur->next;
    }
    return len;
}


void BigNumber::createEmptyList(int size,int Number)
{
    if(Number==-1)     //creating empty list with all 0's in tempRes linked list
    {
        DLLNode *newEl = new DLLNode(0,NULL,NULL);
        tempResHead=tempResTail=newEl;
        DLLNode*cur=tempResHead;
        for(int i=1;i<size;i++)
        {
            DLLNode *newEl = new DLLNode(0,NULL,cur);
            cur->next=newEl;
            cur=tempResTail=newEl;
        }
    }
    else if(Number==-2)     //creating empty list with all -1's in Result Linked List
    {
        DLLNode *newEl = new DLLNode(-1,NULL,NULL);
        ResultHead=ResultTail=newEl;
        DLLNode*cur=ResultHead;
        for(int i=1;i<size;i++)
        {
            DLLNode *newEl = new DLLNode(-1,NULL,cur);
            cur->next=newEl;
            cur=ResultTail=newEl;
        }
    }

}



void BigNumber::findingNumberCount(string filename)    //to find how many number we have in input file
{
    ifstream myFile(filename);
    char digit;
    int tokenNum = 0;
    while(true)  //finding how many operation there are
    {
        myFile>>digit;
        if(digit=='+'||digit=='*') tokenNum++;
        if(myFile.eof())break;
    }
    NumberCount = tokenNum + 1; //because number count is always +1 of operation
    
}

void BigNumber::createBigInt(string filename)
{
    int Num=0;
    char digit;
    ifstream myFile(filename);
    ifstream tempMyFile(filename); //for checking wrong operations on input file.
    tempMyFile>>digit;
    
    //if there is a character or unknown operation at the beginning
    if(digit!='+'&&digit!='*'&&digit!='0'&&digit!='1'&&digit!='2'&&digit!='3'&&digit!='4'&&digit!='5'&&digit!='6'&&digit!='7'&&digit!='8'&&digit!='9')
    {
        cout<<"Wrong operation"<<endl;
        isOperationTrue=false;
    }
    else if(digit=='+'||digit=='*')   //if there is a operation in the beginning of a file(wrong)
    {
        cout<<"Wrong operation"<<endl;
        isOperationTrue=false;
    }
    else
    {
        bool check = false;
        while(true)
        {
            myFile>>digit;
            //if there is a character or unknown operation
            if(digit!='+'&&digit!='*'&&digit!='0'&&digit!='1'&&digit!='2'&&digit!='3'&&digit!='4'&&digit!='5'&&digit!='6'&&digit!='7'&&digit!='8'&&digit!='9')
            {
                cout<<"Wrong operation"<<endl;
                isOperationTrue=false;
                break;
            }
            if(check==true&&(digit=='+'||digit=='*'))  //if there is a operation like this (100+*23)
            {
                cout<<"Wrong operation"<<endl;
                isOperationTrue = false;
                break;
            }
            check = false;
            if(digit=='+'||digit=='*')
            {
                check = true;
                if(digit=='+')
                    OperationArr[Num] = 0;
                if(digit=='*')
                    OperationArr[Num] = 1;
                if(myFile.eof())              //if there is a operation like this 100*900+
                {
                    cout<<"Wrong operation"<<endl;
                    isOperationTrue = false;
                    break;
                }
                
                Num++;
                continue;
            }
            if(myFile.eof()) break;
            int i = digit - '0';
            addToTail(i, Num);
        }
    }
    
    //when we are done with creating lists then we can print them
    if(isOperationTrue)
    {
        for(int i=0;i<NumberCount;i++)
        {
            cout<<i+1<<". Number: ";
            printAll(i);
            if(OperationArr[i]==0)
                cout<<"+"<<endl;
            else if(OperationArr[i]==1)
                cout<<"*"<<endl;
        }
    }

    
}


void BigNumber::addToHead(int data, int Number)
{
    if(Number==-1)  //Adding head for tempresHead linked list
    {
        DLLNode *temp = tempResHead;
        DLLNode *newEl = new DLLNode(data,NULL,NULL);
        
        if(tempResHead == NULL)
        {
            tempResHead=newEl;
            tempResTail=newEl;
            return;
        }
        tempResHead = newEl;
        newEl->next = temp;
        temp->prev = newEl;
        return;
        
    }
    else  //adding head for numbers
    {
        DLLNode *temp = NumbersHead[Number];
        DLLNode *newEl = new DLLNode(data,NULL,NULL);
        
        
        if(NumbersHead[Number]==NULL) //if the list is empty.
        {
            NumbersHead[Number]=newEl;
            NumbersTail[Number]=newEl;
            return;
        }
        NumbersHead[Number] = newEl;
        newEl->next = temp;
        temp->prev = newEl;
    }

    
}
void BigNumber::printAll(int Number) const
{
    if(isOperationTrue)
    {
        if(Number==-1)       //to print  temp Result
        {
            DLLNode *temp = tempResHead;
            if(tempResHead == NULL)
                cout<<"Your Linked List is empty."<<endl;
            else
            {
//                cout<<"Your Current List: ";
                while(temp!=NULL)
                {
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }
        else if(Number==-2)          //to print Result
        {
            DLLNode *temp = ResultHead;
            if(ResultHead == NULL)
                cout<<"Your Linked List is empty."<<endl;
            else
            {
//                cout<<"Your Current List: ";
                while(temp!=NULL)
                {
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }
        else                    //to print Numbers
        {
            DLLNode *temp = NumbersHead[Number];
            if(NumbersHead[Number] == NULL)
                cout<<"Your Linked List is empty."<<endl;
            else
            {
//                cout<<"Your Current List: ";
                while(temp!=NULL)
                {
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }
    }
    else
    {
        cout<<"You can not print numbers your operations are wrong"<<endl;
    }

    
}

void BigNumber::addToTail(int data, int Number)
{
    DLLNode *temp = NumbersTail[Number];
    DLLNode *newEl = new DLLNode(data,NULL,NULL);

    if(NumbersTail[Number] == NULL)
        addToHead(data, Number);
    else
    {
        temp = NumbersTail[Number];
        temp->next = newEl;
        newEl->prev = temp;
        NumbersTail[Number] = newEl;
    }
}
int BigNumber::deleteFromHead(int Number) //delete and return the element
{
    if(NumbersHead[Number] == NULL)
        return -1;
    
    int delEl;
    DLLNode *cur = NumbersHead[Number];
    if(NumbersHead[Number]->next == NULL)
    {
        NumbersHead[Number] = NumbersTail[Number] = NULL;
        delEl=cur->data;
        delete cur;
        cur = NULL;
        return delEl;
    }
    NumbersHead[Number] = cur->next;
    NumbersHead[Number]->prev = NULL;
    delEl=cur->data;
    cur->next = NULL;
    cur->prev = NULL;
    delete cur;
    cur = NULL;
    return delEl;
}


int BigNumber::deleteFromTail(int Number)
{
    int delEl;
    if(NumbersTail[Number] == NULL)
    {
        return -1;
    }
    DLLNode *cur = NumbersTail[Number];
    if(cur->prev == NULL && cur->next == NULL)
    {
        NumbersHead[Number] = NumbersTail[Number] = NULL;
        delEl = cur->data;
        delete cur;
        cur = NULL;
        return delEl;;
    }
    NumbersTail[Number] = NumbersTail[Number]->prev;
    NumbersTail[Number]->next = NULL;
    delEl = cur->data;
    cur->prev = NULL;
    delete cur;
    cur = NULL;
    return delEl;
}


int main()
{
    string filename = "/Users/turkerkoc/Desktop/Yeditepe/2018 Güz/DATA STRUCTURES CSE211/Term Project/Term Project(Operations with Big Numbers)/inputFile.txt";
    string filename2 = "/Users/turkerkoc/Desktop/Yeditepe/2018 Güz/DATA STRUCTURES CSE211/Term Project/Term Project(Operations with Big Numbers)/outputFile.txt";

    BigNumber myBigNumber(filename);
    myBigNumber.UpdateBigInt(filename2);  //output file
    
    
    return 0;
}
