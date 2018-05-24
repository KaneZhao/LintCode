#ifndef C591_H
#define C591_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 连接图 III
*
* 给一个图中的 n 个节点, 记为 1 到 n . 在开始的时候图中没有边.
* 你需要完成下面两个方法:
* 1. connect(a, b), 添加一条连接节点 a, b的边
* 2. query(), 返回图中联通区域个数
* 样例
* 5 // n = 5
* query() 返回 5
* connect(1, 2)
* query() 返回 4
* connect(2, 4)
* query() 返回 3
* connect(1, 4)
* query() 返回 3
*/
class ConnectingGraph3 {
public:
	/*
	* @param n: An integer
	*/ConnectingGraph3(int n) {
		// do intialization if necessary
		//初始化nums的值
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
		  //若其顶层节点不同,合并顶层节点
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
	  //返回root最顶层的值,并进行路径压缩
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