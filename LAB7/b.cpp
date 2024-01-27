#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;

int main() {

    vector<long> nums1, nums2;
    long n;
    cin >> n;
    for (long i = 0; i < n; i++) {
        long num;
        cin >> num;
        nums1.push_back( num );
    }

    long m;
    cin >> m;
    for (long i = 0; i < m; i++) {
        long num;
        cin >> num;
        nums2.push_back( num );
    }

    vector<long> res;
    long i = 0, j = 0;
    while ( i < n || j < m ) {
        if (i == n) res.push_back( nums2[j++] );
        else if ( j == m ) res.push_back( nums1[i++] );
        else if ( nums1[i] < nums2[j] ) res.push_back( nums1[i++] );
        else res.push_back( nums2[j++] );
    }

    for ( long i: res ) cout << i << ' '; 

}