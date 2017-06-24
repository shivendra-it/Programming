#include <bits/stdc++.h>
#define ll long long int
#define mod 100000000000000007
using namespace std;

ll ipow(ll base, ll exp)
{
    ll result = 1;
    while (exp)
    {
        if (exp & 1)
            result = (result * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }

    return result;
}

int main()
{
    ll t;
    cin >> t;
    ll a, b, n, c1, c2;
    while (t--)
    {
        cin >> a >> b >> n;
        if (n % 2)
        {
            c1 = (n + 1) / 2;
            c2 = n - c1;
        }
        else
        {
            c1 = n / 2;
            c2 = n - c1;
        }
        ll k = min(c1,c2);
        c1 = c1-k;
        c2 = c2-k;

        a = (a * ipow(2, c1)) % mod;
        b = (b * ipow(2, c2)) % mod;
        // a = (a * 2 << c1) % mod;
        // b = (b * 2 << c2) % mod;
        cout << (max(a, b) / min(a, b)) << endl;
    }

    return 0;
}