#include <iostream>
#include <vector>
using namespace std;

void computeLPSArray(string pat, int M, int lps[]);
vector<int> KMPSearch(string txt, vector<string> v, int n)
{
    vector<int> num;
    int max = 0;
    for (int g = 0; g < n; g++)
    {
        string pat;
        int count = 0;
        pat = v[g];

        int M = pat.size();
        int N = txt.size();

        int lps[M];
        computeLPSArray(pat, M, lps);

        int i = 0; // index for txt[]
        int j = 0; // index for pat[]
        while ((N - i) >= (M - j))
        {
            if (pat[j] == txt[i])
            {
                j++;
                i++;
            }

            if (j == M)
            {
                count++;
                j = lps[j - 1];
            }

            else if (i < N && pat[j] != txt[i])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        if (max < count)
        {
            max = count;
            // maxindex = i; // remove if not used
        }
        num.push_back(count);
    }
    cout << max << "\n";

    for (int i = 0; i < n; i++)
    {
        if (num[i] == max)
            cout << v[i] << "\n";
    }
    return num;
}

void computeLPSArray(string pat, int M, int lps[])
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{

    while (true)
    {
        int n;
        string txt;

        cin >> n;
        if (n == 0)
            break;

        vector<string> v;

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }

        cin >> txt;

        vector<int> num = KMPSearch(txt, v, n);
    }
}
