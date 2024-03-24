#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int s[n], e[n];
        for (int j = 0; j < n; j++)
            cin >> s[j] >> e[j];
        int max = 0;
        int flag = 0, flag1 = 0;
        for (int j = 1; j < n; j++)
        {
            if (e[j] >= e[0])
            {
                flag1 = 1;
                if (s[j] >= s[0])
                {
                    cout << -1 << endl;
                    flag = 1;
                    break;
                }
                else if (s[j] > max)
                    max = s[j];
            }
        }
        if (flag == 0 && flag1 == 1)
            cout << max + 1 << endl;
        else if (flag1 == 0)
            cout << s[0] << endl;
    }
}