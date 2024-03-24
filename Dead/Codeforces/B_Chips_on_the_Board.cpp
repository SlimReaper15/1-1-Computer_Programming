#include <iostream>
using namespace std;

typedef long long int ll;

int main()
{
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int mina = 1e9 + 1, minb = 1e9 + 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < mina)
                mina = a[i];
            if (b[i] < minb)
                minb = b[i];
        }
        ll sumr = (ll)minb * n, sumc = (ll)mina * n;
        for (int i = 0; i < n; i++)
        {
            sumr += a[i];
            sumc += b[i];
        }
        ll out = (sumr < sumc) ? sumr : sumc;
        cout << out << endl;
    }
}