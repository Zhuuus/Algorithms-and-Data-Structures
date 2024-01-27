#include <iostream>
#include <vector>
using namespace std;



vector<long long> prefix_func(string s) {
    long long n = s.size();
    vector<long long> p(n);
    p[0] = 0;

    for (long long i = 1; i < n; i++) {
        for (long long l = 1; l <= i; l++) {
            if (s.substr(0, l) == s.substr(i - l + 1, l)) {
                p[i] = l;
            }
        }
    }

    return p;
}

int main() {
    string s1, s2, pat;

    cin >> s1 >> s2 >> pat;
    long long count = 0;
    
    s1 = pat + s1;
    s2 = pat + s2;

    long long n = s1.size();
    long long n3 = pat.size();
    

    vector<long long> p1 = prefix_func(s1);
    vector<long long> p2 = prefix_func(s2);

    for (long long i = 0; i < n; i++){
        if(p2[i] == p1[i] && p1[i]%n3==0 && p1[i]!=0) count++;
    }
    cout <<count;
    return 0;
}


// a b c a b a
// 0 0 0 1 2 1

// a b c a b a
// b c

// b c # a b c a b a
// 0 0 0 0 1 2 0 1 0

// aababcaaaba
// 0 1 0 0 1 0 0 1 2 2 3 1