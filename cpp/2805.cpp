#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int N, M,v[1'000'000];
bool check(int mid)
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i] > mid)
			sum += v[i] - mid;
	}
	return sum >= M;

}
int main()
{
	fastio;
	cin >> N >> M;
	for(int i=0; i<N; i++)
	{
		int k;
		cin >> k;
		v[i] = k;
	}
	
	int low = 0, high = 1e9, mid;
	while (low+1<high)
	{
		mid = (low + high) / 2;
		if (check(mid))
			low = mid;
		else
			high = mid;
	}
	cout << low;
}