#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;

bool comparator( pair< vector<string>, double > a, pair< vector<string>, double > b ) {
    if (a.second < b.second ) return true;
    else if (a.second > b.second) return false;

    if (a.first[0] < b.first[0] ) return true;
    else if (a.first[0] > b.first[0]) return false;

    return a.first[1] < b.first[1];
}

long partition(  vector< pair< vector<string>, double > > &a, long l, long r) {
    long p = rand() % ( r - l + 1 ) + l;
    swap( a[p], a[r] );

    long i = l - 1;
    for ( long j = l; j <= r - 1; j++ ) {
        if ( comparator( a[j], a[r] ) ) {
            i++;
            swap( a[i], a[j] );
        }
    }

    swap( a[i+1], a[r] );
    return i + 1;

}

void quick_sort(  vector< pair< vector<string>, double > > &a, long l, long r) {
    if ( l >= r ) return;

    long pivot = partition( a, l, r);
    quick_sort( a, l, pivot - 1);
    quick_sort( a, pivot + 1, r);
}

int main() {

    unordered_map<string, double> gradeHashMap = {
        {"A+", 4.00},
        {"A", 3.75},
        {"B+", 3.50},
        {"B", 3.00},
        {"C+", 2.50},
        {"C", 2.00},
        {"D+", 1.50},
        {"D", 1.00},
        {"F", 0}
    };

    vector< pair< vector<string>, double > > arr;

    long n;
    cin >> n;
    while ( n -- ) {
        string surname, name;
        long m;
        cin >> surname >> name >> m;
        vector<string> fullname = { surname, name };

        double total = 0, totalSubj = 0;

        while ( m-- ) {
            string grade;
            long subj;
            cin >> grade >> subj;

            total += ( subj * gradeHashMap[grade] );
            totalSubj += subj;
        }

        // cout << total << ' ' << totalSubj << '\n';

        arr.push_back( pair< vector<string>, double >( fullname, ( total/ totalSubj ) ) );
        
    }

    quick_sort( arr, 0, arr.size() - 1 );

    for ( pair< vector<string>, double > a : arr )
        cout << a.first[0] << ' ' << a.first[1] << ' ' << fixed << setprecision(3) << a.second << '\n';
}