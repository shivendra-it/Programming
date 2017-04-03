/*
This time your task is simple.

Given two integers X
and K, find the largest number that can be formed by changing digits at atmost K places in the number X

.

Input:

First line of the input contains two integers X
and K

separated by a single space.

Output:

Print the largest number formed in a single line.

Constraints:

    1≤X≤1018

0≤K≤9


SAMPLE INPUT

4483 2

SAMPLE OUTPUT

9983


*/

#include<bits/stdc++.h>
using namespace std;
int main(){
string n;
int k;
cin>>n>>k;
int t = 0;
int len = n.length();
for(int i=0;i<len && t<k;i++){
  if(n[i]!='9')
    {
      n[i]='9';
        t++;
    }
}
std::cout << n << '\n';
return 0;
}
