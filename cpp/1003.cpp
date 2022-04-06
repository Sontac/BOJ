#include <iostream>
#include <cstring>
using namespace std;
int r1[41];
int fibonacci(int n)
{
	if (r1[n] != -1)
		return r1[n];
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	r1[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return r1[n];
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	while (n--)
	{
		memset(r1, -1, sizeof r1);
		int p;
		cin >> p;
		if (p == 0)
			cout << 1 << ' ' << 0 <<'\n';
		else
			cout << fibonacci(p-1) << ' ' << fibonacci(p) << '\n';
	}
	
}