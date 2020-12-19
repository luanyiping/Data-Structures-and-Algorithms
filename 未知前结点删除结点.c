#include<stdio.h>
struct ListNode
{
	int data;
	struct ListNode* next;
};
void deleteNode(struct ListNode* node)
{
	struct ListNode* p = node, * q = node->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
}
