#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<char> s;
    while ( n-- ) {
        char c;
        cin >> c;
        s.push_back( c );
    }

    char mine;
    cin >> mine;

    for ( char c: s) {
        if ( c > mine ) {
            cout << c;
            return 0;
        }
    }

    cout << s[0];

}