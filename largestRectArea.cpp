#include<bits/stdc++.h>
///
using namespace std;

int largestRectArea(vector<int> &height) {
    stack<int> p;
    int i = 0, res = 0;
    height.push_back(0);//���ã����ջ
//    p.push_back(0);//���ã����ջ
//    p.push(0);//���ã����ջ
    while (i < height.size()) {
//        ����ջ��� ����ѡȡ������
//��� 1 ���� 5�ߣ�2���� 6�ߣ���ô2��Ҳ�� push�������γ� 2*5 �ľ���
printf("============\n");
//        {2, 1, 5, 6, 2, 3};
//2 1

//2 3
//1*3
//2*4 (5 6 2 3
//1 *6
//���ĸ߶��� 0 ��Ϊ�� ˳���������������
//i �ߵ� 3 ������ �� 2
//3 ���˵� 5 ��  ���ܣ� ��Ϊ��5 �Ļ� ���� 2 ��Ϊ��С��
//Ҳ����������ֻ���˵�����С��
//i �ߵ� 3 �����һ�� ֻ���˵� 2��ȥ��һ�� 2 3 ���� 2 2 �� 2*2==4
//Ϊʲô�� 4������Ϊ   5 6  2  3
        cout<<"i: "<<i<<"\n";
        if (p.empty() || height[p.top()] <= height[i]) {
//            cout<<"i: "<<i<<"\n";
            if (!p.empty()) {
                cout << " height[p.top()]: " << height[p.top()] << "\n";
            }
            cout << "height[i]: " << height[i] << "\n";
            p.push(i++);
//            �����һ�������߾ͽ�ջ
        } else {
            //��� 1 ���� 6�ߣ�2���� 5�ߣ���ô2�в����㣬Ҫ��2�����¿�ʼ��
//            ����Ҫ����һ��Ŀǰ����������p top ����һ����ô�ߵ�
//���� 1 �� 5 ��2  6�� 3 6 �� 4 4
//��4 ��ʱ�� ��Ҫ���¼����ˣ�p�еľ��� 1,4-1 -1 ������2 ��Ϊɶ��2 ��
//ò�Ʋ������������
//1 2  3
//1 5 6
            int t = p.top();
            p.pop();
//            int cnt=i - p.top() - 1;
//            cout<<"cnt :" <<cnt<<"\n";
            if (!p.empty()) {
                cout<<"p.top() : "<<p.top()<<"\n";
                cout << "i - p.top() - 1 �� " << i - p.top() - 1 << "\n";
            }
//            6 ֻ�� һ����ô�ߵ�
//5  ��������Ϊʲô�أ� ��Ϊ6 ��5 ֮��ģ������ߣ��϶�������� ��������֮��һ��
            cout<<"height[t]: "<<height[t]<<"\n";
            res = max(res, height[t] * (p.empty() ? i : i - p.top() - 1));
//            res = max(res, height[t] * (p.empty() ? i :cnt ));
//            0 1 2 3 ����
//2 -1
        }
    }
    return res;
}

//https://blog.csdn.net/liql2007/article/details/9365383
int main() {
    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout << largestRectArea(v);
}