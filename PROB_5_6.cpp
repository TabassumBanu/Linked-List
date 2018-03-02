//Algorithm to detect loop in linked list
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};

void removeLoop1(struct Node *loop_node, struct Node *head)
{
   struct Node *ptr1;
   struct Node *ptr2;

   ptr1 = head;
   while (1)
   {

     ptr2 = loop_node;
     while (ptr2->next != loop_node && ptr2->next != ptr1)
         ptr2 = ptr2->next;
 
     if (ptr2->next == ptr1)
        break;
     ptr1 = ptr1->next;
   }
    printf("%d is loop point\n",ptr1->data);
   ptr2->next = NULL;
}
 

int detectLoop(struct Node *head)
{
    struct Node  *slow_p = head, *fast_p = head;
 
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        
        if (slow_p == fast_p)
        {
            break;
        }
    }
    removeLoop1(slow_p, head);//method1
    
    /*or method 2 in below if condition
    if (slow_p == fast_p)
    {
        slow_p = head;
        while (slow_p->next != fast_p->next)
        {
            slow_p = slow_p->next;
            fast_p = fast_p->next;
        }
        printf("%d is loop point\n",slow_p->next->data);
         fast_p->next = NULL;
    }
    */
                
}

/* Function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
 
struct Node *newNode(int key)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
/* Drier program to test above function*/
int main()
{
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    detectLoop(head);
    printf("Linked List after removing loop \n");
    printList(head);
    return 0;
}
