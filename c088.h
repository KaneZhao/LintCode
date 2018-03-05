#ifndef C88_H
#define C88_H
#include<iostream>
using namespace std;
//�����������

//����һ�ö��������ҵ������ڵ������������ڵ�(lca)��
//
//������������������ڵ�Ĺ��������Ƚڵ��Ҿ��������ȡ�
//
//ע������
//��������������ڵ㶼�����д���
//
//������ʵ���������Ƿ�����������⣿ yes
//����
//����������ö�����
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
		//��root������������ѯ�ڵ�
		TreeNode *l = lowestCommonAncestor(root->left, A, B);
		TreeNode *r = lowestCommonAncestor(root->right, A, B);
		//���ֱ������root������������,��root���������������
		if (l&&r)
			return root;
		return l ? l : r;
	}
};
#endif