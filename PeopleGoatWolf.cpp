//
// Created by Lenovo on 2021/1/1.
//


#include <bits/stdc++.h>

using namespace std;
//false 表示未过河， true表示已过河
int have = 0;
int first = 1;
string endDirection;
vector<string> movCmdList;

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


enum Direction {
    TO, BACK
};
Direction endDirectionEnum;

void makeMovCmd(State &state, Direction direction);

void makeMovCmd(const State &state, const string &action);


void Search(vector<State> path, int &count, const State &end);


void Action(vector<State> path, int &count, State &oldState, State &newState, const State &end, const string &action) {
    if (newState.IsOk()) {
        for (auto item:path) {
            if (item.Equals(newState)) {
                // 不能有相同的状态
                return;
            }
        }

//        makeMovCmd(oldState, newState, action);
//        makeMovCmd(newState, action);
        path.push_back(newState);
//        Search(path,count);
        makeMovCmd(oldState, action);

        Search(path, count, end);
        // 回溯 防止影响
//        path.RemoveAt(path.Count - 1);
        movCmdList.pop_back();
        path.pop_back();
    }
}

void Action(vector<State> path, int &count, State &oldState, State &newState, const State &end, Direction direction) {
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
        makeMovCmd(oldState, direction);
        path.push_back(newState);

        Search(path, count, end);
        // 回溯 防止影响
//        path.RemoveAt(path.Count - 1);
//        movCmdList.pop_back();
        path.pop_back();
    }
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


void Switch(const vector<State> &path, int &count, State &cur, const string &action, const State &end) {

//    auto *pNewState = cur.Copy();
    auto newState = cur.Copy();
    newState.Man = !newState.Man;

    newState.Action = "独自" + action;
//    newState.Action
//    makeMovCmd(cur)
//    makeMovCmd(cur, *pNewState, action);
//    makeMovCmd(cur, action);
//现在的状态如果是已经过河了的话
    Action(path, count, cur, newState, end, action);


    if (cur.Wolf == cur.Man) {
        // 人和狼都在 一起
        newState.Wolf = !newState.Wolf;
        newState.Action = "带着狼" + action;
//        makeMovCmd(cur, *pNewState, action);
        Action(path, count, cur, newState, end, action);

//        Action(path, count, *pNewState, end);
        newState.Wolf = !newState.Wolf;
    }

    if (cur.Sheep == cur.Man) {
        newState.Sheep = !newState.Sheep;
        newState.Action = "带着羊" + action;
//        makeMovCmd(cur, *pNewState, action);
        Action(path, count, cur, newState, end, action);

//        Action(path, count, *pNewState, end);
        newState.Sheep = !newState.Sheep;
    }


    if (cur.Vegetable == cur.Man) {
        newState.Vegetable = !newState.Vegetable;
        newState.Action = "带着菜" + action;
//        makeMovCmd(cur, *pNewState, action);
        Action(path, count, cur, newState, end, action);

//        Action(path, count, *pNewState, end);
        newState.Vegetable = !newState.Vegetable;
    }
}

void Switch(const vector<State> &path, int &count, State &cur, Direction direction, const State &end) {

//    auto *pNewState = cur.Copy();
    auto newState = cur.Copy();
    newState.Man = !newState.Man;

//    newState.Action = "独自" + direction;
//    newState.Action
//    makeMovCmd(cur,direction);
//    makeMovCmd(cur, *pNewState, direction);
//    makeMovCmd(cur, direction);
//现在的状态如果是已经过河了的话
//第一步是直接跳过的 所以方向好像和我想的不符合 其实就是反了一下
    Action(path, count, cur, newState, end, direction);


    if (cur.Wolf == cur.Man) {
        // 人和狼都在 一起
        newState.Wolf = !newState.Wolf;
//        newState.Action = "带着狼" + direction;
//        makeMovCmd(cur, *pNewState, direction);
        Action(path, count, cur, newState, end, direction);

//        Action(path, count, *pNewState, end);
        newState.Wolf = !newState.Wolf;
    }

    if (cur.Sheep == cur.Man) {
        newState.Sheep = !newState.Sheep;
//        newState.Action = "带着羊" + direction;
//        makeMovCmd(cur, *pNewState, direction);
        Action(path, count, cur, newState, end, direction);

//        Action(path, count, *pNewState, end);
        newState.Sheep = !newState.Sheep;
    }


    if (cur.Vegetable == cur.Man) {
        newState.Vegetable = !newState.Vegetable;
//        newState.Action = "带着菜" + direction;
//        makeMovCmd(cur, *pNewState, direction);
        Action(path, count, cur, newState, end, direction);

//        Action(path, count, *pNewState, end);
        newState.Vegetable = !newState.Vegetable;
    }
}


void Search(vector<State> path, int &count, State &end) {
//    auto cur = path[path.size() - 1];
    auto cur = path.back();
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
        Switch(path, count, cur, BACK, end);
    } else {
        Switch(path, count, cur, TO, end);
    }
}

bool contains(const string &src, const string &toFind) {
    return src.find(toFind) != string::npos;
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

//https://pintia.cn/problem-sets/1344847226110738432/problems/1344847333161959424
void makeMovCmd(const State &state, const string &action) {
    if (contains(action, "返回")) {
//        string here = stateToStrHere(state);
// 如果是返回
        string there = stateToStrThere(state);
        string here = reverseCondition(there);
        movCmdList.emplace_back(here + " <- " + there);
    } else {
        string here = stateToStrHere(state);
        string there = reverseCondition(here);
//        string there = stateToStrThere(state);
        movCmdList.emplace_back(here + " -> " + there);

    }
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




//https://www.cnblogs.com/wj033/p/9129984.html

State parseState(string stateString) {
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


int mainPeopleGoatWolf() {

    string start, end;
//    cin>>start>>end;
    getline(cin, start);
//    auto startState = parseState(start, START);
    auto startState = parseState(start);
//    pStartState = parseStatePointer(start, START);
    getline(cin, end);
    auto endState = parseState(end);
//    pEndState = parseStatePointer(end, END);


//    auto original = new State();
//    State original = State(false, false, false, false);
//    auto path =  vector<State>();
    vector<State> path;
//    path.push_back(original);
    path.push_back(startState);
//    movCmdList.push_back(start);
    int count = 0;
//    Search(path, count);
    Search(path, count, endState);

    if (!have) {
        printf("None\n");
    }


//    Console.ReadKey();
}