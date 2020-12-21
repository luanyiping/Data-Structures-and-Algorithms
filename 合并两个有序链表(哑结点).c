struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p = prev;
	while(l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			prev->next = l1;
			l1 = l1->next;
		}
		else
		{
			prev->next = l2;
			l2 = l2->next;
		}
		prev = prev->next;
	}
	prev->next = (l2 == NULL) ? l1 : l2;
	return p->next;

}