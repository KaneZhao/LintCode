#ifndef C545_H
#define C545_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
/*
* 前K大数 II
*
* 实现一个数据结构，提供下面两个接口
* 1.add(number) 添加一个元素
* 2.topk() 返回前K大的数
* 样例
* s = new Solution(3);
* >> create a new data structure.
* s.add(3)
* s.add(10)
* s.topk()
* >> return [10, 3]
* s.add(1000)
* s.add(-99)
* s.topk()
* >> return [1000, 10, 3]
* s.add(4)
* s.topk()
* >> return [1000, 10, 4]
* s.add(100)
* s.topk()
* >> return [1000, 100, 10]
*/
class Solution {
public:
	/*
	* @param k: An integer
	*/Solution(int k) {
		// do intialization if necessary
		//设置数组的最大长度为k
		size = k;
	}

	  /*
	  * @param num: Number to be added
	  * @return: nothing
	  */
	  void add(int num) {
		  // write your code here
		  //如果数组长度小于size,将num插入到数组的相应位置
		  //否则,若num的插入位置不是末尾,将其插入,并将末尾元素剔除
		  auto pos = lower_bound(res.begin(), res.end(), num, greater<int>());
		  if (res.size() < size)
		  {
			  res.insert(pos, num);
		  }
		  else
		  {
			  if (pos != res.end())
			  {
				  res.insert(pos, num);
				  res.pop_back();
			  }
		  }
	  }

	  /*
	  * @return: Top k element
	  */
	  vector<int> topk() {
		  // write your code here
		  return res;
	  }
	  int size = 0;//表示数组的长度
	  vector<int> res;//表示返回的数组
};
#endif