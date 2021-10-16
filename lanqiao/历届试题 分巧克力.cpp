#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
// https://blog.csdn.net/weixin_39739342/article/details/88635779
int main()
{
	int N,K;
	int i,j,h,w,max_k=0,key=0;
	int result[100005]={0};
    scanf("%d %d",&N,&K);
    for(i=0;i<N;i++){
    	scanf("%d %d",&h,&w);
    	int sam=min(h,w);
    	max_k=max(max_k,sam);
        // 最大的小边
        // 比如 1  5， 3 4 
        // 小边是 1  3
        // 最大的就是3 ，尽量是取得小边大的巧克力，1 5 也许可以舍弃
    	for(j=sam;j>=1;j--){
    		result[j]+=(h/j)*(w/j);
            // 分成 j 边长的方块的话，会有多少个呢	result[j]
    		if(j<=key)break;
            // j 枚举的是边， 如果这个边小了，那就是巧克力小了，小朋友们肯定不愿意
    		if(result[j]>K){
                // 个数 比需要的多
    			key=j;
    			break;
    		}
    	}
    }
    for(i=max_k;i>0;i--){
        // 切得最大的
    	if(result[i]>=K){
    		printf("%d\n",i);
    		break;
    	}
    }
    return 0;
}