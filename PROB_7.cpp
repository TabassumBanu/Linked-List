/* Program to check if a linked list is palindrome */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Link list node */
struct Node
{
	char data;
	struct Node* next;
};

void printList(struct Node *ptr)
{
	while (ptr != NULL)
	{
		printf("%c->", ptr->data);
		ptr = ptr->next;
	}
}

bool compareLists(struct Node* head1, struct Node *second_half)
{
	struct Node* temp1 = head1;
	struct Node* temp2 = second_half;

	while (second_half)
	{
		if (temp1->data == second_half->data)
		{
			temp1 = temp1->next;
			temp2 = second_half->next;
		}
		else return 0;
	}

	/* Both are empty reurn 1*/
	if (second_half == NULL)
		return 1;

}

struct Node* reverse(struct Node* head_ref)
{
    if(head_ref == NULL || head_ref->next == NULL)
        return head_ref;
        
    struct Node* temp = reverse(head_ref->next);
    head_ref->next->next = head_ref;
    head_ref->next = NULL;
    return temp;
}

bool isPalindrome(struct Node *head)
{
	struct Node *slow_ptr = head, *fast_ptr = head;
	struct Node *second_half;
	bool res = false; 

	while (fast_ptr != NULL && fast_ptr->next != NULL)
	{
	 //   fast_ptr = fast_ptr->next->next;
    //	slow_ptr = slow_ptr->next;
	}

	if (fast_ptr != NULL)
	{
	//	second_half = slow_ptr->next;
	}
	if (fast_ptr->next != NULL)
	{
		//second_half = slow_ptr->next->next;
	}
	//struct Node *temp = reverse(second_half); // Reverse the second half
	//printList(temp);
	//res = compareLists(head, temp); // compare
	return res;
}

void push(struct Node** head_ref, char new_data)
{

	struct Node* temp = *head_ref
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head_ref == NULL)
	    *head_ref = new_node;
	 else
	 {
	    while(temp->next) 
	        temp = temp->next
	 }
	 
}

int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;
	char str[] = "adcddcba";
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
	    push(&head, str[i]);
	}
	
	printList(head);
//	isPalindrome(head)? printf("Is Palindrome\n\n"):
						//printf("Not Palindrome\n\n");

	return 0;
}
