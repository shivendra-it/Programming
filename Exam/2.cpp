#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[9];
    for (int i = 0; i <9; i++)
    {
            cin >> a[i];
    }

    int w = 0, b = 0, s = 0;

        int i1 = max_element(a,a+3);
        int i2 = max_element(a+3,a+6);
        int i3 = max_element(a+6,a+9);
    
    
    return 0;
}