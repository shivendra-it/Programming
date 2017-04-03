#include<bits/stdc++.h>
using namespace std;

int arr[49700];

void seieve(int n){
fill(arr,arr+n,0);

int v = sqrt(n);

for(int i=2;i<=v;i++){
    for(int j=2;i*j<n;j++){
        arr[i*j] = 1;
    }
}
for(int i=2;i<n;i++){
    if(!arr[i])
    cout<<i<<",";
}

}

int main(){
    seieve(49700);
}