#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> Pii;
int main()
{
	int n;
	cin >> n;
	while (n--) {
		int row, col, maxLength = 0;
		cin >> row;
		map<Pii, int> lastIndex, length;
		for (int i = 1; i <= row; i++) {
			cin >> col;
			for (int j = 0; j < col; j++) {
				Pii p;
				cin >> p.first >> p.second;
//				所有的row  
//上次出现 就是连续出现 
				if (lastIndex[p] == i-1)
					length[p]++;
				else if (lastIndex[p] < i-1)
					length[p] = 1;
//					距离上次隔了有一个以上的距离 
				lastIndex[p] = i;
				maxLength = max(maxLength, length[p]);
			}
		}
		cout << maxLength << " ";
	}
	return 0;
}

