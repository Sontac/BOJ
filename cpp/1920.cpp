#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int a, b;
	cin >> a;
	vector<int> v1(a);
	for (int i = 0; i < a; ++i)
		cin >> v1[i];
	cin >> b;
	vector<int> v2(b);
	sort(v1.begin(), v1.end());
	auto search = [&](vector<int>& v, int num)
	{
		const int n = v.size();
		int lo = -1, hi = n;
		while (lo + 1 < hi)
		{
			int mid = (lo + hi) / 2;
			if (v[mid] >= num)
				hi = mid;
			else
				lo = mid;
		}
		return hi < n&& v[hi] == num;

	};
	for (int i = 0; i < b; ++i)
	{
		int num;
		cin >> num;
		cout << (search(v1, num)) << '\n'; //binary_serch(v1.begin(),v1.end(),num)
	}

}