
int st,en;
void dfs(int u){
	if(en==u){
		for(int v:pa){
			
		}
	}
	for(int v:g[u]){
		if(vis[v])continue;
		pa.push_back(v);
		dfs(v);
		pa.pop_back();
	}
} 

int build(int ml,int mr,int pl,int pr)
{
	
	
	if(mr<ml){
		return -1;
	}
	
	if(mr-ml==0){
		return m[ml]
	}
	
	
	int pos;
	int root=pr;
	for(int i=ml;i<=mr;i++){
		if(m[i]==p[pr]){
			pos=i;
			break;
		}
	}
	t[root].l=build(ml,pos-ml,pl,pl+pos-ml-1);
	t[root].r=build(pos+1,mr-1,pl+pos-ml,por-1);
	return root;
	
}
int main(){
	pa.push_back(st);
	dfs(st);
}
