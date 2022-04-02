#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		queue<int> q1, check;
		vector<int> v1(a);
		for (int i = 0; i < a; ++i)
		{
			int p;
			cin >> p;
			q1.push(p);
			v1.push_back(p);
			check.push(i == b);
		}
		sort(v1.begin(), v1.end());
		int count = 0;
		while(q1.size()&&v1.size())
		{
			
			if (q1.front() < v1.back())
			{
				int j = q1.front();
				q1.pop();
				q1.push(j);
				check.push(check.front());
				check.pop();
			}
			else
			{
				count++;
				v1.pop_back();
				q1.pop();
				if (check.front() == 1)
					break;
				check.pop();
			}
			
		}
		cout << count <<'\n';
	}
}