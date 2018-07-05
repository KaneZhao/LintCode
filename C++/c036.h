#ifndef C036_H
#define C036_H
#include<iostream>
using namespace std;
/*
* ��ת���� II
*
* ����
* ��ת�����е�m���ڵ㵽��n���ڵ�Ĳ���
* m��n����1 �� m �� n �� ������
* ������ʵ���������Ƿ�����������⣿
* ����
* ��������1->2->3->4->5->null�� m = 2 ��n = 4������1->4->3->2->5->null
* ��ս
* ��ԭ��һ�η�ת���
*/
class ListNode{
public:
	int val;
	ListNode *next;
	ListNode(int val){
		this->val = val;
		this->next = next;
	}
};
class Solution {
public:
	/**
	* @param head: ListNode head is the head of the linked list
	* @param m: An integer
	* @param n: An integer
	* @return: The head of the reversed ListNode
	*/
	ListNode * reverseBetween(ListNode * head, int m, int n) {
		// write your code here
		//��m����n,����ת
		if (m == n)
			return head;
		ListNode *pn = head, *pm = head;
		ListNode *node = new ListNode(-1);
		node->next = head;
		ListNode *pre = node;
		//�ҵ���m���ڵ����ǰһ���ڵ�
		for (int i = 1; i < m; ++i)
		{
			pm = pm->next;
			pre = pre->next;
		}
		//�ҵ���n���ڵ�
		for (int i = 1; i < n; ++i)
		{
			pn = pn->next;
		}
		ListNode *post = pn->next;//post��ʾ��m���ڵ�ĺ�һ���ڵ�
		ListNode *start = pre;//start��ʾ��n���ڵ��ǰһ���ڵ�
		//pre��ʾҪ��ת�ĵ�һ���ڵ�,pm��ʾҪ��ת�ĵڶ����ڵ�
		pre = pre->next;
		pm = pm->next;
		//���浱ǰ�ڵ�pm,ǰһ���ڵ�pre�Լ���һ���ڵ�pnext
		//��pm->next=pre�ٴ�����ڵ�
		for (int i = 0; i < n - m; ++i)
		{
			ListNode *pnext = pm->next;
			pm->next = pre;
			if (i == 0)
				pre->next = post;
			pre = pm;
			pm = pnext;
		}
		start->next = pre;
		return node->next;
	}
};
#endif