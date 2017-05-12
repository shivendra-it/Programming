#include<bits/stdc++.h>
using namespace std;
int fib(int n){
if(n==0 || n==1)
	return n;
int a=0,b=1,c=1;
for(int i=1;i<n-2;i++){
a = b;
b = c;
c = a+b;
}
return c;
}

int main(){
cout<<fib(8);
return 0;
}
