#include<bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap
{
    int *harr;
    int capacity;
    int hsize;
public:
    MinHeap(int capacity);
    void MinHeapify(int);
    int extractMin();
    int getMin(){ return harr[0]; }
    void insertKey(int k);
    void deleteKey(int i);
    void decreaseKey(int i, int new_val);

    int left(int i){ return (2*i + 1); }
    int right(int i){ return (2*i + 2); }
    int parent(int i){ return ((i-1)/2); }

};

MinHeap::MinHeap(int cap){
    hsize = 0;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::insertKey(int k){
    if(hsize == capacity){
        cout<<"overflow";
        return;
    }

    hsize++;
    int i =hsize-1;
    harr[i] = k;

    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(&harr[i],&harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i ,int k){
    harr[i] = k;
    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(&harr[i],&harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l<hsize && harr[l]<harr[i])
        smallest = l;
    
    if(r<hsize && harr[r]<harr[smallest])
        smallest = r;

    swap(&harr[smallest],&harr[i]);
}

int MinHeap::extractMin(){
    if(hsize <= 0){
        return INT_MAX;
    }
    if(hsize == 1){
        hsize--;
        return harr[0];
    }
    int root = harr[0];
    harr[0]= harr[hsize-1];
    hsize--;
    MinHeapify(0);
    return root;
}

void MinHeap::deleteKey(int i){
    decreaseKey(i,INT_MIN);
    extractMin();
}

int main(){
 MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();

 

    return 0;
}