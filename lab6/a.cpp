#include <iostream>
using namespace std;

bool solution( char a, char b){
     bool a_vowel = false, b_vowel = false;
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') a_vowel = true;
    if (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u') b_vowel = true;

    if (a_vowel && !b_vowel) return true;
    else if ( !a_vowel && b_vowel ) return false;
    else return a < b;


}

int partition(string& s,int low,int hight){
    char pivot = s[hight];
    int i = low-1;

    for(int j=low;j<=hight;j++){
        if(solution(s[j],pivot)){
            i++;
            swap(s[i],s[j]);
        }
    };

    swap( s[ i + 1 ], s[ hight ] );
    return i + 1;
}


void quickSort(string& s,int low,int hight){
    if(low<hight){
        int pi = partition(s,low,hight);
        quickSort(s,low,pi-1);
        quickSort(s,pi+1,hight);
    }
}



int main(){
    int n;
    string s;
    cin>>n>>s;
    quickSort(s,0,n-1);
    cout << s;
}