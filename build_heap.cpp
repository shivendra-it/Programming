#include<bits/stdc++.h>
#define pii pair<int,int> 
using namespace std;


int main(){
priority_queue<pii,vector<pii> > Q;

Q.push(make_pair(1,2));
Q.push(make_pair(3,4));
Q.push(make_pair(5,6));
Q.push(make_pair(7,8));
Q.push(make_pair(9,10));
Q.push(make_pair(11,12));

//priority_queue<pii,vector<pii>,greater<pii> >:: iterator  i;

while (!Q.empty())
{
    cout<<Q.top().first<<" ";
    Q.pop();
}
    return 0; 
}