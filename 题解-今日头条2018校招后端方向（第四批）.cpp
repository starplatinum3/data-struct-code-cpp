//题解-今日头条2018校招后端方向（第四批）

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int count[50005];
int n,m;
int ans=0;
 
//检查当前区间长度(step)是否能在 m 个步骤内实现全 a 或 全 b 
bool func(int step){
    for(int i=0;i+step<n;i++){
//    	操作次数 m  
//    	(count[i+step]-count[i-1]) a 的个数 
        if(m>=step+1-(count[i+step]-count[i-1]))return true;
			//检查 a  公式 m>=区间内 b 的个数 
		if(m>=count[i+step]-count[i-1])return true;	
		//检查 b  公式： m>=区间内 a 的个数 
    }
    return false;
}
 
 
int main(){
    cin>>n>>m;
    string str;
    cin>>str;
    //输入并计算出 count 数组 
    int sum=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='a')count[i]=++sum;
        else count[i]=sum;
    }
 
    //二分搜索最大区间值 
	int l=0,r=n-1,mid; 
    while(l<r){
//    	可以就扩大 
        mid=l+(r-l)/2;
        if(func(mid)){
            l=mid+1;
        }else r=mid;
    }
    ans=max(ans,l);
     
    cout<<ans<<endl;
    return 0;
     
}
