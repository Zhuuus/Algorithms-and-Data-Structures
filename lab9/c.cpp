#include <iostream>
#include <vector>

using namespace std;
void computeLPSArray(string pat, int M, int lps[]);

bool KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = M;

    int lps[M];

    computeLPSArray(pat,M,lps);

    int i = 0 ;
    int j = 0 ; 

    while((N - i) >= (M - j)){
        if((pat[j]) == (txt[i])){
            j++;
            i++;
        }
        if(j == M){
            return true;
            j = lps[j - 1];
        }

        else if(i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    
}

void computeLPSArray(string pat, int M,int lps[] )
{
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while(i < M)
    {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }

    }
}

int main(){
    string s,pat,txt;
    cin >>txt>>pat;
    s=txt;
    long long count=0;
    bool q=true;
    while (q)
    {
        for(long long i=0;i<s.size();i++){
            if(KMPSearch(pat,txt)){
                cout <<count;
                q=false;
                break;
            }

            if(txt.size() > pat.size()*2){
                cout<<"-1";
                q=false;
                break;
            }

            count++;
            txt=txt+s[i];
            cout<< txt<<"\n";
        }
    }
    
}