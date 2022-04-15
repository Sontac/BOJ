#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>> v(200'001);
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		v[a + 100'000].push_back(b);
	}
	for (int i = 0; i <= 200'000; ++i)
	{
		if (v[i].size()!=0)
		{
			sort(v[i].begin(), v[i].end());
			for (auto& x : v[i])
				cout << i - 100'000 << ' ' << x << '\n';
		}
	}
}