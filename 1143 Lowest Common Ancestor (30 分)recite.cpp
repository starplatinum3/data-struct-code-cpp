

int n,m;
const int N=1e4+8;
int pre[N]; 
map<int,int>mp;
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		 cin>>pre[i];
		 mp[pre[i]]=1;
	}
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
			int a;
		for(int j=0;j<n;j++){
			 a=pre[j];
			if((a<u&&a>v)||(a>u&&a<v)||(a==u)||(a==v))
			{
				break;
			}
		}
		if(mp)
		if((a<u&&a>v)||(a>u&&a<v)){
			printf("LCA of %d and %d is %d.\n",u,v,a);
		}else if((a==u)||(a==v)){
			printf("8 is an ancestor of 7.\n",u,v,a);
		}
	}
	
}
