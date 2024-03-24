#include <algorithm> 
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x, x + n);
    int count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (x[i + 1] != x[i])
            count++;
    }
    cout << count << endl;
}