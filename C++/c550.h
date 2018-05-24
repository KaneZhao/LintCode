#ifndef C550_H
#define C550_H
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
/*
* �ʹ�õ�K������II
*
* ����
* ��ʵʱ���������ҵ��ʹ�õ�k������.
* ʵ��TopK���е���������:
* TopK(k), ���췽��
* add(word), ����һ���µ���
* topk(), �õ���ǰ�ʹ�õ�k������.
* ���������������ͬ��ʹ��Ƶ��, ����ĸ����.
* ����
* TopK(2)
* add("lint")
* add("code")
* add("code")
* topk()
* >> ["code", "lint"]
*/

//����lower_bound��cmp����,�ڽ����������ҵ�Ԫ�صĲ���λ��,��Ԫ�ص�������ͬ,�ַ������ֵ���
struct cmp{
	bool operator()(pair<int, string> a, pair<int, string> b)
	{
		if (a.first != b.first)
		{
			return a.first > b.first;
		}
		else
			return a.second < b.second;
	}
};
class TopK {
public:
	/*
	* @param k: An integer
	*/TopK(int k) {
		// do intialization if necessary
		this->k = k;
	}

	  /*
	  * @param word: A string
	  * @return: nothing
	  */
	  void add(string word) {
		  // write your code here
		  //���ڵ���word,�Ȼ�ȡ����ִ���,������pair
		  auto temp = make_pair(all[word], word);
		  //���word��ǰk��Ƶ����,��words��cur��ɾ��word,����word�ĳ��ִ���
		  if (cur.find(word) != cur.end())
		  {
			  words.erase(find(words.begin(), words.end(), temp));
			  cur.erase(cur.find(word));
		  }
		  temp.first++;
		  //���µ�����words��Ѱ��temp�Ĳ���λ��
		  //���words�ĳ���С��k,ֱ�Ӳ���,����word����cur��
		  //����,�жϲ���λ���Ƿ���ĩβ,����ĩβ��ʾ���ִ�����ǰk���,
		  //�������words��,����words��ĩβԪ��ɾ��,����cur��ֵ
		  auto pos = lower_bound(words.begin(), words.end(), temp, cmp());
		  if (words.size() < k)
		  {
			  words.insert(pos, temp);
			  cur.insert(word);
		  }
		  else
		  {
			  if (pos != words.end())
			  {
				  words.insert(pos, temp);
				  cur.erase(cur.find(words.back().second));
				  words.pop_back();
				  cur.insert(word);
			  }
		  }
		  all[word]++;
	  }

	  /*
	  * @return: the current top k frequent words.
	  */
	  vector<string> topk() {
		  // write your code here
		  vector<string> res;
		  for (auto c : words)
			  res.push_back(c.second);
		  return res;
	  }
	  int k;
	  vector<pair<int, string>> words;//���K(С�ڵ���)������Ƶ����ߵĵ���
	  set<string> cur;//��ŵ�ǰK(С�ڵ���)������Ƶ����ߵĵ���
	  map<string, int> all;//������г��ֵĵ��ʼ�����ִ���
};
#endif