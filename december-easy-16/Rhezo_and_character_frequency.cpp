#include<bits/stdc++.h>
using namespace std;
int main(){
string n;
char c;
int k;
cin>>n>>c>>k;
int t = 0,max=-1;
int len = n.length();
int arr[1000],pos=0;

for(int i=0;i<len;i++){
  int p =0;
for(int j=0;j<k && (i+j) < len;j++){
  if(n[i+j]==c)
    p++;
  }
  if(p>=max){
    max=p;
    pos=i;
  }
}
for(int s =pos ;s<=k;s++)
{
  if(n[s]==c)
    pos = s;
}
//std::cout<<"max" << max << '\n';
if(max<=0)
std::cout << "-1" << '\n';
else
std::cout << pos+2 << '\n';
return 0;
}
