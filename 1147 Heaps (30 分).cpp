//1147 Heaps (30 ��)
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int>v;
int fir=1;
//��Ϊ����ȫ�� ���Կ������±� 
//https://blog.csdn.net/shshbdhsjjd/article/details/113976754
//��������ҿ��������֪���� 
void post(int idx){
	if(idx>=m){
		return ;
	}
	post(idx*2+1);
	post(idx*2+2);
	if(fir)fir=0;
	else printf(" ");
	printf("%d",v[idx]);
	
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		v.clear();
		for(int j=0; j<m; j++) {
			int x;
			scanf("%d",&x);
			v.push_back(x);

		}
		vector<int>maxH=v;
		vector<int>minH=v;
//		ֱ����  make_heap �Ͳ��ñ� heap �Ĵ����� 
		make_heap(maxH.begin(),maxH.end());
		make_heap(minH.begin(),minH.end(),greater<int>() );
		if(maxH==v) {
			cout<<"Max Heap\n";
		} else if (minH==v) {
			cout<<"Min Heap\n";
		}
		else {
			cout<<"Not Heap\n";
		}
		fir=1;
		post(0);
		printf("\n");
	}
}
