#include<stdio.h>
struct ListNode
{
	int data;
	struct ListNode* next;
};
int kthToLast(struct ListNode* head, int k)
{
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (k--)
	{
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow->data;
}
