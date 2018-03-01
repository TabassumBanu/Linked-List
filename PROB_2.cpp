/* Function to get the middle of the linked list
Method 1 usinf fast and slow pointer


void printMiddle(struct Node *head)
{
	struct Node *slow_ptr = head;
	struct Node *fast_ptr = head;

	if (head!=NULL)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}
		printf("The middle element is [%d]\n\n", slow_ptr->data);
	}
}

Method 2:
traverse only if count is odd
*/
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
	int data;
	struct node* next;
};

/* Function to get the middle of the linked list*/
void printMiddle(struct node *head)
{
	int count = 0;
	struct node *mid = head;

	while (head != NULL)
	{
		/* update mid, when 'count' is odd number */
		if (count & 1)
			mid = mid->next;

		++count;
		head = head->next;
	}

	/* if empty list is provided */
	if (mid != NULL)
		printf("The middle element is [%d]\n\n", mid->data);
}


void push(struct node** head_ref, int new_data)
{
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));
    
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

// A utility function to print a given linked list
void printList(struct node *ptr)
{
	while (ptr != NULL)
	{
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	struct node* head = NULL;
	int i;

	for (i=5; i>0; i--)
	{
		push(&head, i);
		printList(head);
		printMiddle(head);
	}

	return 0;
}
