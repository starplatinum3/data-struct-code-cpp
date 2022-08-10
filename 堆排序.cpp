#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

// https://blog.csdn.net/weixin_44536804/article/details/123398989
int n, m;
int h[N], siz;
// 实现某个节点往下调整的函数 交换后继续下沉该节点直至最后堆稳定
void down(int x)
{
	int min_id = x;
	// 找父节点和子节点（如果存在的话）中的最小值
	if(x * 2 <= siz && h[x * 2] < h[min_id]) min_id = x * 2;
	if(x * 2 + 1 <= siz && h[x * 2 + 1] < h[min_id]) min_id = x * 2 + 1;
	// 如果当前节点x不是最小的话，就交换节点值变成最小的
	if(min_id != x)
	{
		swap(h[x], h[min_id]);
		down(min_id);
	}

	
}
int main()
{
	cin >> n >> m;
	//这里必须从1开始存储，不然父节点i的左右节点不遵从2*i或者2*i+1
	for(int i = 1; i <= n; i ++) cin >> h[i];
	siz = n;
	// 堆的建立，从最后一个非叶子节点开始往下down 思考：为什么从这里开始往下down？
	for(int i = n / 2; i > 0; i --) down(i);

	while(m --)
	{
		cout << h[1] << ' ';
		// 删除堆顶元素
		h[1] = h[siz];
		siz --;
		down(1);
	}
	

	
	return 0;
}
