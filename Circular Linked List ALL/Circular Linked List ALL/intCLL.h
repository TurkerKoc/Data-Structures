//************************  intSLList.h  **************************
//           singly-linked list class to store integers

#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntCLLNode {
public:
    IntCLLNode()
    {
        next = 0;
    }
    IntCLLNode(int el, IntCLLNode *ptr = 0)
    {
        data = el; next = ptr;
    }
    int data;
    IntCLLNode *next;
};

class IntCLList
{
public:
    IntCLList()
    {
        tail = NULL;
    }
    
    int isEmpty()
    {
        return tail == 0;
    }
    
    void addToTail(int);
    void addToBegin(int);
    void addToEmpty(int);
    void deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;
    void printAll() const;
    IntCLLNode getHead();
    
    
private:
    IntCLLNode *tail;
};





#endif


