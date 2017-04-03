#include<bits/stdc++.h>
using namespace std;

int NumberOfSetBits(int i)
{
     // Java: use >>> instead of >>
     // C or C++: use uint32_t
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
int numberOfSetBits(int i)
{
    int c =0;
    while(i){
        i = i&(i-1);
        c++;
    }
return c;
}

int main(){
    cout<<NumberOfSet
    Bits(12125);
    cout<<numberOfSetBits(12125);
    //1458752 == 101100100001001000000

    return 0;
}