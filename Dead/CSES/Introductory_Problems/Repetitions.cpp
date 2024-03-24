#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int count = 0, max = 0;
    char prev = s[0];
    for (int i = 1; i < l; i++)
    {
        if (s[i] == prev)
        {
            count++;
            if (count > max)
                max = count;
        }
        else
            count = 0;
        prev = s[i];
    }
    cout << max + 1;
}