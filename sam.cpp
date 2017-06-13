#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mod 1000000007
vector<LL int> fib(10000009, 0);
vector<long  int> st(10000005,0);

void generatefibonacci()
{
	
	fib[0] = 0;
	fib[1] = 1;
	for(LL int i=2; i<10000009; i++)
	{
		fib[i] = (fib[i-1]+fib[i-2])%mod;
	}

}
LL int GCD(LL int a, LL int b)
{
    LL int r, i;
    while(b!=0)
    {
        r = (a % b);
        a = b;
        b = r;
    }
    return a;
}
LL int findGCD(LL int ss, LL int se, LL int qs, LL int qe, LL int si)
{
    if (ss>qe || se < qs)
        return 0;
    if (qs<=ss && qe>=se)
        return st[si];
    LL int mid = ss+(se-ss)/2;
    return GCD(findGCD(ss, mid, qs, qe, si*2+1),
               findGCD(mid+1, se, qs, qe, si*2+2));
}
 
LL int findRangeGCD(LL int ss, LL int se, vector<LL int> &arr ,LL int n)
{
    if (ss<0 || se > n-1 || ss>se)
    {
        return 0;
    }
    return findGCD(0, n-1, ss, se, 0);
}
 
LL int buildST(vector<LL int> &arr, LL int ss,LL int se,LL int si)
{
    if (ss==se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    LL int mid = ss+(se-ss)/2;
    st[si] = GCD(buildST(arr, ss, mid, si*2+1),
                 buildST(arr, mid+1, se, si*2+2));
    return st[si];
}
void generateSegmentTree(vector<LL int> &arr, LL int n)
{
   LL int height = (LL int)(ceil(log2(n)));
   LL int size = 2*(LL int)pow(2, height)-1;
   buildST(arr, 0, n-1, 0);
}


int main()
{
	LL int n ,q;
	cin>>n>>q;
	 vector<LL int> vec(n+1, 0);
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
    }
	generateSegmentTree(vec, n);
	generatefibonacci();
	for(int i=0; i<q; i++)
	{
		LL int l, r;
		cin>>l>>r;
		LL int GCD_value = findRangeGCD(l-1, r-1, vec, n);
		LL int fib_value = fib[GCD_value];

		cout<<fib_value<<endl;
	}

	return 0;

}
