#ifndef C735_H
#define C735_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��һ��������, �õ�ǰԪ��֮�������е����Ԫ�����滻��ǰԪ��(�Ҳ�����Ԫ��). ��Ϊ���һ��Ԫ�ص��ұ�û��Ԫ����, 
* ������ -1 ���滻���ֵ. �ٸ�����, �������Ϊ [16,17,4,3,5,2], ��ô������Ҫ�޸�Ϊ [17,5,5,5,2,-1].
*/
class Solution {
public:
	/*
	* @param : An array of integers.
	* @return: nothing
	*/
	void arrayReplaceWithGreatestFromRight(vector<int> &nums) {
		// Write your code here.
		if (nums.empty())
			return;
		int len = nums.size();
		int num = nums[len - 1];
		nums[len - 1] = -1;
		for (int i = len - 2; i >= 0; --i)
		{
			int tmp = nums[i];
			nums[i] = num;
			if (tmp > num)
				num = tmp;
		}
	}
};
#endif