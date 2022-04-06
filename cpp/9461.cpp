#include <iostream>
#include <cstring>
using namespace std;
using ull = unsigned long long;
ull p[101];
ull pa(int n)
{
	if (p[n] != -1)
		return p[n];
	if (n == 1||n==2||n==3)
		return 1;
	if (n == 4 || n == 5)
		return 2;
	p[n] = pa(n - 1) + pa(n - 5);
	return p[n];
}
int main()
{
	memset(p, -1, sizeof p);
	int a;
	cin >> a;
	while (a--)
	{
		int n;
		cin >> n;
		cout << pa(n) <<'\n';
	}
}