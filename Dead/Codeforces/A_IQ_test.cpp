#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int odd = 0, even = 0;
    for (int i = 0; i < 3; i++)
    {
        if (a[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    int what = (even > odd) ? 1 : 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == what)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
}