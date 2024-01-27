#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
    public: vector<long long > freeSeat;
    public: long long  size;
    
    MaxHeap(){
        size =0;
    }

    long long  parent(long long  i){
        return i = (i-1)/2;
    }
    long long  left(long long  i){
        return i = (i*2)+1;
    }
    long long  right(long long  i){
        return i = i * 2 +2;
    }
    void heapify(long long  i){
        if (left(i) > size-1) return ;
        long long  j = left(i);
        long long  max = freeSeat[left(i)];
        

        if( right(i) < size  && freeSeat[right(i)] > max){
            j = right(i);
            max = freeSeat[right(i)];
        }

        if (freeSeat[i]<freeSeat[j]){
            swap(freeSeat[i],freeSeat[j]);
            heapify(j);
        }
    }
    

    void insert(long long  k){
        freeSeat.push_back(k);
        long long  i = size;

        while( i > 0 && freeSeat[parent(i)] < freeSeat[i]){
            swap(freeSeat[parent(i)],freeSeat[i]);
            i = parent(i);

        }

        size++;
    }


    void answer(long long  ticket){
        long long  sum = 0;
        while(ticket!=0){
            sum += freeSeat[0];
            // cout <<freeSeat[0]<<"\n";
            freeSeat[0] -=1;
            heapify(0);
            ticket-=1;
        }
        cout<<sum;

    }
};

int  main(){
    MaxHeap* maxHeap = new MaxHeap;
    long long  n,ticket,k;
    cin >> n>> ticket;
    for(long long  i=0;i<n;i++){
        cin>>k ;
        maxHeap->insert(k);
    }

    maxHeap -> answer(ticket);
}
