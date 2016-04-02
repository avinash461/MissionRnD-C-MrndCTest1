/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int merge_circularlists(struct node **head1, struct node **head2){
	if ((*head1) && (*head2))
	{
		int len = 0;
		struct node *first_list = *head1;
		struct node *sec_list = *head2;
		struct node *temp;
		struct node *temp2=NULL;
		temp = *head1;
		while (temp->next != *head1)
		{
			len++;
			temp = temp->next;
		}
		temp->next = NULL;
		temp = *head2;
		while (temp->next != *head2)
		{
			len++;
			temp = temp->next;
		}
		len = len + 2;
		temp->next = NULL;
		while (first_list != NULL && sec_list != NULL)
		{
			if (first_list->data <= sec_list->data)
			{
				if (temp2 == NULL)
				{
					temp2 = first_list;
				}
				else
				{
					temp2->next = first_list;
				}
				first_list = first_list->next;
			}
			if (sec_list->data <= first_list->data)
			{
				if (temp2 == NULL)
				{
					temp2 = sec_list;
				}
				else
				{
					temp2->next = sec_list;
				}
				sec_list = sec_list->next;

			}
		}
		if (first_list == NULL)
		{
			temp2->next = sec_list;
		}
		if (sec_list == NULL)
		{
			temp2->next = first_list;
		}
		*head1 = temp2;
		while (temp2)
		{
			temp2 = temp2->next;
		}
		temp2->next = *head1;
		return len;
	}
	return -1;
}

