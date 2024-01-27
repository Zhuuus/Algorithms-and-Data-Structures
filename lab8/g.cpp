#include <iostream>
#include <vector>
#include <string>

using namespace std;

void computeLPSArray(string pat, int M, int lps[]);

vector<int> KMPSearch(string s, vector<string> v, int n) {
    vector<int> num;

    for (int g = 0; g < n; g++) {
        int M = v[g].size();
        int N = s.size();
        string pat = v[g];

        int count = 0;

        int lps[M];
        computeLPSArray(pat, M, lps);

        int i = 0;
        int j = 0;

        while (i < N) {
            if (pat[j] == s[i]) {
                j++;
                i++;
            }

            if (j == M) {
                count++;
                j = lps[j - 1];
            } else if (i < N && pat[j] != s[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        num.push_back(count);
    }

    return num;
}

void computeLPSArray(string pat, int M, int lps[]) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    string s;
    
    int n;
    cin >>s>> n;
    vector<string> v;
    while (n--) {
        int x, y;
        cin >> x >> y;
        // if(x==1) x=0;

        // cout << s.substr(x-1, y-x+1) << "\n";
        v.push_back(s.substr(x-1, y-x+1));
    }

    vector<int> num = KMPSearch(s, v, v.size());

    // Print or use the results
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << "\n";
    }

    return 0;
}



