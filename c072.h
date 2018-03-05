#ifndef C72_H
#define C72_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 中序遍历和后序遍历树构造二叉树
*
* 根据中序遍历和后序遍历树构造二叉树
* 注意事项
* 你可以假设树中不存在相同数值的节点
* 样例
* 给出树的中序遍历： [1,2,3] 和后序遍历： [1,3,2]
* 返回如下的树：
*   2
*  /  \
* 1    3
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
class Solution {
public:
	/*
	* @param inorder: A list of integers that inorder traversal of a tree
	* @param postorder: A list of integers that postorder traversal of a tree
	* @return: Root of a tree
	*/
	typedef vector<int>::iterator iter;
	TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
		// write your code here
		if (inorder.empty())
			return NULL;
		TreeNode *node = helper(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());
		return node;
	}
	//递归地构造二叉树
	//postorder的最后一个元素作为根节点rootVal,在inorder中寻找rootVal,其左右两边作为新的
	//inorder,并由此获得新的postorder
	TreeNode *helper(iter pstart, iter pend, iter istart, iter iend)
	{
		if (pend == pstart)
			return NULL;
		int rootVal = *(pend - 1);
		iter rootIter = find(istart, iend, rootVal);
		TreeNode *res = new TreeNode(rootVal);
		res->left = helper(pstart, pstart + (rootIter - istart), istart, rootIter);
		res->right = helper(pstart + (rootIter - istart) ,pend -1, rootIter + 1, iend);
		return res;
	}
};
#endif