#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

int main()
{
    ll n, m, a;
    cin >> n >> m >> a;
    ll x = (ll)ceil((double)n / a);
    ll y = (ll)ceil((double)m / a);
    cout << x * y << endl;
}
s