/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
    void deleteNodeBegin(int delData);
    void deleteNodeEnd(int delData);
    void printList();
    
};

List::List()
{
    Head = NULL;
    Curr = NULL;
    temp = NULL;
}

void List::addNodeBegin(int addData)
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
    for(int i=1; i<=10; i++)
        l.addNodeBegin(i);
    l.printList();

    return 0;
}



