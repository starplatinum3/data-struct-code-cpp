#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
clock_t start,end;
 
int main(){
	start=clock();		//����ʼ��ʱ
	int ans=0;
	for(int i=1;i<=1e8;i++)
		ans++;
	end=clock();		//���������ʱ
	double endtime=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"Total time:"<<endtime<<endl;		//sΪ��λ
	cout<<"Total time:"<<endtime*1000<<"ms"<<endl;	//msΪ��λ
	system("pause");
	return 0;
}
