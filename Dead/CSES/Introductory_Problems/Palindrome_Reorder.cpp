#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int asc[26] = {0};
    for (int i = 0; i < l; i++)
        asc[s[i] - 65]++;
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (asc[i] % 2 != 0)
            odd++;
    }
    if (odd > 1)
    {
        printf("NO SOLUTION\n");
        return 0;
    }
    string out;
    char oddc = '0';
    for (int i = 0; i < 26; i++)
    {
        if (asc[i] % 2 == 0)
        {
            for (int j = 0; j < asc[i] / 2; j++)
                out += (char)(i + 65);
        }
        else
            oddc = i + 65;
    }
    string rev = out;
    reverse(rev.begin(), rev.end());
    if (oddc != '0')
    {
        for (int i = 0; i < asc[oddc - 65]; i++)
            out += oddc;
    }
    out += rev;
    cout << out << endl;
}