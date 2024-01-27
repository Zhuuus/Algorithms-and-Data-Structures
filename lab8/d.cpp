#include <iostream>
#include <vector>
using namespace std;

void computeLPSArray(string pat, int M,int lps[]);
vector<int> KMPSearch(string txt,vector<string> v,int n)
{
    vector<int> num;
    int max = 0;
    for(int g=0;g<n;g++){
        string pat;
        int count = 0;
        pat = v[g];

        int M = pat.size();
        int N = txt.size();

        int lps[M];

        computeLPSArray(pat, M, lps);

        int i = 0; // index for txt[]
        int j = 0; // index for pat[]
        while ((N - i) >= (M - j)) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }

            if (j == M) {
                // printf("Found pattern at index %d ", i - j);
                count++;
                j = lps[j - 1];
            }

            // mismatch after j matches
            else if (i < N && pat[j] != txt[i]) {
                // Do not match lps[0..lps[j-1]] characters,
                // they will match anyway
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        int max = 0;
        int maxindex;
        if(max<count){
            max = count;
            maxindex = i;
        }
        num.push_back(count);
    }
    cout << max<<"\n";

    for(int i=0;i<n;i++){
        if(max == num[i])
        cout << v[i] << "\n";
    }
    

}
void computeLPSArray(string pat,int M,int lps[])
{
    int len = 0;

    lps[0] = 0;

    int i=1;
    while(i < M)
    {
        if(pat[i] == pat[len]){
            len++;
			lps[i] = len;
			i++;
        }

        else
        {
            if(len != 0){
                len = lps[len-1];

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

        cin >>n;
        if(n == 0) break;

        vector <string> v(n);
         

        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        
        cin >>txt;

        vector <int> num = KMPSearch(txt,v,n);


    }
    
}