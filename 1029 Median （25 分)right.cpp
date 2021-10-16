#include <stdio.h>
#include <vector>
using std::vector;
vector<int> v;
//https://blog.csdn.net/weixin_43869268/article/details/88524511
int main() {
	int n,m,temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		v.push_back(temp);
	}
	v.push_back(0x7FFFFFFF); //假设比较过程中超出v的范围
	scanf("%d", &m);
	int mid = (m + n + 1) / 2, cnt = 0, k = 0;
	//mid为比较的次数
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		while (v[k]<temp){
			cnt++;
			if (cnt == mid) printf("%d", v[k]);
			k++;
		}
		cnt++;
		if (cnt == mid) printf("%d", temp);
	}
	while (k<n){
		cnt++;
		if (cnt == mid) printf("%d", v[k]);
		k++;
	}
	return 0;
}

