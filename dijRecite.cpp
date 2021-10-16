int dis[n];
int getMinDisPo(){
	int v=-1;
	int minDis=INF;
	for(int i=0;i<n;i++){
		if(vis[i]==0&&dis[i]<minDis){
			minDis=dis[i];
			v=i;
		}
	}
	return v;
}
void suoxiao(int v){
	for(int  u=0;u<n;u++){
		dis[u]=min(dis[u],dis[v]+len[v][u]);
	}
}

//对吗 应该对的吧 
void dij(){
//	vis[s]=1;

	 for(int i=0;i<n;i++){
	 	dis[i]=g[s][i];
	 }
	 dis[0]=0; 
	 for(int i=0;i<n;i++){
	 	int v=getMinDisPo();
	 	if(v==-1)break;
	 	vis[v]=1;
	 	suoxiao(v);
	 }
}


struct Node{
	int id,w;
	bool operate<  (const Node &ano) const{
		return w<ano.w;
	}
};

//错的 
void dijPrio(){
	priority_queue<Node>q;
	q.push(Node(0,0));
	while(!q.empty()){
		Node tp=q.top();
		q.pop();
		int v=tp.id;
		vis[v]=1;
		for(u=0;u<n;u++){
			if(dis[u]>dis[v]+len[v][u]){
				dis[u]=dis[v]+len[v][u];
				q.push(Node(u,dis[u]));
			}
//			dis[u]=min(dis[u],dis[v]+len[v][u]);
		}
		
	}
	 
}
//对的 应该 
void dijPrio(){
	memset(vis,0,sizeof(vis));
	
	priority_queue<Node>q;
	q.push(Node(s,0));
	dis[s]=0;
	 while(!q.empty()){
	 	int u=q.top().id;
	 	q.pop();
	 	if(vis[u])continue;
	 	vis[u]=1;
	 	for(int v=0;v<n;v++){
	 		if(dis[v]>dis[u]+len[u][v]){
	 			dis[v]=dis[u]+len[u][v];
	 			if(!vis[v]){
	 				q.push(Node(v,dis[v]));
				 }
			 }
		 }
	 }
}
