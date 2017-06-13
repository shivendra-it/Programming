#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> sieveGeneration(ll n)
{
    vector<bool> prime(n+1,true);
    prime[0] = false;
    prime[1] = false;
    int m = sqrt(n);
    for (ll p=2; p<=m; p++)
    {
        if (prime[p])
        {
            for (ll i=p*2; i<=n; i += p)
            prime[i] = false;
        }
    }
    vector<ll> res;
    for (int i=0;i<n;i++)
        if (prime[i])
            res.push_back(i);
    return res;
}

bool checkzero(ll i){
    return (i == 0)?true:false;
}

vector<ll> Rangeofsieve(ll x ,ll y)
{
    vector<ll> s1 = sieveGeneration(x);
    vector<ll> s2 = sieveGeneration(y);
    vector<ll> res(y-x);

    set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(),
    inserter(res, res.end()));
    vector<ll>::iterator itr = remove_if(res.begin(),res.end(),checkzero);
    res.resize(itr-res.begin());

    return res;
}

ll n,q,l,r,x,y,s,j,k,c;
int main()
{
	
	cin >> n;
	ll a[n],p[1000007];
	for(ll i=0;i<n;i++)
		cin >> a[i];

	cin >> q;

	for(ll i=0;i<q;i++){
		cin>>l>>r>>x>>y;
		s=1;
		for(ll i=l-1;i<=r-1;i++)
		    s=s*a[i];

	vector<ll> res = Rangeofsieve(x-1,y+1);
	int len=res.end()-res.begin();
    copy(res.begin(),res.end(),p);
	k=0,c=0;
	while(k<=len-1){
		if(s%p[k]==0){
			c++;
			s=s/p[k];
		}
		else
			k++;
	}
	cout << c << "\n";
    }
	return 0;
}
