#ifndef C036_H
#define C036_H
#include<iostream>
using namespace std;
/*
* 翻转链表 II
*
* 描述
* 翻转链表中第m个节点到第n个节点的部分
* m，n满足1 ≤ m ≤ n ≤ 链表长度
* 您在真实的面试中是否遇到过这个题？
* 样例
* 给出链表1->2->3->4->5->null， m = 2 和n = 4，返回1->4->3->2->5->null
* 挑战
* 在原地一次翻转完成
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
		//当m等于n,不翻转
		if (m == n)
			return head;
		ListNode *pn = head, *pm = head;
		ListNode *node = new ListNode(-1);
		node->next = head;
		ListNode *pre = node;
		//找到第m个节点和其前一个节点
		for (int i = 1; i < m; ++i)
		{
			pm = pm->next;
			pre = pre->next;
		}
		//找到第n个节点
		for (int i = 1; i < n; ++i)
		{
			pn = pn->next;
		}
		ListNode *post = pn->next;//post表示第m个节点的后一个节点
		ListNode *start = pre;//start表示第n个节点的前一个节点
		//pre表示要翻转的第一个节点,pm表示要翻转的第二个节点
		pre = pre->next;
		pm = pm->next;
		//保存当前节点pm,前一个节点pre以及后一个节点pnext
		//令pm->next=pre再处理各节点
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