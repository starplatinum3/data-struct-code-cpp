#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

//2
//3 3 0 0
//3 3 3 3欧弟 

void printVec( const vector<ll>& vec){
	for(int i=0;i<vec.size();i++){
		printf("%d ",vec[i]);
	}
	printf("\n");
}
bool judge(ll n, ll k, ll d1, ll d2) {
    if(n % 3 != 0) return false;
    ll residue = n-k;
//    剩下的场次 
    for(int i = 0; i<2; i++) {
        d1 = -d1;
//        相差的分数 
//        两支队伍之间比较 
// n, k, d1, d2(1 <= n <= 10^12; 0 <= k <= n, 0 <= d1, d2 <= k)
//打了0 场次的比赛 
        for(int j = 0; j<2; j++) {
            d2 = -d2;
            vector<ll> v;
            v.push_back(d1);
            v.push_back(d2);
            v.push_back(0);
            sort(v.begin(), v.end());
            printf("一开始\n");
            printVec(v);
            printf("v[0]<0 的时候 不断\n");
            while(v[0] < 0) {
//            	三只球队的分值差距 自己和自己的差距是0 
//            	相差的3分 想要拉回来 
                v[1]+=-v[0], v[2]+=-v[0];
                v[0]+=-v[0];
                printVec(v);
            }
            printVec(v);
//            和分数差距最多的 去拉回来那个差距 
            if(v[2]+v[2]+v[2] > n) {
//            	v[2]累加到最后就是比赛的场次 
            	printf("v[2]的三倍比一共的场次多\n");
            	printf("v[2] %d\n",v[2]);
            	continue;
			}
//			0 0 3 要追平的话  
//  0 和3  需要3分 0和 3 三分
//3*2  
//-3 0 3  
            ll tem = 2*v[2]-v[0]-v[1];
//            就是 v[2] -v[0 ]+v[2]-v[1] 
            if(residue >= tem) {
//            	剩下的场次 大于
//三的倍数 
//如果%3 的话 就是打假赛就行了 反正已经平了 
//1 1 1 
//互相打一下 每个队伍都赢一次  
                if((residue-tem) % 3 == 0) return true;
            }
        }
    }
    return false;
}
int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    ll n, k, d1, d2;
    for(int i = 0; i<t; i++) {
        cin >> n >> k >> d1 >> d2;
        judge(n, k, d1, d2) ? cout << "yes\n" : cout << "no\n";
    }
    return 0;
}
