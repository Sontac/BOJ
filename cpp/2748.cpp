#include <iostream>
#include <vector>
using namespace std;

vector<unsigned long long> r(91);
unsigned long long cal(int n)
{
	if (r[n] > 0)
		return r[n];
	if (n == 1)
		return 1;
	else if (n == 0)
		return 0;
	r[n] = cal(n - 1) + cal(n - 2);
	return r[n];
}

int main()
{
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		r[i] = (0);
	}
	cout << cal(n);
}