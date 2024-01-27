#include <iostream>
#include <vector>
using namespace std;


int main(){
    string txt;
    int n;
    
    cin >>txt>>n;
    vector<string> v(n);

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }

}