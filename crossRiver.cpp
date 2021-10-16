//
// Created by Lenovo on 2021/1/2.
//

//羊狼 正确

//
// Created by Lenovo on 2021/1/1.
//


#include <bits/stdc++.h>

using namespace std;
//false 表示未过河， true表示已过河
int have = 0;
int first = 1;

class State {
public:
    bool man;

    bool wolf;

    bool goat;

    bool cabbage;

    string action;

    bool isOk() {

        if (wolf == goat && wolf != man) {
            // wolf和羊都在 但是人不在 会出问题
            return false;
        }

        if (goat == cabbage && goat != man) {
            return false;
        }

        return true;

    }

    State(bool man, bool wolf, bool goat, bool vegetable) : man(man), wolf(wolf), goat(goat), cabbage(vegetable) {}

    State() {}


    State *copy() {
        return new State(man, wolf, goat, cabbage);

    }


    bool equals(const State &newState) {
        return (this->man == newState.man
                && this->wolf == newState.wolf
                && this->goat == newState.goat
                && this->cabbage == newState.cabbage);
    }
};

vector<string> movCmdList;

void makeMovCmd(const State &newState, const string &action);


void search(vector<State> path, int &count, const State &end);


void action(vector<State> path, int &count, State &oldState, State &newState, const State &end, const string &action) {
//    好不好 不好的话就returnle 也不节外生枝了
//  判断就是去isok里看
//  1. wolf和羊都在 但是人不在 会出问题，就是说wolf和羊在同一边，但是人不在这一边 ，是不行的，
//  同理羊和菜也是这样
//2. 不能有重复出现的状态，下面的循环判断了
    if (newState.isOk()) {
        for (auto item:path) {
            if (item.equals(newState)) {
                // 不能有相同的状态
                return;
            }
        }

//        makeMovCmd(oldState, newState, action);
//        makeMovCmd(newState, action);
        path.push_back(newState);
//        search(path,count);
        search(path, count, end);
        // 回溯 防止影响
//        path.RemoveAt(path.Count - 1);
        movCmdList.pop_back();
        path.pop_back();
    }
}

string stateToStrHere(const State &state) {
    string result = (state.man ? "." : "M");
//  result +=   (state.man?".":"M")+(state.wolf?".":"W")+(state.goat?".":"G")+(state.cabbage?".":"C");
    result += (state.wolf ? "." : "W");
    result += (state.goat ? "." : "G");
    result += (state.cabbage ? "." : "C");
    return result;
//  result +=  (state.wolf?".":"W")+(state.goat?".":"G")+(state.cabbage?".":"C");
//  result +=  (state.wolf?".":"W")+(state.goat?".":"G")+(state.cabbage?".":"C");
}


string stateToStrThere(const State &state) {
//    对岸那边有人的话是写M的
    string result = (state.man ? "M" : ".");
//  result +=   (state.man?".":"M")+(state.wolf?".":"W")+(state.goat?".":"G")+(state.cabbage?".":"C");
    result += (state.wolf ? "W" : ".");
    result += (state.goat ? "G" : ".");
    result += (state.cabbage ? "C" : ".");
    return result;
//  result +=  (state.wolf?".":"W")+(state.goat?".":"G")+(state.cabbage?".":"C");
//  result +=  (state.wolf?".":"W")+(state.goat?".":"G")+(state.cabbage?".":"C");
}


void switchMov(const vector<State> &path, int &count, State &cur, const string &actionStr, const State &end) {

    auto *pNewState = cur.copy();
    pNewState->man = !pNewState->man;

    pNewState->action = "独自" + actionStr;
//    makeMovCmd(cur, *pNewState, actionStr);
    makeMovCmd(cur, actionStr);
//    只有这个时候是确定要走了的 这个时候才要把动作保存
//    为什么这个只能在这里push 这个mov的行为 放在action就错了呢
//而且 下面那些都不用makemov  我这里的这句也不用回溯 ，下面那些action之后都要回溯的啊
//意思难道是我都已经独自走了 这是很决绝的，就没必要回溯了，因为这个时候回溯也只是走回头路了
//独自走了是因为再带一个东西过去的话，等会回来就会出问题，所以才要独自走，比如说我现在要带个菜
//过去 但是那边已经有羊了，这样的话我等会还要把羊带回来，这样就很累，所以还不如独自走
//不过独自走的话，什么都不带，那也是循环做无用功了。所以回来的时候才是尽量的独自走，因为好不容易带过去的
//东西 我们不想要带回来了，过河的时候，我们希望尽量带上东西
//现在的状态如果是已经过河了的话
    printf("现在已经是不得不自己走的情况了，因为带着别的东西的话 是之前走过的道路了\n");
    action(path, count, cur, *pNewState, end, actionStr);
//这个时候是已经一定要走的了，因为不带东西，回去了也只是不带东西，这样是循环的不带东西，所以就没必要回溯了

//下面的这些都是去尝试一下 带着狼或者羊过去了，好不好，有没有问题
    if (cur.wolf == cur.man) {
        // 人和狼都在 一起
        pNewState->wolf = !pNewState->wolf;
        pNewState->action = "带着狼" + actionStr;
//        makeMovCmd(cur, *pNewState, actionStr);
//action那边有一个分支 为了不影响我当前的分支 我是要回溯的
        action(path, count, cur, *pNewState, end, actionStr);
//也就是我当前的这个狼的状态是要改回来的
//        actionStr(path, count, *pNewState, end);
        pNewState->wolf = !pNewState->wolf;
    }

    if (cur.goat == cur.man) {
        pNewState->goat = !pNewState->goat;
        pNewState->action = "带着羊" + actionStr;
//        makeMovCmd(cur, *pNewState, actionStr);
        action(path, count, cur, *pNewState, end, actionStr);

//        actionStr(path, count, *pNewState, end);
        pNewState->goat = !pNewState->goat;
    }


    if (cur.cabbage == cur.man) {
        pNewState->cabbage = !pNewState->cabbage;
        pNewState->action = "带着菜" + actionStr;
//        makeMovCmd(cur, *pNewState, actionStr);
        action(path, count, cur, *pNewState, end, actionStr);

//        actionStr(path, count, *pNewState, end);
        pNewState->cabbage = !pNewState->cabbage;
    }
}

string endDirection;


void search(vector<State> path, int &count, const State &end) {
//    auto cur = path[path.size() - 1];
    auto cur = path.back();
//停止条件
    if (cur.equals(end)) {
        count++;
//        printf("解%d:", count);
//        Console.WriteLine($
//        "解{count}:");
//        path.ForEach((a) = > {Console.WriteLine(a.action);});
//        for (const auto &val:path) {
//            cout << (val.action) << "\n";
//        }
        if (first) {
            first = 0;
        } else {
            printf("\n");
        }
        have = 1;
        makeMovCmd(end, endDirection);
        for (const auto &val:movCmdList) {
            cout << (val) << "\n";
        }

//        printf("\n");
        return;
    }

//man true的话 是已经过河了 所以要返回,所以一开始是false
//已经过河了的话 现在就要返回了
    if (cur.man) {
        switchMov(path, count, cur, "返回", end);
    } else {
        switchMov(path, count, cur, "过河", end);
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
void makeMovCmd(const State &newState, const string &action) {
    if (contains(action, "返回")) {
//        string here = stateToStrHere(newState);
// 如果是返回
        string there = stateToStrThere(newState);
        string here = reverseCondition(there);
        movCmdList.emplace_back(here + " <- " + there);
    } else {
        string here = stateToStrHere(newState);
        string there = reverseCondition(here);
//        string there = stateToStrThere(newState);
        movCmdList.emplace_back(here + " -> " + there);

    }
}


//http://c.biancheng.net/view/1367.html
enum Which {
    START, END
};

//https://www.cnblogs.com/wj033/p/9129984.html

State parseState(string stateString) {
//    State original= nullptr;
//        如果是. 的话，就是不在 就是true
    if (contains(stateString, "<-")) {
        endDirection = "返回";
    } else {
        endDirection = "过河";
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
//    search(path, count);
    search(path, count, endState);

    if (!have) {
        printf("None\n");
    }


//    Console.ReadKey();
}
//int main(){
//    mainPeopleGoatWolf();
//}