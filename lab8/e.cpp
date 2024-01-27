#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void translation( vector<long long> v )
{
    
    for(int i=0;i<v.size();i++)
    { 
        long long cure;
        cure = v[i] / pow(2,i) + 97;
        v[i] = cure;

    }

    for(int i=0;i<v.size();i++){
        cout<<char(v[i]);
    }
}


int main(){
    long n;
    long long tmp =0;
    cin>> n;
    vector<long long>v;
    while(n--){
        long long num;
        cin >> num;
        v.push_back(num-tmp);
        tmp = num;
    }

    translation(v);

}