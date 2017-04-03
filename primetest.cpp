#include<bits/stdc++.h>
using namespace std;
int isAKSprime(int n){
int i=5, w=2;
if(n==2 || n==3 || n==5)
	return 1;
if(n%2 == 0 || n%3 == 0 || n==1)
	return 0;
while(i*i <= n)
{
if(n%i==0)
return 0;

i+=w;
w=6-w;

}
return 1;

}
int main(){
int n;

while(1){
cin>>n;
cout<<isAKSprime(n);
}
return 0;
}
