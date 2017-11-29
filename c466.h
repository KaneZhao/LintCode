#ifndef C466_H
#define C466_H
#include<iostream>
using namespace std;
/*
* Count how many nodes in a linked list.
* 
* Example
* Given 1->3->5, return 3.
*/
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
	/*
	* @param head: the first node of linked list.
	* @return: An integer
	*/
	int countNodes(ListNode * head) {
		// write your code here
		if (head == NULL)
			return 0;
		ListNode *p = head;
		int len = 0;
		while (p != NULL)
		{
			len++;
			p = p->next;
		}
		return len;
	}
};
#endif