
#include<bits/stdc++.h>
using namespace std;

int m,n;
class Per {
	public:
		string num;
		int sc;
		char lev;
		string siNum;
		string date;
		string snum;
		Per(string num,int sc):
			num(num),sc(sc) {
			lev=num[0];
			siNum=num.substr(1,3);
			date=num.substr(4,6);
			snum=num.substr(10,3);
		}
		Per() {
		}

		void print() {
//			cout<<num<<"\n";
			printf("%s\n",num.c_str());
		}
};
vector<Per>pers;
bool cmpLev(Per p1,Per p2) {
	if(p1.sc!=p2.sc) {
		return p1.sc>p2.sc;
	}
	return p1.num<p2.num;
}
void levPer(char lev) {
	vector<Per>levPers;
	for(auto p:pers) {
		if(p.lev==lev) {
//			p.print();
			levPers.push_back(p);
		}
	}
	if(levPers.empty()) {
//		cout<<"NA\n";
		printf("NA\n");
		return ;
	}
	sort(levPers.begin(),levPers.end(),cmpLev);

	for(auto p:levPers) {
//		cout<<p.num<<" "<<p.sc<<"\n";
		printf("%s %d\n",p.num.c_str(),p.sc);
	}
}

void sitePer(string siNum) {
//		vector<Per>sitePers;
	int cnt=0;
	int sum=0;
	int ha=0;
	for(auto p:pers) {
//		cout<<"p.site: "<<p.siNum<<"\n";
		if(p.siNum==siNum) {
//			sitePers.push_back(p);
//			p.print();
			cnt++;
			sum+=p.sc;
			ha=1;
		}
	}
	if(!ha) {
//			cout<<"NA\n";
		printf("NA\n");
		return ;
	}
	printf("%d %d\n",cnt,sum);
}

bool cmpDate(pair<string,int>p1,pair<string,int>p2) {
	if(p1.second!=p2.second) {
		return p1.second>p2.second;
	}
	return  stoi(p1.first)<stoi(p2.first);
}

void 	datePer(string date) {
//	map<string,int>mp;
	unordered_map<string,int>mp;
//	https://blog.csdn.net/liuchuo/article/details/84973049
//柳神 
//多交几次 就过了 
	vector<pair<string,int> >datePers;
	for(auto p:pers) {
		if(p.date==date) {
			mp[p.siNum]++;
		}
	}
	for(auto p:mp) {
		datePers.push_back(make_pair(p.first,
		                             p.second));
	}

	if(datePers.empty()) {
//		cout<<"NA\n";
		printf("NA\n");
		return ;
	}
	sort(datePers.begin(),datePers.end(),cmpDate);
//	printf("%d %d\n",cnt,sum);
	for(auto p:datePers) {
//		printf("%d %d\n",p.first,p.second);
//		cout<<p.first<<" "<<p.second<<"\n";
		printf("%s %d\n",p.first.c_str(),p.second);
	}
}
int main() {
//	ios::sync_with_stdio(false);
	scanf("%d%d",&m,&n);
	getchar();
	for(int i=0; i<m; i++) {
		string num;
		int sc;
//		cin>>num;
		char numC[111];
		scanf("%s",numC);
		num=string(numC);
		scanf("%d",&sc);
		pers.emplace_back(num,sc);

	}
//	printf("read  \n");
	for(int i=1; i<=n; i++) {
		int ty;
//		cin>>ty;
		scanf("%d",&ty);
		if(ty==1) {
			char lev;
//			cin>>lev;
			scanf(" %c",&lev);
			printf("Case %d: %d %c\n",i,ty,lev);
			levPer( lev);
		} else if(ty==2) {
			string siNum;
			char si[11];
//			cin>>siNum;
			scanf(" %s",si);
			siNum=string(si);
			printf("Case %d: %d ",i,ty);
//			cout<<siNum<<"\n";
			printf("%s\n",siNum.c_str());
			sitePer(siNum);
		} else if(ty==3) {
			string date;
//			cin>>date;
			char da[111];
			scanf(" %s",da);
			date=string(da);
			printf("Case %d: %d ",i,ty);
//			cout<<date<<"\n";
			printf("%s\n",date.c_str());
			datePer(date);
		}
	}
}
