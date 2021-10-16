/*
 * main.cpp
 *
 *  Created on: 2014年9月11日
 *      Author: Spike
 */
 
#include <fstream>
#include <iostream>
#include <vector>
//https://blog.csdn.net/caroline_wendy/article/details/39205383
using namespace std;
 
class KWayMergeSort
{
public:
	KWayMergeSort(vector<ifstream*>& vif) :
		m_vifs(vif), m_ofs("out.txt") { }
 
	void calculate() {
		/* 分别从k个输入归并段读人该段当前第一个记录的关键字到外结点 */
		for(int i = 0;i < k;++i) {
			input(i, b[i]);
		}
 
		createLoserTree();
 
	    while(b[ls[0]] != MAXKEY){
	        /* q指示当前最小关键字所在归并段 */
	        int q = ls[0];
 
	        /* 将编号为q的归并段中当前（关键字为b[q].key）的记录写至输出归并段 */
	        cout << b[q] << " ";
	        m_ofs << b[q] << " ";
 
	        /* 从编号为q的输入归并段中读人下一个记录的关键字 */
	        input(q, b[q]);
	        /* 调整败者树，选择新的最小关键字 */
	        adjust(q);
	    }
 
	    /* 将含最大关键字MAXKEY的记录写至输出归并段 */
        cout << endl;
        m_ofs << endl;
	}
private:
	void input (int i, int& b) {
		if ((*m_vifs[i]).good()) {
			(*(m_vifs[i])) >> b;
		}
	}
 
	/**
	* 已知b[0]到b[k-1]为完全二叉树ls的叶子结点，存有k个关键字，沿从叶子
	* 到根的k条路径将ls调整成为败者树。
	*/
	void createLoserTree() {
	    b[k] = MINKEY;
 
	    /* 设置ls中“败者”的初值 */
	    for(int i = 0; i < k; ++i){
	        ls[i] = k;
	    }
 
	    /* 依次从b[k-1]，b[k-2]，…，b[0]出发调整败者 */
	    for(int i = k - 1; i >= 0; --i){
	        adjust(i);
	    }
	}
 
	void adjust(int i) {
		/* ls[t]是b[s]的双亲结点 */
		int t = (i + k) / 2;
		while (t > 0) {
			/* s指示新的胜者 */
			if (b[i] > b[ls[t]]) {
				int tmp = i;
				i = ls[t];
				ls[t] = tmp;
			}
			t = t / 2;
		}
		ls[0] = i;
	}
 
private:
	static const int k = 4;
	static const int MINKEY = -1;
	static const int MAXKEY = 100;
	int b[k+1]; //败者树的叶子节点
	int ls[k]; //败者树的其余节点
	vector<ifstream*> m_vifs;
	ofstream m_ofs;
};
 
int main(void) {
 
	vector<ifstream*> vif;
	ifstream* ifs0 = new ifstream("f0.txt");
	ifstream* ifs1 = new ifstream("f1.txt");
	ifstream* ifs2 = new ifstream("f2.txt");
	ifstream* ifs3 = new ifstream("f3.txt");
	vif.push_back(ifs0);
	vif.push_back(ifs1);
	vif.push_back(ifs2);
	vif.push_back(ifs3);
 
	KWayMergeSort k(vif);
	k.calculate();
 
	delete ifs0;
	delete ifs1;
	delete ifs2;
	delete ifs3;
 
	return 0;
 
}