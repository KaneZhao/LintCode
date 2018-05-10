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
* 最常使用的K个单词II
*
* 描述
* 在实时数据流中找到最常使用的k个单词.
* 实现TopK类中的三个方法:
* TopK(k), 构造方法
* add(word), 增加一个新单词
* topk(), 得到当前最常使用的k个单词.
* 如果两个单词有相同的使用频率, 按字母排序.
* 样例
* TopK(2)
* add("lint")
* add("code")
* add("code")
* topk()
* >> ["code", "lint"]
*/

//构建lower_bound的cmp函数,在降序序列中找到元素的插入位置,若元素的数字相同,字符串按字典序
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
		  //对于单词word,先获取其出现次数,并构建pair
		  auto temp = make_pair(all[word], word);
		  //如果word是前k高频单词,在words和cur中删除word,更新word的出现次数
		  if (cur.find(word) != cur.end())
		  {
			  words.erase(find(words.begin(), words.end(), temp));
			  cur.erase(cur.find(word));
		  }
		  temp.first++;
		  //在新的数组words中寻找temp的插入位置
		  //如果words的长度小于k,直接插入,并将word插入cur中
		  //否则,判断插入位置是否在末尾,不在末尾表示出现次数是前k大的,
		  //将其插入words中,并把words的末尾元素删除,更新cur的值
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
	  vector<pair<int, string>> words;//存放K(小于等于)个出现频率最高的单词
	  set<string> cur;//存放当前K(小于等于)个出现频率最高的单词
	  map<string, int> all;//存放所有出现的单词及其出现次数
};
#endif