//
// Created by Lenovo on 2020/12/10.
//
#include <stdio.h>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct student{
    string num;
    int score;
    int testPoint;
    int rank;
    int testPointRank;
    bool operator < (const student &a)const{
        return score>a.score;
    }
};
vector<student> putTestPointRank(vector<student> studentsInAPoint){
   int rank=1;
    studentsInAPoint[0].rank=1;
   for(int i =1 ;i<studentsInAPoint.size();i++){
       if(studentsInAPoint[i].score==studentsInAPoint[i-1].score){
           studentsInAPoint[i].testPointRank=rank;
       }else{
           studentsInAPoint[i].testPointRank=++rank;
       }

   }
    return studentsInAPoint;
}

vector<student> putRank(vector<student> studentsInAPoint){
    int rank=1;
    studentsInAPoint[0].rank=1;
    for(int i =1 ;i<studentsInAPoint.size();i++){
        if(studentsInAPoint[i].score==studentsInAPoint[i-1].score){
            studentsInAPoint[i].rank=rank;
        }else{
            studentsInAPoint[i].rank=++rank;
        }

    }
    return studentsInAPoint;
}

void ptaRank(){
    int n;
    scanf("%d\n",&n);
//    student students[n];
    vector<student>students;
    int total=0;
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        student student;
//        struct student studentsInAPoint[k];
        vector<struct student> studentsInAPoint;
//        int studentsInAPointCnt=0;
        for(int j=0;j<k;j++){
            cin>>student.num>>student.score;
//            students[total++]=student;
//            students.emplace_back(student);
//            studentsInAPoint[studentsInAPointCnt++]=student;
            studentsInAPoint.emplace_back(student);
//            scanf("%")
        }
        sort(studentsInAPoint.begin(),studentsInAPoint.end());
        studentsInAPoint=putTestPointRank(studentsInAPoint);
        for(struct student s:studentsInAPoint){
            students.emplace_back(s);
        }
    }
    sort(students.begin(),students.end());
    students=putRank(students);
    printf("%d\n",students.size());
    for(student s:students){
        cout<<s.num<<" "<<s.rank<<" "<<
        s.testPoint<<" "<<s.testPointRank<<"\n";
    }
}

