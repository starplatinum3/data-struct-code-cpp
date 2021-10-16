#include<bits/stdc++.h>
using namespace std;
int n;
int allsh=-1,allsm=-1,allss=-1,alleh=-1,allem=-1,alles=-1;
string allSId,allEId;
void maxTime(int hour,int minute,int sec,string id) {
//	printf("=======\n");
//	printf("max time end, %d:%d:%d\n",hour,minute,sec);
	if(alleh==-1) {
		alleh=hour;
		allem=minute;
		alles=sec;
		allEId=id;
		return;
	}
	if(hour>alleh) {
		alleh=hour;
		allem=minute;
		alles=sec;
		allEId=id;
	} else if(hour==alleh) {
		if(minute>allem) {
			alleh=hour;
			allem=minute;
			alles=sec;
			allEId=id;
		} else if(minute==allem) {
			if(sec>alles) {
				alleh=hour;
				allem=minute;
				alles=sec;
				allEId=id;
			}
		}
	}
}

void minTime(int hour,int minute,int sec,string id) {
//	printf("=======\n");
//		printf("min time start, %d:%d:%d\n",hour,minute,sec);
//		cout<<"min time id: "<<id<<"\n";
	if(allsh==-1) {
		allsh=hour;
		allsm=minute;
		allss=sec;
		allSId=id;
		return;
	}
	if(hour<allsh) {
		allsh=hour;
		allsm=minute;
		allss=sec;
		allSId=id;
	} else if(hour==allsh) {
		if(minute<allsm) {
			allsh=hour;
			allsm=minute;
			allss=sec;
			allSId=id;
		} else if(minute==allem) {
			if(sec<allss) {
				allsh=hour;
				allsm=minute;
				allss=sec;
				allSId=id;
			}
		}
	}
}

int main() {
	scanf("%d",&n);
	getchar();
	for(int i=0; i<n; i++) {
		string id;
		cin>>id;
//		cout<<"id: "<<id<<"\n";
		int sh,sm,ss;
		int eh,em,es;
		scanf("%d:%d:%d %d:%d:%d", &sh,&sm,&ss, &eh,&em,&es);

		minTime(sh,sm,ss,id);
		maxTime(eh,em,es,id);

	}
//	cout<<"star: "<<allSId<<"\n";
//		cout<<"end : "<<allEId<<"\n";
		
	cout<<allSId<<" "<<allEId<<"\n";
}
