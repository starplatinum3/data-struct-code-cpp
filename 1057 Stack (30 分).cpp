//1057 Stack (30 分)
#include <bits/stdc++.h>
using namespace std;
const int MAX_CNT=111111;
const int INF=0x3f3f3f3f;
int a[MAX_CNT];
int bit[MAX_CNT];
int lowbit(int x){
	return x&(-x);
}
//应该是 max 也没事， 因为后面都没有数字 都是乱的
//随便加上也没事吧  不知道， 因为求和的时候也没加上嘛 
int add(int x,int index){
	for(;index<=MAX_CNT;index+=lowbit(index)){
		bit[index]+=x;
	}
}

int sum(int idx){
	int sumRes=0;
		for(;idx>0;idx-=lowbit(idx)){
//		bit[index]+=x;
		sumRes+=bit[idx];
	}
	return sumRes;
}
int sum(int l,int r){
	return sum(r)-sum(l-1);
} 
list<int>fr;
list<int>ba;

int cntOp;
vector<int>st;
vector<int>vals;
int medVal(){
//	return vals[]
}

//class Value
//{
//public:
//    Value();
//    Value(int val);
//    Value(const std::string& val);
//
//    bool isString() const;
//    bool isInt() const;
//
//    const std::string& string() const;
//    uint32_t uint32() const;
//
//private:
//    boost::variant<int, std::string> _data;
//};

//作者：黄兢成
//链接：https://www.zhihu.com/question/33594512/answer/56973726
//来源：知乎
//著作权归作者所有。商业转载请


//联系作者获得授权，非商业转载请注明出处。


vector<Value>res;
int main(){
	scanf("%d",&cntOp);
	for(int i=0;i<cntOp;i++){
		string op;
		
		cin>>op;
		if(op=="Pop"){
			if(st.size()==0){
				cout<<"Invalid\n";
			}else{
				cout<<st.back()<<"\n";
				res.push_back(st.back());
								st.pop_back();
				vals.pop_back(); 
			}
		}else if(op=="PeekMedian"){
				if(st.size()==0){
				cout<<"Invalid\n";
			}else{
				cout<<vals[(vals.size()-1)/2]<<"\n";
				res.push_back(vals[(vals.size()-1)/2]);
			}
		}else if(op=="Push"){
			int val;
			cin>>val;
			st.push_back(val);
			vals.push_back(val);
		}
	}
} 
