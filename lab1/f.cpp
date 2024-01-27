#include <iostream>
using namespace std;
int main(){
    int n,primNamder,a=0;
    cin >>n;

    for(int i=2;i<100;i++){
        bool prim=true;
        
        for(int j=2;j<=i;j++){
            if( i % j == 0 ){
                prim=false;
                break;
            }
            if(prim){

                a++;
                if(a==n){
                    cout<<i;
                }
            }

        }

    }


};