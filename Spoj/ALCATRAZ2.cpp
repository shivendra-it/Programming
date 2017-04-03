#include<bits/stdc++.h>
using namespace std;
int arr[8];


int main() {

  
  int n,a,b;
  for(int i=0;i<8;i++)
    cin>>arr[i];
  cin>>n;
  pair<int,int> pii;
  vector<pair<int ,int > > vp(n);
  for(int i=0;i<n;i++){
    cin>>a>>b;
  vp[i].first = a;
  vp[i].second = b;
  }


  return 0;
}
