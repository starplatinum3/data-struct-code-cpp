#include<iostream>
using namespace std;
#include<stack>
#include<map>
 
string s1,s2;//双方（A，B）的牌 
stack<char> st;//双方出的牌 
map<char,bool> mp;//判断牌是否出现相等 
 
int main(){
	cin>>s1>>s2;
	bool f=true;
	while(s1.size()&&s2.size()){//当双方的牌都不为空时: 
		if(f){//f为true时，A方出牌 
			st.push(s1[0]);//A的第一张牌入栈 
			s1.erase(s1.begin());//将A的第一张牌删除 			
			if(mp[st.top()]){//如果这张牌出现过 
			//为了便于理解，我举个例子: 
			// A手中的牌目前为---A6897  , 双方出掉的牌为 ---46576  （这里的6是A刚刚出掉的牌，6之前出现过，所以是被标记过的） 
				char tmp=st.top();//记录这张牌的字符  ---- 6 
				mp[st.top()]=false;//将该张牌取消标记，因为相等的牌要收回 
				s1+=st.top();//将赢得牌拿走 ----A68976 
				st.pop();//该张牌出栈 ------4657
				while(tmp!=st.top()){//如果两张相等的牌之间还有牌  57
					s1+=st.top();  //A689767   A6897675
					mp[st.top()]=false;//将这些被A赢走的牌都取消标记 
                    // 这些标记都是可以取消的吗
                    // 好像是的 因为一旦有重复的，就会被拿走了，所以不会有重复的，
                    // 所以拿走的那些的标记都可以取消了
					st.pop();//465   46
				}
				s1+=st.top();//A68976756
				st.pop();//4
				f=!f;//将f标记为false 跳出 本次循环 轮到B出牌 
			}else{
				mp[st.top()]=true; //将牌标记 
			}
		}else{
			st.push(s2[0]);
			s2.erase(s2.begin());
			if(mp[st.top()]){
				char tmp=st.top();
				mp[st.top()]=false;
				s2+=st.top();
				st.pop();
				while(tmp!=st.top()){
					s2+=st.top();
					mp[st.top()]=false;
					st.pop();
				}
				s2+=st.top();
				st.pop();
				f=!f;
			}else{
				mp[st.top()]=true;
			}
		}
		f=!f;
	}
	if(s1.size()==0){
		cout<<s2<<endl;
	}else{
		cout<<s1<<endl;
	}
	return 0;
}