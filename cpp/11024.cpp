#include <iostream>
#include <string>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(false);

int main()
{
    fastio;
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {       
        string a;
        long long b = 0, k=0;
        getline(cin, a);
        for(int i = 0; i <= a.size(); i++)
        {
            if (a[i] != ' ' && i < a.size())
            {
                k = (k * 10 + (a[i] - '0'));
            }
            else

            {
                b += k;
                k = 0;
            }
        }
        cout << b << '\n';
    }
    return 0;
}