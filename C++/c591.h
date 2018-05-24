#ifndef C591_H
#define C591_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ����ͼ III
*
* ��һ��ͼ�е� n ���ڵ�, ��Ϊ 1 �� n . �ڿ�ʼ��ʱ��ͼ��û�б�.
* ����Ҫ���������������:
* 1. connect(a, b), ���һ�����ӽڵ� a, b�ı�
* 2. query(), ����ͼ����ͨ�������
* ����
* 5 // n = 5
* query() ���� 5
* connect(1, 2)
* query() ���� 4
* connect(2, 4)
* query() ���� 3
* connect(1, 4)
* query() ���� 3
*/
class ConnectingGraph3 {
public:
	/*
	* @param n: An integer
	*/ConnectingGraph3(int n) {
		// do intialization if necessary
		//��ʼ��nums��ֵ
		for (int i = 0; i <= n; ++i)
			nums.push_back(i);
		cnt = n;
	}

	  /*
	  * @param a: An integer
	  * @param b: An integer
	  * @return: nothing
	  */
	  void connect(int a, int b) {
		  // write your code here
		  int root1 = unionSearch(a, nums);
		  int root2 = unionSearch(b, nums);
		  //���䶥��ڵ㲻ͬ,�ϲ�����ڵ�
		  if (root1 != root2)
		  {
			  nums[root1] = root2;
			  cnt--;
		  }
	  }

	  /*
	  * @return: An integer
	  */
	  int query() {
		  // write your code here
		  return cnt;
	  }
	  //����root����ֵ,������·��ѹ��
	  int unionSearch(int root, vector<int>& nums)
	  {
		  while (root != nums[root])
		  {
			  nums[root] = nums[nums[root]];
			  root = nums[root];
		  }
		  return root;
	  }
	  vector<int> nums;
	  int cnt;
};
#endif