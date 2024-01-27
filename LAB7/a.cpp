#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;

void merge(vector<string> &a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    string L[n1];
    for(int i = 0; i < n1; i++){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    string R[n2];
    for(int i = 0; i < n2; i++){
        R[i] = a[l2 + i];
    }


    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1].size() <= R[i2].size()){
            a[i++] = L[i1++];
        }else{
            a[i++] = R[i2++];
        }
    }

    while(i1 < n1){
        a[i++] = L[i1++];
    }
    while(i2 < n2){
        a[i++] = R[i2++];
    }

}

void merge_sort(vector<string> &a, int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, mid + 1, r);
    }
}

int main() {

    long n;
    cin >> n;
    cin.ignore();

    while (n--) {
        vector<string> vec;
        while ( true ) {
            string s;
            cin >> s;
            vec.push_back( s );

            if ( cin.peek() == '\n') break;
        }

        merge_sort( vec, 0, vec.size() - 1 );
        for( string ss: vec ) cout << ss << ' ';
        cout << '\n';
    }
}