#ifndef C106_H
#define C106_H
#include<iostream>
using namespace std;
/*
* �����б�ת��Ϊ���ֲ�����
* 
* ����һ������Ԫ������������ĵ���������ת����һ�ø߶�ƽ��Ķ��ֲ�����
*
* ����
*                2
* 1->2->3  =>   / \
*              1   3
*/
class TreeNode{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val){
		this->val = val;
		this->left = this->right = NULL;
	}
};
class ListNode{
public:
	int val;
	ListNode *next;
	ListNode(int val){
		this->val = val;
		this->next = NULL;
	}
};
class Solution {
public:
	/**
	* @param head: The first node of linked list.
	* @return: a tree node
	*/
	TreeNode *sortedListToBST(ListNode *head) {
		// write your code here
		if (head == NULL)
			return NULL;
		ListNode *node = new ListNode(-1);
		node->next = head;
		ListNode *fast = head, *slow = node;
		//���ÿ���ָ��,���ҵ������������ֵ
		while (fast != NULL&&fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode *root = new TreeNode(slow->next->val);
		ListNode *second = slow->next->next;
		slow->next = NULL;
		ListNode *first = node->next;
		root->left = sortedListToBST(first);
		root->right = sortedListToBST(second);
		return root;
	}
	
};
#endif