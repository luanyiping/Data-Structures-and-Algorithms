struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    /* ���� */
    if (l1 == NULL || l2 == NULL) {
        return l1 != NULL ? l1 : l2;
    }

    struct ListNode* mergeHead = NULL;
    if (l1->val < l2->val) {
        /* ��ȡ�ϲ�֮��������ͷ�ڵ� */
        mergeHead = l1;
        /* ���ϲ�֮�������ҽ���������ͷ�ڵ�֮�� */
        mergeHead->next = mergeTwoLists(l1->next, l2);
    }
    else {
        mergeHead = l2;
        mergeHead->next = mergeTwoLists(l1, l2->next);
    }

    return mergeHead;
}