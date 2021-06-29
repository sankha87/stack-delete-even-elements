#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *next;
};
void display(struct Node *n)
{
	while (n != NULL)
	{
		printf(" %d ", n->data);
		n = n->next;
	}
}
Node* push(struct Node *head_ref, int data)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = head_ref;
	head_ref = new_node;
	return head_ref;
}
int return_top(struct Node *head_ref)
{
	return head_ref->data;
}
Node* pop(struct Node *head_ref)
{
	struct Node *temp = head_ref;
	head_ref = head_ref->next;
	free(temp);
	return head_ref;
}
Node* delete_even_element(struct Node *head_ref)
{
	int counter = 0;
	struct Node *temp = head_ref, *prev = head_ref, *temp2 = head_ref;
	while (temp2 != NULL)
	{
		prev = temp2;
		temp = prev->next;
		if (prev->data % 2 == 0)
		{
			head_ref = head_ref->next;
			temp2 = head_ref;
			free(prev);
		}
		else
		{
			if (temp->data % 2 == 0)
			{
				prev->next = temp->next;
				temp2 = prev->next;
				free(temp);
			}
		}
	}
	return head_ref;
}
void main()
{
	struct Node *top = NULL;
	top = push(top, 60);
	top = push(top, 55);
	top = push(top, 50);
	top = push(top, 45);
	top = push(top, 40);
	top = push(top, 35);
	top = push(top, 30);
	top = push(top, 25);
	top = push(top, 20);
	top = push(top, 15);
	top = push(top, 10);
	top = push(top, 5);
	printf("After push operation, Stack is : ");
	display(top);
	printf("\n\nTop Of Stack is : ");
	printf(" %d ", return_top(top));
	top = pop(top);
	printf("\n\nAfter POP operation, The Stack is: ");
	display(top);
	top = delete_even_element(top);
	printf("\n\nAfter delete_even_element operation, The Stack is: ");
	display(top);
	_getch();
}