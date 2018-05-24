#ifndef C86_H
#define C86_H
#include<iostream>
#include<stack>
using namespace std;
/*
* 二叉查找树迭代器

* 设计实现一个带有下列属性的二叉查找树的迭代器：
* 元素按照递增的顺序被访问（比如中序遍历）
* next()和hasNext()的询问操作要求均摊时间复杂度是O(1)
* 样例
* 对于下列二叉查找树，使用迭代器进行中序遍历的结果为 [1, 6, 10, 11, 12]
*           10
*          /    \
*        1      11
*         \       \
*         6       12
*挑战
* 额外空间复杂度是O(h)，其中h是这棵树的高度
* Super Star：使用O(1)的额外空间复杂度
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