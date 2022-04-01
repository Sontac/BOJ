#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
vector<int> sort(const vector<int>& left, const vector<int>& right)
{
	auto lptr = left.begin();
	auto rptr = right.begin();
	vector<int> sorted;
	while (lptr != left.end() && rptr != right.end())
	{
		if (*lptr > *rptr)
		{
			sorted.emplace_back(*rptr);
			rptr++;
		}
		else
		{
			sorted.emplace_back(*lptr);
			lptr++;
		}	
	}
	if (lptr != left.end())
	{
		for (; lptr != left.end(); lptr++)
			sorted.emplace_back(*lptr);
	}
	else
	{
		for (; rptr != right.end(); rptr++)
			sorted.emplace_back(*rptr);
	}
	return sorted;
}
vector<int> mergesort(vector<int> a)
{
	if (a.size() > 1)
	{
		auto n = size_t(a.size() / 2);
		auto left = mergesort(vector<int>(a.begin(), a.begin()+n));
		auto right = mergesort(vector<int>(a.begin() + n, a.end()));
		return sort(left, right);

	}
	return a;
}

int main()
{
	fastio;
	int n,m;
	cin >> n;
	vector<int> v1(n);
	for (int i = 0; i < n; ++i)
		cin >> v1[i];
	v1 = mergesort(v1);
	cin >> m;
	
	
	auto search = [&](const vector<int>& v,const int t)
	{
		const int n = v.size();
		int lo = -1, hi = n;
		while (lo + 1 < hi)
		{
			int mid = (lo + hi) / 2;
			if (v[mid] >= t)
				hi = mid;
			else
				lo = mid;
		}
		return v[hi] == t && hi<n;
	};
	for (int i = 0; i < m; ++i)
	{
		int t;
		cin >> t;
		cout << search(v1, t) << ' ';
	}
	
}