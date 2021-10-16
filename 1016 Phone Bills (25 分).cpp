#include<bits/stdc++.h>
using namespace std;
int recCnt;
int toll[33];
int dayToll=0;
typedef long long ll;
long long sumToll[33];
ll sum(int l,int r) {
	return sumToll[r]-sumToll[l-1];
}
/*
// 模拟
// CYLL 01:01:06:01 on-line
// CYLL 01:28:16:05 off-line
// 27day 10 h 4 minute
// 2 --27 cents *25
// 6*60+1 minute  24*60+0 m
// 24-6 )*
// for (int i=6;i<24;i++)
// sum+= toll[i]*60;
// sum(6+1,24-1)*60  +cent[6]*1
// sum(0,16-1)*60+5*cents[16]
// 6 *cent[6] ,7 cent[7] 。。。16* cent[16]  - 1*cent[6]- (60-5)*cent[16]
//  假如都是 1 day ，。

// 2--27 完整的
// 28-1 -2 ==25

// 6 :01  59 59* cent[6]  6--7
// 7 cent[7]
// ...
//  cent [23]

// cent[0]*60 cent[1] *60 +c... cent[15] .. <=(16-1
// cent[16]* (05-1

// cnet[0] cent[1]   cnet[6]
//  0--1   1---2    ... 6--7

*/
set<string>nameSet;

class TmpRec {
     public:
		int mon;
		int day,h,m;
		TmpRec(int _mon, int _day, int _h,int _m ) {
			mon=_mon;
			day=_day,h=_h,m=_m;
		}
//     int stH,stM,enH,enM;
}
map<string,TmpRec>mp;

class Record {
     public:
		int mon;
		int stD,enD;
		int stH,stM,enH,enM;
		int passMi;
		ll pay;
		Record( int _mon, int _stD,int  _stH, int _stM  ,int  _enD,int _enH,int _enM) {
			mon=_mon;
			stD=_stD;
			enD=_enD;
			stH=_stH;
			stM=_stH;
			enH=_stH;
			enM=_stH;
			calPay();
			calPassMi();
		}
		ll stTimeCalToll() {
			return   sum(stH+1,24-1)*60  +toll[stH]*stM ;
		}
		ll endTimeCalToll() {
			return  sum(0,enH-1)*60+enM*toll[16];
		}
//     void printRecords(){
//         for(int i=0;i<)
//     }
		void print() {
			printf("%d:%d:%d %d:%d:%d %d $%.2f\n",stD,stH,stM,enD,enH,enM,passMi,pay);
		}
		void calPassMi() {
			int stFormMi=stD*3600+stH*60+stM;
			int endFormMi=enD*3600+enH*60+enM;
			passMi=endFormMi-stFormMi;
		}
		void calPay() {
			ll sum=0;
			sum+=(enD-stD-2)*dayToll;
			sum+=stTimeCalToll()+endTimeCalToll();
//         for(int i=stH;i<enH;i++){
//             sum+=toll[i]*60;
//         }
//         sum-=stM*toll[stH];
//         sum+=enM*toll[enH];
			pay=sum;
		}
};


class Person {
    public:
		string name;
	static	const int MAX_REC_CNT=111;
		Record records[MAX_REC_CNT];
		int recCnt=0;
		ll totPay=0;
		void calTotPay() {
//         ll sum=0;
			for(int i=0; i<recCnt; i++) {
				totPay+=records[i].pay;
			}
		}
		void add(Record rec) {
			records[recCnt++]=rec;
		}
		Person(string _name) {
			name=_name;
		}
		void print() {
			cout<<name;
			printf(" %02d\n",mon);
			for(int i=0; i<recCnt; i++) {
				records[i].print();
			}
			printf("Total amount: $%.2lf\n",totPay);
		}
};

map<string,Person>mpP;


int main() {
	for(int i=0; i<24; i++) {
		scanf("%d",toll+i);
		if(i>=1) {
			sumToll[i]=sumToll[i-1]+toll[i];
		}
		dayToll+=toll[i]*60;
	}

	scanf("%d",&recCnt);
	for(int i=0; i<recCnt; i++) {
		string name;
		int mon;
//     int stD,enD;
//     int stH,stM,enH,enM;
		int day,h,m;
		string op;
		cin>>name;
		scanf("%d:%d:%d:%d",&mon,&day,&h,&m);
		cin>>op;
		if(op=="on-line") {
			mp[name]=TmpRec(mon,day,h,m);
			nameSet.push(name);
		} else {
//             if(nameSet.contains(name)){
//             mp[name]
//         }
			TmpRec tmpRec=mp[name];
			if(tmpRec==nullptr) {
				continue;
			} else {
//                 new Recode 的同时 就算了 pay
				Record rec=Record(mon,tmpRec.day,tmpRec.h,tmpRec.m, day,h,m);
				auto per=  mpP[name];
				if(per==nullptr) {
					mp[name]=Person(name);
				} else {
					mpP[name].add(rec);
				}


			}

		}

	}
	for(auto name:mpP) {
		auto p= mpP[name];
		p.calPay();
		p.print();
	}
}
