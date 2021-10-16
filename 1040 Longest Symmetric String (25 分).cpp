#include<iostream>
#include<algorithm>
#include<string>
//1040 Longest Symmetric String (25 分)
//https://blog.csdn.net/weixin_42582136/article/details/90291680
using namespace std;
int func(string& s, int left, int right)
{
	while (left >= 0 && right < s.size() && s[left] == s[right])
	{
		left--;
		right++;
	}
//	中间一个拓展 
//1 2 3 4 5 6
//2 4
//4-2==2 ，为什么不是 +1  
//1 2 3 2 5 6
//因为 2 一样 会再往外扩散
 //1 2 3 2 5  这个时候才停止
// 就是 5-1-1==3 
//1 2 3 2 5
//0 1 2 3 4
//2 - (3-1)/2
	return right - left - 1;
}
int longestPalindrome(string s) {
	if (s == "")
		return 0;
	int Max = 0,start, end;
	for (int i = 0; i < s.size(); i++)
	{
		int len = max(func(s, i, i), func(s, i, i + 1));
		if (len > Max)
		{
			Max = len;
			start = i - (len - 1) / 2;
			end = i + len / 2;
			printf("len start end, %d %d %d\n",len,start,end);
		}
	}
	return end - start + 1;
}
int main()
{
	string str;
	getline(cin, str);
	cout << longestPalindrome(str);
	return 0;
}

