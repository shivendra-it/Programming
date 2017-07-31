#include <iostream>
using namespace std;

int solve(int a[],int n,int x,int y,int c,int b[])
{
	if(b[x-1] == 1)
	return 10000000;
	
	b[x-1] = 1;
	
	if(x == y)
	return c;
	
	int left,right;
	
	left = x+a[x-1]%n;
	int ans1 = solve(a,n,left,y,c+1,b);
	b[left-1] = 0;
	right = ((x-a[x-1])%n+n)%n;
	int ans2 = solve(a,n,right,y,c+1,b);
	b[right-1] = 0;
	return min(ans1,ans2);
}

int main() {
	
	int t,n,x,y;
	int a[100000];
	int b[100000] = {0};
	int c[100000] = {0};
	
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n >> x >> y;
		for(int j=0;j<n;j++)
		cin >> a[j];
		
		cout << solve(a,n,x,y,0,b) << endl;
	}
	
	return 0;
}