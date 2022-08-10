class Solution {
private:
	int n, k;
	int allSameNum = 0;
	//<code：形如+1-2+3，code对应的物品个数>
	unordered_map<string, int> memo;
	string getAntiCode(const string &s) {
		string r;
		for (char c : s) {
			if (c == '+')
				r += '-';
			else if (c == '-')
				r += '+';
			else
				r += c;
		}
		return r;
	}
public:
	Solution() {
		cin >> n >> k;
		int temp, last;
		for (int i = 0; i < n; i++)
		{
			string code;
			bool allSame = true;
			for (int j = 0; j < k; j++)
			{
				cin >> temp;
				if (j == 0)
					last = temp;
				else {
					if (temp != last)
						allSame = false;
                        // 一行的数字都一样？
					if (temp - last > 0)
						code += '+';
					code += to_string(temp - last);
					last = temp;
				}
			}
            // 这种差值有多少个。。 而且是 递增的？
            // a[i]-a[i-1]=b[i]-b[i-1]
            cout<<"code : " <<code<<"\n";
			if (allSame)
				allSameNum += 1;
			else if (memo.count(code))
				++memo[code];
			else
				memo[code] = 1;
		}
	}
	void solve() {
		int r = 0;
		for (const auto &m : memo) {
			string antiCode = getAntiCode(m.first);
			if (memo.count(antiCode))
				r += m.second * memo[antiCode];
                // 这种code 有多少个 和他相反的code *
                // 为啥是相反
		}
		r /= 2;
		r += allSameNum * (allSameNum - 1) / 2;
		cout << r << endl;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	Solution s;
	s.solve();
	return 0;
}

// https://www.nowcoder.com/questionTerminal/f5a3b5ab02ed4202a8b54dfb76ad035e?questionTypes=000100&page=1&onlyReference=false