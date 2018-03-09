
#include <iostream>

using namespace std;
template <class T>
class List
{
    private:
    
    typedef struct node
    {
        T data;
        struct node* next;
    }* nodePtr;
    
    nodePtr Head;
    nodePtr Curr;
    nodePtr temp;
    
    public:
    
    List();
    void addNodeBegin(T addData);
    void addNodeEnd(T addData);
    void deleteNodeBegin();
    void deleteNodeEnd();
    void printList();
    
};

template <class T>
List<T>::List()
{
    Head = NULL;
    Curr = NULL;
    temp = NULL;
}

template <class T>
void List<T>::deleteNodeEnd()
{
    if(Head != NULL)
   {
       Curr = Head;
       while(Curr->next->next != NULL)
            Curr = Curr->next;
        Curr->next = NULL;
    }
}

template <class T>
void List<T>::deleteNodeBegin()
{
    if(Head != NULL)
    {
        Head = Head->next;
    }
}
template <class T>
void List<T>::addNodeEnd(T addData)
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
template <class T>
void List<T>::addNodeBegin(T addData)
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
template <class T>
void List<T>::printList()
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
    List<char>l;
    char str[] = "abacaba";
    int i;
 
    for (i = 0; str[i] != '\0'; i++)
    {
        l.addNodeEnd(str[i]);
    }

    l.printList();

    return 0;
}



