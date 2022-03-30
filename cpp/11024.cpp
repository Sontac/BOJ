#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main()
{
    fastio;
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        int sum = 0, k = 0;
        string st1;
        getline(cin, st1);
        for (int i = 0; i <= st1.size(); i++)
        {
            if (st1[i] != ' ' && i < st1.size())
            {
                k = (k * 10 + (st1[i] - '0'));
            }
            else
            {
                sum += k;
                k = 0;
            }
        }
        cout << sum << '\n';
    }
}