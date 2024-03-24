#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int res[6];
    res[0] = a + b + c;
    res[1] = a * b * c;
    res[2] = (a * b) + c;
    res[3] = a * (b + c);
    res[4] = (a + b) * c;
    res[5] = a + (b * c);
    int max = res[0];
    for (int i = 1; i < 6; i++)
    {
        if (res[i] > max)
            max = res[i];
    }
    cout << max;
}