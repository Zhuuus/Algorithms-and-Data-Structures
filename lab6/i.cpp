#include <iostream>
using namespace std;
int partition(string& s,int low,int height){
    int pivat = s[height];
    int i = low - 1;
    for(int j=0;j<=height;j++){
        if(s[j]<pivat){
            i++;
            swap(s[i],s[j]);
        }
    }
    swap(s[i + 1], s[height] );
    return i + 1;
}

void quickSort(string& s,int low ,int height){
    if(low< height){
        int pi = partition(s,0,height);
        quickSort(s,low,pi-1);
        quickSort(s,pi+1,height);
    }
}
int main(){
    string s;
    cin>>s;
    
    quickSort(s,0,s.size()-1);
    cout<<s;
}