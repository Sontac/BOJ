#include <iostream>
#include <vector>

using namespace std;
bool binary(const vector<int>& v, const int t)
{
	const int k = v.size();
	int lo = -1, hi = k;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (v[mid] >= t)
			hi = mid;
		else
			lo = mid;
	}
	return v[hi] == t && hi < k;
}
int lower(const vector<int>& v, const int t)
{
	const int k = v.size();
	int lo = -1, hi = k;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (v[mid] >= t)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}
int upper(const vector<int>& v, const int t)
{
	const int k = v.size();
	int lo = -1, hi = k;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (v[mid] > t)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

vector<int> sort(vector<int>& left, vector<int>& right)
{
	auto lptr = left.begin();
	auto rptr = right.begin();
	vector<int> merged;
	while (lptr != left.end() && rptr != right.end())
	{
		if (*lptr < *rptr)
		{
			merged.emplace_back(*lptr);
			lptr++;
		}
		else
		{
			merged.emplace_back(*rptr);
			rptr++;
		}
	}
	if (lptr != left.end())
		for (; lptr != left.end(); lptr++)
			merged.emplace_back(*lptr);
	else if (rptr != right.end())
		for (; rptr != right.end(); rptr++)
			merged.emplace_back(*rptr);
	return merged;
}


vector<int> mergesort(vector<int>a)
{
	if (a.size() > 1)
	{
		auto mid = size_t(a.size() / 2);
		auto left = mergesort(vector<int>(a.begin(), a.begin() + mid));
		auto right = mergesort(vector<int>(a.begin() + mid, a.end()));
		return sort(left, right);
	}
	else
		return a;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v1(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v1[i];
	}
	int m;
	cin >> m;
	int sum = 0;
	vector<int> v2(m);
	v1=mergesort(v1);
	for (int i = 0; i < m; ++i)
	{
		int t;
		cin >> t;
		if (binary(v1, t))
		{

			v2[i] = upper(v1, t) - lower(v1, t);
		}
		else
			v2[i] = 0;
	}
	for (auto x : v2)
		cout << x << ' ';
}