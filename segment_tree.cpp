#include<bits/stdc++.h>
using namespace std;
int sum[1000];
void build (int inp_arr[], int node, int tl, int tr) {
    if (tl == tr)
        sum[node] = inp_arr[tl];
    else {
        int mid = (tl + tr) / 2;
        build (inp_arr, node*2, tl, mid);
        build (inp_arr, node*2+1, mid + 1, tr);
        sum[node] = sum[node*2] + sum[node*2+1];
    }
}


int sum_query (int node,int l, int r,int tl, int tr) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return sum[node];
    int tm = (tl + tr) / 2;
    return sum_query (2*node,l, min(r,tm),tl, tm) 
               + sum_query (2*node + 1,max(l,tm + 1), r,tm + 1, tr);
}


void update (int node, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        sum[node] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (node*2, tl, tm, pos, new_val);
        else
            update (node*2+1, tm+1, tr, pos, new_val);
        sum[node] = sum[node*2] + sum[node*2+1];
    }
}


int main(){    
cout<< "saff";
int inp_arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
build(inp_arr,1,0,14);
cout<< "saf";
cout<< sum_query(1,0, 14,1, 3) <<endl;
    return 0;
    
}

