#include <iostream>
#include <vector>

using namespace std;

void computeLPSArray(string pat, int M, int lps[]) {
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            } else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPSearch(string pat, string txt) {
    int M = pat.size();
    int N = txt.size();
    vector<int> v;

    int count = 0;
    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;

    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            count++;
            v.push_back(i - j + 1);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    cout << count<<"\n";
    return v;
}

int main() {
    string pat, txt;
    cin >> txt >> pat;

    vector<int> v = KMPSearch(pat, txt);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}
