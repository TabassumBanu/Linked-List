
#include <iostream>

using namespace std;

class List
{
    private:
    
    typedef struct node
    {
        int data;
        struct node* next;
    }* nodePtr;
    
    nodePtr Head;
    nodePtr Curr;
    nodePtr temp;
    
    public:
    
    List();
    void addNodeBegin(int addData);
    void addNodeEnd(int addData);
    void deleteNodeBegin();
    void deleteNodeEnd();
    void printList();
    
};

List::List()
{
    Head = NULL;
    Curr = NULL;
    temp = NULL;
}

void List::deleteNodeEnd()
{
    if(Head != NULL)
   {
       Curr = Head;
       while(Curr->next->next != NULL)
            Curr = Curr->next;
        Curr->next = NULL;
    }
}

void List::deleteNodeBegin()
{
    if(Head != NULL)
    {
        Head = Head->next;
    }
}

void List::addNodeEnd(int addData)
{
   nodePtr newNode = new node;
   newNode->data = addData;
   newNode->next = NULL;
   
   if(Head != NULL)
   {
       Curr = Head;
       while(Curr->next != NULL)
            Curr = Curr->next;
        Curr->next = newNode;
    }
    else
    {
        Head = newNode;
    }
}

void List::addNodeBegin(int addData)
{
   nodePtr newNode = new node;
   newNode->data = addData;
   newNode->next = NULL;
   
   if(Head != NULL)
   {
       newNode->next = Head;
        Head = newNode;
    }
    else
    {
        Head = newNode;
    }
}
void List::printList()
{
    temp = Head;
    cout<<"list output \n";
  
    while(temp)
    {
        cout<<temp->data;
        cout<<"\t";
        temp = temp->next;
    }
}
int main()
{
    List l;
    int i;
    
    for(i=1; i<=10; ++i)
    {
        l.addNodeBegin(i);
    }
    ++i;
    l.addNodeEnd(i);
    l.deleteNodeBegin();
    l.deleteNodeEnd();

    l.printList();

    return 0;
}



