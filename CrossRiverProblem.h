//
// Created by Lenovo on 2021/1/2.
//

#ifndef DATASTRUCT_CROSSRIVERPROBLEM_H
#define DATASTRUCT_CROSSRIVERPROBLEM_H
//
// Created by Lenovo on 2021/1/2.
//
#include <bits/stdc++.h>

using namespace std;

enum Direction {
    TO, BACK

};

class State {
public:
    bool Man;

    bool Wolf;

    bool Sheep;

    bool Vegetable;

    string Action;
    string mov;

    bool IsOk() {

        if (Wolf == Sheep && Wolf != Man) {
            // wolf和羊都在 但是人不在 会出问题
            return false;
        }

        if (Sheep == Vegetable && Sheep != Man) {
            return false;
        }

        return true;

    }

    State(bool man, bool wolf, bool sheep, bool vegetable) : Man(man), Wolf(wolf), Sheep(sheep), Vegetable(vegetable) {}

    State() {}


    State Copy() {
        return State(Man, Wolf, Sheep, Vegetable);
    }


    bool Equals(const State &newState) {
        return (this->Man == newState.Man
                && this->Wolf == newState.Wolf
                && this->Sheep == newState.Sheep
                && this->Vegetable == newState.Vegetable);
    }


};

class CrossRiverProblem {
    int have = 0;
    int first = 1;
    string endDirection;
    vector<string> movCmdList;
    Direction endDirectionEnum;
    Direction startDirectionEnum;
    State end;
    State start;
    State cur;
    int count = 0;
//    Direction nowDirection;
    vector<State> path;
public:

    Direction reverseDirection(Direction direction) {
        if (direction == TO) {
            return BACK;
        } else {
            return TO;
        }
    }

    void Switch(Direction direction) {

//    auto *pNewState = cur.Copy();
        auto newState = cur.Copy();
        newState.Man = !newState.Man;

//    newState.Action = "独自" + nowDirection;
//    newState.Action
//    makeMovCmd(cur,nowDirection);
//    makeMovCmd(cur, *pNewState, nowDirection);
//    makeMovCmd(cur, nowDirection);
//现在的状态如果是已经过河了的话
//第一步是直接跳过的 所以方向好像和我想的不符合 其实就是反了一下
        Action(newState, direction);


        if (cur.Wolf == cur.Man) {
            // 人和狼都在 一起
            newState.Wolf = !newState.Wolf;
//        newState.Action = "带着狼" + nowDirection;
//        makeMovCmd(cur, *pNewState, nowDirection);
            Action(newState, direction);

//        Action(path, count, *pNewState, end);
            newState.Wolf = !newState.Wolf;
        }

        if (cur.Sheep == cur.Man) {
            newState.Sheep = !newState.Sheep;
//        newState.Action = "带着羊" + nowDirection;
//        makeMovCmd(cur, *pNewState, nowDirection);
            Action(newState, direction);

//        Action(path, count, *pNewState, end);
            newState.Sheep = !newState.Sheep;
        }


        if (cur.Vegetable == cur.Man) {
            newState.Vegetable = !newState.Vegetable;
//        newState.Action = "带着菜" + nowDirection;
//        makeMovCmd(cur, *pNewState, nowDirection);
            Action(newState, direction);

//        Action(path, count, *pNewState, end);
            newState.Vegetable = !newState.Vegetable;
        }
    }

    void Action(State newState, Direction direction) {
        if (newState.IsOk()) {
            for (auto item:path) {
                if (item.Equals(newState)) {
                    // 不能有相同的状态
                    return;
                }
            }


//        makeMovCmd(oldState, newState, action);
//        makeMovCmd(newState, action);
//        Search(path,count);
//            nowDirection= reverseDirection(nowDirection);
            makeMovCmd(newState, reverseDirection(direction));
            path.push_back(newState);

            Search();
//            Search(path, count, end);
            // 回溯 防止影响
//        path.RemoveAt(path.Count - 1);
//        movCmdList.pop_back();
            path.pop_back();
        }
    }

    string reverseCondition(string condition) {
        string standard = "MWGC";
        string result;
//    if (condition[0] == '.')result[0] = 'M';
//    else result[0] = '.';
//    result[1]
        for (int i = 0; i < standard.length(); i++) {
            result += condition[i] == '.' ? standard[i] : '.';
        }
        return result;
    }

    void makeMovCmd(State &state, Direction direction) {
        if (direction == BACK) {
//        string here = stateToStrHere(state);
// 如果是返回
            string there = stateToStrThere(state);
            string here = reverseCondition(there);
            state.Action = here + " <- " + there;
//        movCmdList.emplace_back(here + " <- " + there);
        } else {
            string here = stateToStrHere(state);
            string there = reverseCondition(here);
//        string there = stateToStrThere(state);
            state.Action = here + " -> " + there;

//        movCmdList.emplace_back(here + " -> " + there);

        }
    }

    State parseStartState(string stateString) {
//    State original= nullptr;
//        如果是. 的话，就是不在 就是true
        if (contains(stateString, "<-")) {
//        endDirection = "返回";
            startDirectionEnum = BACK;
        } else {
//        endDirection = "过河";
            startDirectionEnum = TO;

        }
        return State(stateString[0] == '.', stateString[1] == '.',
                     stateString[2] == '.', stateString[3] == '.');
//        for(int i=0;i<4;i++){
//
//            if(stateString[i])
//        }


    }

    State parseEndState(string stateString) {
//    State original= nullptr;
//        如果是. 的话，就是不在 就是true
        if (contains(stateString, "<-")) {
//        endDirection = "返回";
            endDirectionEnum = BACK;
        } else {
//        endDirection = "过河";
            endDirectionEnum = TO;

        }
        return State(stateString[0] == '.', stateString[1] == '.',
                     stateString[2] == '.', stateString[3] == '.');
//        for(int i=0;i<4;i++){
//
//            if(stateString[i])
//        }


    }

    string stateToStrHere(const State &state) {
        string result = (state.Man ? "." : "M");
//  result +=   (state.Man?".":"M")+(state.Wolf?".":"W")+(state.Sheep?".":"G")+(state.Vegetable?".":"C");
        result += (state.Wolf ? "." : "W");
        result += (state.Sheep ? "." : "G");
        result += (state.Vegetable ? "." : "C");
        return result;
//  result +=  (state.Wolf?".":"W")+(state.Sheep?".":"G")+(state.Vegetable?".":"C");
//  result +=  (state.Wolf?".":"W")+(state.Sheep?".":"G")+(state.Vegetable?".":"C");
    }

    string stateToStrThere(const State &state) {
//    对岸那边有人的话是写M的
        string result = (state.Man ? "M" : ".");
//  result +=   (state.Man?".":"M")+(state.Wolf?".":"W")+(state.Sheep?".":"G")+(state.Vegetable?".":"C");
        result += (state.Wolf ? "W" : ".");
        result += (state.Sheep ? "G" : ".");
        result += (state.Vegetable ? "C" : ".");
        return result;
//  result +=  (state.Wolf?".":"W")+(state.Sheep?".":"G")+(state.Vegetable?".":"C");
//  result +=  (state.Wolf?".":"W")+(state.Sheep?".":"G")+(state.Vegetable?".":"C");
    }

    void Search() {
//    auto cur = path[path.size() - 1];
        cur = path.back();
//停止条件
        if (cur.Equals(end)) {
            count++;
//        printf("解%d:", count);
//        Console.WriteLine($
//        "解{count}:");
//        path.ForEach((a) = > {Console.WriteLine(a.Action);});
//        for (const auto &val:path) {
//            cout << (val.Action) << "\n";
//        }
            if (first) {
                first = 0;
            } else {
                printf("\n");
            }
            have = 1;
//        makeMovCmd(end, endDirection);
            makeMovCmd(end, endDirectionEnum);
//        for (const auto &val:movCmdList) {
//            cout << (val) << "\n";
//        }

            for (const auto &val:path) {
                cout << (val.Action) << "\n";
            }


//        printf("\n");
            return;
        }

//man true的话 是已经过河了 所以要返回,所以一开始是false
        if (cur.Man) {
//        Switch(path, count, cur, "返回", end);
//            Switch(path, count, cur, BACK, end);
            Switch(BACK);
        } else {
            Switch(TO);
        }
    }

    int mainPeopleGoatWolf() {

        string startStr, endStr;
//    cin>>start>>end;
        getline(cin, startStr);
//    auto startState = parseState(start, START);
        start = parseStartState(startStr);
//    pStartState = parseStatePointer(start, START);
        getline(cin, endStr);
//        auto endState = parseState(endStr);
        end = parseEndState(endStr);
//    pEndState = parseStatePointer(end, END);


//    auto original = new State();
//    State original = State(false, false, false, false);
//    auto path =  vector<State>();
//        vector<State> path;
//    path.push_back(original);
        makeMovCmd(start, startDirectionEnum);
//    movCmdList.push_back(start);
        path.push_back(start);

//        int count = 0;
//    Search(path, count);
        Search();

        if (!have) {
            printf("None\n");
        }


//    Console.ReadKey();
    }


    bool contains(const string &src, const string &toFind) {
        return src.find(toFind) != string::npos;
    }
};

#endif //DATASTRUCT_CROSSRIVERPROBLEM_H
