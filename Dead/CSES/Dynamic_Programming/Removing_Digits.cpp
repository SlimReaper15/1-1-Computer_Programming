#include <bits/stdc++.h>
using namespace std;

// remove returns the number of steps taken from n to 0
int remove(int n)
{
    string s = to_string(n);
    sort(s.begin(), s.end());
    int l = s.length();
    int max = s[l - 1] - 48;
    if (n < 10)
        return 1;
    return 1 + remove(n - max);
}

int main()
{
    int n;
    cin >> n;
    cout << remove(n) << endl;
}