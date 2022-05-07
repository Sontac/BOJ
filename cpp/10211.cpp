#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
tii find_max_crossing_subaary(vector<int>& v, int left, int mid, int right)
{
	int leftsum = -1'000'000;
	int sum = 0;
	int lindex, rindex;
	for (int i = mid; i >= 0; i--)
	{
		sum += v[i];
		if (sum > leftsum)
		{
			leftsum = sum;
			lindex = i;
		}
	}
	int rightsum = -1'000'000;
	sum = 0;
	for (int i = mid + 1; i <= right; i++)
	{
		sum += v[i];
		if (sum > rightsum)
		{
			rightsum = sum;
			rindex = i;
		}
	}
	return make_tuple(lindex, rindex, leftsum + rightsum);
}
tii find_max_subarray(vector<int>&v, int left, int right)
{
	if (left == right)
		return make_tuple(left, right, v[left]);
	else
	{
		int mid = (left + right) / 2;
		auto [lleft, lright, lmax] = find_max_subarray(v, left, mid);
		auto [rleft, rright, rmax] = find_max_subarray(v, mid+1, right);
		auto [cleft, cright, cmax] = find_max_crossing_subaary(v, left, mid, right);
		if (lmax >= rmax && lmax >= cmax)
			return make_tuple(lleft, lright, lmax);
		else if (rmax >= lmax && rmax >= cmax)
			return make_tuple(rleft, rright, rmax);
		else return make_tuple(cleft, cright, cmax);
	}
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		auto [l, r, max] = find_max_subarray(v, 0, n - 1);
		cout << max << '\n';

	}
}