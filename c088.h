#ifndef C88_H
#define C88_H
#include<iostream>
using namespace std;
//最近公共祖先

//给定一棵二叉树，找到两个节点的最近公共父节点(lca)。
//
//最近公共祖先是两个节点的公共的祖先节点且具有最大深度。
//
//注意事项
//假设给出的两个节点都在树中存在
//
//您在真实的面试中是否遇到过这个题？ yes
//样例
//对于下面这棵二叉树
//
//         4
//        / \
//       3   7
//          / \
//         5   6
//lca(3, 5) = 4
//
//lca(5, 6) = 7
//
//lca(6, 7) = 7
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
	* @param root: The root of the binary search tree.
	* @param A: A TreeNode in a Binary.
	* @param B: A TreeNode in a Binary.
	* @return: Return the least common ancestor(LCA) of the two nodes.
	*/
	TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
		// write your code here
		if (!root)
			return NULL;
		if (root == A)
			return A;
		if (root == B)
			return B;
		//从root的左右子树查询节点
		TreeNode *l = lowestCommonAncestor(root->left, A, B);
		TreeNode *r = lowestCommonAncestor(root->right, A, B);
		//若分别存在于root的左右子树中,则root就是最近公共祖先
		if (l&&r)
			return root;
		return l ? l : r;
	}
};
#endif