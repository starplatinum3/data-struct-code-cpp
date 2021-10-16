
class Node {
		int id,len;
		bool operator<(const Node &rhs)const {
			return len>rhs.len;
		}

};

void dij() {

	priority_queue<Node>q;
	q.push({st,0});
	dis[st]=0;
	while(!q.empty()) {
		Node fr=q.top();
		q.pop();
		int u=fr.u;
		vis[u]=1;
		for(int v:g[u]) {
			if(vis[v])continue;
//			vis[v]=1;
			if(dis[v]>dis[u]+len[u][v]) {
				dis[v]=dis[u]+len[u][v];
				num[v]=num[u]+1;
				pa[v]=u;
			} else if(	dis[v]==dis[u]+len[u][v]&&
			            num[v]>num[u]+1) {
				num[v]=num[u]+1;
				pa[v]=u;
			}
			q.push({v,dis[v]});
		}
	}

}
