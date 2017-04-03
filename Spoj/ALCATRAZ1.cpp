#include<bits/stdc++.h>
using namespace std;

char arr[55];

int main(){

  int t;
  cin>>t;
  while (t--) {
    int sum = 0;
    fflush(stdin);
    scanf("%s",arr);
    int l = strlen(arr);
    for(int i=0;i<l;i++){
      sum += arr[i]  - '0';
    }
    std::cout << sum << '\n';
  }


  return 0;
}
