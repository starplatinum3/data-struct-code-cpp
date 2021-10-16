//1057 Stack (30 分)
#include <bits/stdc++.h>

using namespace std;
const int MAX_CNT = 111111;
const int INF = 0x3f3f3f3f;
int a[MAX_CNT];
int bit[MAX_CNT];

int lowbit(int x) {
    return x & (-x);
}

//应该是 max 也没事， 因为后面都没有数字 都是乱的
//随便加上也没事吧  不知道， 因为求和的时候也没加上嘛 
int add(int x, int index) {
    for (; index <= MAX_CNT; index += lowbit(index)) {
        bit[index] += x;
    }
}

int sum(int idx) {
    int sumRes = 0;
    for (; idx > 0; idx -= lowbit(idx)) {
//		bit[index]+=x;
        sumRes += bit[idx];
    }
    return sumRes;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

list<int> fr;
list<int> ba;

int cntOp;
vector<int> st;
vector<int> vals;

int medVal() {
//	return vals[]
}

class BaseHolder {
public:
    virtual ~BaseHolder() {}
};

template<typename T>
class Holder : public BaseHolder {
public:
private:
    T _data;
};

//作者：黄兢成
//        链接：https://www.zhihu.com/question/33594512/answer/56973726
//来源：知乎
//        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <memory>

//vector<std::shared_ptr>res;
string res;
 int get(int idx){
 	int ans;
 	int l,r=MAX_CNT;
 	l=0;
 	while(l<=r){
 		int mid=(l+r)/2;
 		if(sum(mid)>=idx){
 			ans=mid;
 			r=mid-1;
		 }else{
		 	l=mid+1;
		 }
	 }
	 return ans;
 } 
int main() {
    scanf("%d", &cntOp);
//    vals.push_back(-1);
    for (int i = 0; i < cntOp; i++) {
        string op;

        cin >> op;
        if (op == "Pop") {
            if (st.size() == 0) {
                cout << "Invalid\n";
//                res += "Invalid\n";
//                res += "\n";
            } else {
                cout << st.back() << "\n";
//                res.push_back(st.back());
//                res += std::to_string(st.back());
//                res += "\n";
//                add(st.back(),-1);
                 add(-1,st.back());
//                 参数写反了 
                st.pop_back();
//                vals.pop_back();
            }
        } else if (op == "PeekMedian") {
            if (st.size() == 0) {
                cout << "Invalid\n";
//                res += "Invalid\n";
//                res += "\n";
            } else {
//                0 1 2 3 4 5
//6/2 ==3  (6-1)/2== 2
//                value is defined to be the (N/2)-th smallest element
//                if N is even, or ((N+1)/2)-th if N is odd.
//                int idx = (vals.size() & 1) ? ((vals.size() + 1) / 2) : vals.size() / 2;
//                int siz = vals.size() - 1;
                int siz=st.size();
//                int idx = (vals.size() & 1) ? ((vals.size() + 1) / 2) : vals.size() / 2;
//                int idx = (siz & 1) ? ((siz + 1) / 2) : siz/ 2;
//                idx--;
//                sort(vals.begin() + 1, vals.end());
//
//                cout << vals[idx] << "\n";
                cout<<get((siz+1)/2)<<"\n";
//                res.push_back(vals[(vals.size()-1)/2]);
//                res += std::to_string(vals[(vals.size() - 1) / 2]);
//                res += "\n";
            }
        } else if (op == "Push") {
            int val;
            cin >> val;
//            add(val,1);
              add(1,val);
            st.push_back(val);
//            vals.push_back(val);
        }
    }

//    cout<<res<<"\n";
} 
