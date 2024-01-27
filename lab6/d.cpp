#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

bool my_comparator( vector<int> a, vector<int> b) {
    // cout << "test " << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
    if (a[2] < b[2]) return true;      
    else if (a[2] > b[2]) return false;

    if (a[1] < b[1]) return true;
    else if (a[1] > b[1]) return false;

    return a[0] < b[0];

}
long partition( vector<vector<int> >& a, long l, long r) {
    long p = rand() % ( r - l + 1) + l;
    swap( a[p], a[r] );

    long i = l - 1;
    for ( long j = l; j <= r - 1; j++) {
        if (my_comparator( a[j], a[r] )) {
            i++;
            swap( a[j], a[i] );
        } 
    }

    swap ( a[i + 1], a[r] );
    return i + 1;

}
void quick_sort( vector<vector<int> >& a, long l, long r) {
    if (l >= r) return;

    long piv = partition( a, l, r);
    quick_sort( a, l, piv - 1);
    quick_sort( a, piv + 1, r);

}

int main() {
    long n;
    cin >> n;
    vector<vector<int> > date;
    while( n-- ) {
        string s;
        cin >> s;
        stringstream ss( s );
        string token;
        vector<int> arr;
        while ( getline(ss, token, '-')) {
            int val = stoi( token );
            arr.push_back( val );
        }
        date.push_back( arr );
    }

    quick_sort( date, 0, date.size() - 1);

    for ( vector<int> d : date ) {
        cout << setfill('0') << setw(2) << d[0] << '-' << setw(2) << d[1] << '-' << setw(4) << d[2] << endl;
    }
}
