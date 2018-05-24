#ifndef C86_H
#define C86_H
#include<iostream>
#include<stack>
using namespace std;
/*
* ���������������

* ���ʵ��һ�������������ԵĶ���������ĵ�������
* Ԫ�ذ��յ�����˳�򱻷��ʣ��������������
* next()��hasNext()��ѯ�ʲ���Ҫ���̯ʱ�临�Ӷ���O(1)
* ����
* �������ж����������ʹ�õ�����������������Ľ��Ϊ [1, 6, 10, 11, 12]
*           10
*          /    \
*        1      11
*         \       \
*         6       12
*��ս
* ����ռ临�Ӷ���O(h)������h��������ĸ߶�
* Super Star��ʹ��O(1)�Ķ���ռ临�Ӷ�
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
class BSTIterator {
public:
	/*
	* @param root: The root of binary tree.
	*/BSTIterator(TreeNode * root) {
		// do intialization if necessary
		while (root)
		{
			s.push(root);
			root = root->left;
		}
	}

	  /*
	  * @return: True if there has next node, or false
	  */
	  bool hasNext() {
		  // write your code here
		  return !s.empty();
	  }

	  /*
	  * @return: return next node
	  */
	  TreeNode * next() {
		  // write your code here
		  TreeNode *cur = s.top();
		  s.pop();
		  TreeNode *node = cur;
		  if (cur->right)
		  {
			  cur = cur->right;
			  while (cur)
			  {
				  s.push(cur);
				  cur = cur->left;
			  }
		  }
		  return node;
	  }
	  stack<TreeNode*> s;
};
#endif