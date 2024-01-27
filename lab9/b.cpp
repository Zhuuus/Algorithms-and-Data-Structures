#include <iostream>
using namespace std;
void computeLPSArray(string pat, int M, int lps[]);

void KMPSearch(string pat,int num,string txt)
{
    int M = pat.size();
    int N = txt.size();

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
            num--;
            // cout << "Df"
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
    if(num <= 0 ){
        cout << "YES";
    }
    else cout<< "NO";
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
    string pat,txt;
    int num;
    cin >> pat>>num>>txt;

    KMPSearch(pat,num,txt);
}
