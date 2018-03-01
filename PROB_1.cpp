// C program to find n'th node from end using slow and fast pointers
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
int data;
struct Node* next;
};

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node *head, int n)
{
struct Node *main_ptr = head;
struct Node *ref_ptr = head;

int count = 0;
if(head != NULL)
{
	while( count < n )
	{
		if(ref_ptr == NULL)
		{
		printf("\n %d is greater than the no. of "
					"nodes in list", n);
		return;
		}
		ref_ptr = ref_ptr->next;
		count++;
	} /* End of while*/

	while(ref_ptr != NULL)
	{
		main_ptr = main_ptr->next;
		ref_ptr = ref_ptr->next;
	}
	printf("\n Node no. %d from last is %d ", 
			n, main_ptr->data);
}
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* newNode = (struct Node *)malloc(sizeof (struct Node));
    if(!newNode)
    {
        printf("malloc failed.....\n");
        return;
    }
    newNode->data = new_data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

/* Drier program to test above function*/
int main()
{
/* Start with the empty list */
  struct Node* head = NULL;
  struct Node* temp;
  push(&head, 20);
	push(&head, 4);
  push(&head, 15);
	push(&head, 35);
  
  temp = head;
	while(temp != NULL)
	{
		printf("%d \t",temp->data);
		temp = temp->next;
	}	
    printNthFromLast(head, 2);
}

    
