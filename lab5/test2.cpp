#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
    public: vector<long long> a;
    long long size;

    MinHeap(){
        size = 0;
    }
    long long parent(long long i){
        return (i - 1) / 2;
    }
    long long left(long long i){
        return 2*i+1;
    }
    long long right(long long i){
        return 2*i+2;
    }
    void heapify(long long i){
        if(left(i) > size -1) return ;
        long long j = left(i);
        long long mini = a[left(i)];
        if(right(i) < size && a[right(i)] < mini){
            mini = a[right(i)];
            j = right(i);
        }
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }


    void insert(long long k){
        a.push_back(k);
        size++;
        long long i = size - 1;
        while ( i > 0 && a[parent(i)] > a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i) ;
        }
    }
    void print() {
        for (long long i = 0; i < size; i++) {
            cout << a[i]<<"_"<<i << " ";
        }
        cout << endl;
    }
    long long extractMin(){
        long long root_value = a[0];
        swap(a[0], a[size -1]);
        size--;
        heapify(0);
        return root_value;
    }

    long long increaseKey(long long i, long long new_value) {
        a[i] =a[i]+ new_value;
        long long num = a[i];
        heapify(i);
        return num;
    }
    void A(){
        long long sum = 0;
        while(size>1){
            long long one = extractMin();
            sum += increaseKey(0,one);
        
        }
        cout << sum;
    }
};  



int main(){
    MinHeap* minHeap = new MinHeap;
    int n,k;
    cin >>n;
    for(int i=0; i<n; i++){
        cin>>k;
        minHeap->insert(k);
    }
    
    minHeap->A();

    
}