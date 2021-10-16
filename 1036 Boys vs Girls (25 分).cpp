//1036 Boys vs Girls (25 ·Ö)
#include<bits/stdc++.h>
using namespace std;
class Person {
	public:
		string na,se, num;
		int sc;
		Person(string na,string se,string num,int sc) :
			na(na),se(se),num(num),sc(sc) {
		}
		Person() {
		}
};
bool cmpMa(Person a ,Person b) {
	return 	a.sc<b.sc;
}
bool cmpFema(Person a ,Person b) {
	return 	a.sc>b.sc;
}
vector<Person>mas;
vector<Person>femas;
int n;
int main() {
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		string na,se, num;
		int sc;
		cin>> na>>se>>num>>sc;
		Person p=Person(na,se,num,sc);
		if(se=="M") {
			mas.push_back(p);
		} else {
			femas.push_back(p);
		}
	}

	sort(mas.begin(),mas.end(),cmpMa);
	sort(femas.begin(),femas.end(),cmpFema);

	int NA=0;

	if(femas.size()==0) {
		printf("Absent\n");
		NA=1;
	} else {
		cout<<femas[0].na<<" "<<femas[0].num<<"\n";
//			for(auto p: mas){
//				cout<<p.na<<" "<<p.num<<"\n";
//			}
	}



	if(mas.size()==0) {
		printf("Absent\n");
		NA=1;
	} else {
		cout<<mas[0].na<<" "<<mas[0].num<<"\n";
//			for(auto p: mas){
//				cout<<p.na<<" "<<p.num<<"\n";
//			}
	}


	if(NA) {
		printf("NA\n");
	} else {
		cout<<	femas[0].sc-mas[0].sc<<"\n";
	}

}
