#include<bits/stdc++.h>
using namespace std;
class Time{
    public:
    int h,m,s;
    int formSec;
    Time( int h, int m,int s){
        this->h=h;
        this->m=m;
        this->s=s;
        makeFormSec();
    }
    void makeFormSec(){
        formSec=h*3600+m*60+s;
    }
    int getFormSec() const{
//         formSec=h*3600+m*60+s;
        return formSec;
    }
    bool operator<(const Time &rhs) const{
        return getFormSec()<rhs.getFormSec();
    }
    
        bool operator>(const Time &rhs) const{
        return rhs<*this;
    }
};

class Person{
    public:
//     int h,m,s;
    Time time;
    int spe;
    int need;
    Person(){}
    Person(  int h, int m,int s,
    int spe){
        this->time=Time(h,m,s);
//         this->h=h;
//         this->m=m;
        this->spe=spe;
        this->need=spe;
//         this->s=s;
    }
    bool operator<(const Person& rhs) const{
        return time<rhs.time;
    }
};
int cntPer,cntWin;
const int MAX_Q_CNT=111;
queue<Person>q[MAX_Q_CNT];
vector<Person>pers;
int totWait=0;
void deQ(){
    for(int i=0;i<cntWin;i++){
        if(q[i].size()){
            Person fr= q[i].front();
            fr.need--;
//             柜台的++ 黄线外的也要++
            totWait++;
//             不管有没有做操作， 这个人总是等着了
            if(fr.need==0){
                q[i].pop();
            }
        }
    }
    
    totWait+=pers.size();
}

void enQ(){
    for(int i=0;i<cntWin;i++){
        if(q[i].empty()){
            if(pers.empty())continue;
            q[i].push(pers.front());
            pers.pop_front();
        }
    }
}
int main(){
    scanf("%d%d",&cntPer,&cntWin);
    Time endTime=Time(17,0,0);
     Time stTime=Time(8,0,0);
    for(int i=0;i<cntPer;i++){
     int h,m,s;
    int spe;
    scanf("%d:%d:%d %d", &h,&m,&s,&spe);
        Person per=Person(h,m,s,spe);
        if(per.time>endTime)continue;
//      pers.emplace_back(h,m,s,spe);
        pers.push_back(per);
    }
    int oriPerCnt=pers.size();
    sort(pers.begin(),pers.end());
    for(auto per:pers){
        
    }
    int stSec=pers.time.getFormSec();
//         for(int t=28800；t<=61200;t++){
    for(int t=stSec;t<=61200;t++){
        enQ();
        deQ();
    }
    printf("%.1lf\n",(double)totWait/oriPerCnt);
    
}
