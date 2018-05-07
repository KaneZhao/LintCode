#ifndef C545_H
#define C545_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
/*
* ǰK���� II
*
* ʵ��һ�����ݽṹ���ṩ���������ӿ�
* 1.add(number) ���һ��Ԫ��
* 2.topk() ����ǰK�����
* ����
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
		//�����������󳤶�Ϊk
		size = k;
	}

	  /*
	  * @param num: Number to be added
	  * @return: nothing
	  */
	  void add(int num) {
		  // write your code here
		  //������鳤��С��size,��num���뵽�������Ӧλ��
		  //����,��num�Ĳ���λ�ò���ĩβ,�������,����ĩβԪ���޳�
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
	  int size = 0;//��ʾ����ĳ���
	  vector<int> res;//��ʾ���ص�����
};
#endif