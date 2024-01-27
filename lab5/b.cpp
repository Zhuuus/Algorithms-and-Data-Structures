#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
    public: vector<int> stone;
    public: int size;
    


    int left(int i){
        return i*2+1;
    }
    int right(int i){
        return i*2+2;
    }
    int parent(int i){
        return (i-1)/2;

    }



    void insert(int k){
        stone.push_back(k);
        int i = size;
        while( i > 0 && stone[parent(i)] < stone[i] ){
            // cout<<"m";
            swap(stone[parent(i)],stone[i]);
            i = parent(i);

        }
        size+=1;

    }

    void heapify(int i){
        if(left(i) > size-1 ) return ;
        int j = left(i);
        int max = stone[left(i)];

        if(right(i) < size && stone[right(i)] > max){
            max = stone[right(i)];
            j = right(i);
        }

        if(stone[i] < stone[j] ){
            swap(stone[i],stone[j]);
            heapify(j);
        }
    }

    void PowerStone(){
        // cout << stone[0]<<endl;
        if(stone[0]==stone[1]){
            cout<<stone[0]<<"-"<<stone[1]<<'='<<stone[0] - stone[1]<<endl;
            swap(stone[0],stone[size-1]);
            stone.pop_back();
            swap(stone[1],stone[size-2]);
            stone.pop_back(); 
            size-=2;
            heapify(1);
            heapify(0);
        }

        if(stone[0] < stone[1]){
            cout<<stone[0]<<"-"<<stone[1]<<'='<<stone[0] - stone[1]<<endl;

            stone[1] = stone[1] - stone[0];
            swap(stone[0],stone[size-1]);

            stone.pop_back();
            size -=1;

            heapify(1);
            heapify(0);
            heapify(1);
        }
        if(stone[0]>stone[1]){
            cout<<stone[0]<<"-"<<stone[1]<<'='<<stone[0] - stone[1]<<endl;

            stone[0] = stone[0] - stone[1];
            swap(stone[1],stone[size-1]);
            stone.pop_back();

            size -=1;
            heapify(1);
            heapify(0);
            heapify(1);
        }
    }
    void starStoneWar(){
        while(size>1){
            PowerStone();
        }
        if(stone.empty()) cout << 0;
        
        else cout<<stone[0];
    }

};
int main(){
    MaxHeap* maxHeap = new MaxHeap;
    int n,k;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>k;
        maxHeap->insert(k);
    }

    maxHeap->starStoneWar();
}