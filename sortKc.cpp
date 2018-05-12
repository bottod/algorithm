#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */

/******************************开始写代码******************************/

int calcMinKLenSum(string& first, string& second){
	string final_s = first+second;
	string final_s_all = final_s;//合并后原始值
	sort(final_s.begin(),final_s.end());//排序
	final_s.erase(unique(final_s.begin(),final_s.end()),final_s.end());//去掉重复值
	int score = 0;
	for(int i = 0;i<final_s.size();i++)
	{
		for(int j = 0;j<final_s_all.size();j++)
		{
			if(final_s_all[j] == final_s[i])
				score += 1;
		}
	}
	score = score - final_s.size();
    return score;
}

/******************************结束写代码******************************/

int main() {
    string first, second;
    cin >> first >> second;
    int  sum = calcMinKLenSum(first, second);
    cout << sum << endl;
    return 0;
}