#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    int n,k;
    cin >>n;
    vector<int> numbers(n);

    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }

    cin >>k;

    int nearestNumberm = numbers[0];
    int nearesIndex = 0;
    int minNearesNumbers = abs(numbers[0] - k);

    for(int i=0;i<n;i++){
        minNearesNumbers = abs(numbers[i]-k);
        if(minNearesNumbers < nearestNumberm){ 
            nearestNumberm=minNearesNumbers;
            nearesIndex = i;
        }
    }
    cout << nearesIndex;

}