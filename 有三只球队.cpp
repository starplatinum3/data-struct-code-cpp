#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

//2
//3 3 0 0
//3 3 3 3ŷ�� 

void printVec( const vector<ll>& vec){
	for(int i=0;i<vec.size();i++){
		printf("%d ",vec[i]);
	}
	printf("\n");
}
bool judge(ll n, ll k, ll d1, ll d2) {
    if(n % 3 != 0) return false;
    ll residue = n-k;
//    ʣ�µĳ��� 
    for(int i = 0; i<2; i++) {
        d1 = -d1;
//        ���ķ��� 
//        ��֧����֮��Ƚ� 
// n, k, d1, d2(1 <= n <= 10^12; 0 <= k <= n, 0 <= d1, d2 <= k)
//����0 ���εı��� 
        for(int j = 0; j<2; j++) {
            d2 = -d2;
            vector<ll> v;
            v.push_back(d1);
            v.push_back(d2);
            v.push_back(0);
            sort(v.begin(), v.end());
            printf("һ��ʼ\n");
            printVec(v);
            printf("v[0]<0 ��ʱ�� ����\n");
            while(v[0] < 0) {
//            	��ֻ��ӵķ�ֵ��� �Լ����Լ��Ĳ����0 
//            	����3�� ��Ҫ������ 
                v[1]+=-v[0], v[2]+=-v[0];
                v[0]+=-v[0];
                printVec(v);
            }
            printVec(v);
//            �ͷ���������� ȥ�������Ǹ���� 
            if(v[2]+v[2]+v[2] > n) {
//            	v[2]�ۼӵ������Ǳ����ĳ��� 
            	printf("v[2]��������һ���ĳ��ζ�\n");
            	printf("v[2] %d\n",v[2]);
            	continue;
			}
//			0 0 3 Ҫ׷ƽ�Ļ�  
//  0 ��3  ��Ҫ3�� 0�� 3 ����
//3*2  
//-3 0 3  
            ll tem = 2*v[2]-v[0]-v[1];
//            ���� v[2] -v[0 ]+v[2]-v[1] 
            if(residue >= tem) {
//            	ʣ�µĳ��� ����
//���ı��� 
//���%3 �Ļ� ���Ǵ���������� �����Ѿ�ƽ�� 
//1 1 1 
//�����һ�� ÿ�����鶼Ӯһ��  
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
