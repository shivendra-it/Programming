#include<bits/stdc++.h>
using namespace std;

int arr[1001];

int main(){
  int n,k,s;
  cin>>n>>k>>s;
  for(int i=0;i<n;i++){
    std::cin >> arr[i];
  }

  std::sort(arr,arr+n);

  int isk = k*s;

  int sum =0;
  for(int i=n-1;i>=0;i--){
    sum += arr[i];
    if(sum>=isk){
      std::cout << n-i << '\n';
      break;
    }
  }

  return 0;
}
