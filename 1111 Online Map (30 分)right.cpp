#include <stdio.h>
#include <string.h>
#define inf 0x3f3f3f3f
int m,n,source,destination,a,b,w,l,t;
int length[501][501],times[501][501],dis[501],
    cost[501],cost1[501],num[501],vis[501],path1[501],path2[501];
void getpath1(int x) {
	if(x != source) {
		getpath1(path1[x]);
		printf(" -> ");
	}
	printf("%d",x);
}
void getpath2(int x) {
	if(x != source) {
		getpath2(path2[x]);
		printf(" -> ");
	}
	printf("%d",x);
}
int equals(int x) {
	if(path1[x] != path2[x])return 0;
	else if(x == source)return 1;
//    比到头 一样 就是一样了
	return equals(path1[x]);
}

//https://www.cnblogs.com/8023spz/p/9300733.html
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			length[i][j] = times[i][j] = inf;
		}
		dis[i] = cost[i] = cost1[i] = inf;
		path1[i] = path2[i] = -1;
	}
	for(int i = 0; i < m; i ++) {
		scanf("%d%d%d%d%d",&a,&b,&w,&l,&t);
		if(w) {
			length[a][b] = l;
			times[a][b] = t;
		} else {
			length[a][b] = length[b][a] = l;
			times[a][b] = times[b][a] = t;
		}
	}
	scanf("%d%d",&source,&destination);
	dis[source] = cost[source] = cost1[source] = 0;
//    cost time
//    cost1 tmp time
	while(1) {
		int t = -1,mi = inf;
		for(int i = 0; i < n; i ++) {
			if(!vis[i] && mi > dis[i]) {
				mi = dis[i];
				t = i;
			}
		}
		printf("t %d\n",t);
		if(t == -1)break;
		vis[t] = 1;
		for(int i = 0; i < n; i ++) {
			if(vis[i] || length[t][i] == inf)continue;
			if(dis[i] > dis[t] + length[t][i]) {
				path1[i] = t;
				dis[i] = dis[t] + length[t][i];
				cost1[i] = cost1[t] + times[t][i];
				printf("len v %d\n",i);
//                这里 cost1 后面就不用了吗
			} else if(dis[i] == dis[t] + length[t][i]
			          && cost1[i] > cost1[t] + times[t][i]) {

				printf("from ");
				printf("cost1[i]  %d to ",cost1[i]);

				cost1[i] = cost1[t] + times[t][i];
//                一样的距离 需要时间少点的
				path1[i] = t;

				printf("cost1[i] %d\n",cost1[i]);
			}
		}
	}
	memset(vis,0,sizeof(vis));
	while(1) {
		int t = -1,mi = inf;
		for(int i = 0; i < n; i ++) {
			if(!vis[i] && mi > cost[i]) {
				mi = cost[i];
				t = i;
			}
		}
		if(t == -1)break;
		vis[t] = 1;
		for(int i = 0; i < n; i ++) {
			if(vis[i] || times[t][i] == inf){
				printf("vis[i] i %d %d\n",vis[i],i);
				printf(" times[t][i]  %d\n", times[t][i] );
				continue;
			}
			if(cost[i] > cost[t] + times[t][i]) {
				path2[i] = t;
				cost[i] = cost[t] + times[t][i];
				num[i] = num[t] + 1;
//                最快的路 要 点数少
				printf(" num[i]  i %d %d \n",num[i],i);
			} else if(cost[i] == cost[t] + times[t][i]
			          && num[i] > num[t] + 1) {
				num[i] = num[t] + 1;
				path2[i] = t;
				printf("num[i] %d\n", num[i]);
			}
		}
	}
	printf("Distance = %d",dis[destination]);
	if(!equals(destination)) {
		printf(": ");
		getpath1(destination);
		printf("\n");
	} else {
		printf("; ");
	}
	printf("Time = %d: ",cost[destination]);
	getpath2(destination);
}
