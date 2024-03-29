#include <iostream>
#include <vector>
#include <hash_fun.h>
#include <string>
using namespace std;

void computeLPSArray(string pat, int M, int lps[]);


bool KMPSearch(string pat,string txt,int count){
    
    int M = pat.size();
    int N = M; //txt = 

    int lps[M];

    computeLPSArray(pat, M, lps);
 
    int i = 0; 
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        else return false;
 
        if (j == M) {
            
            // cout<< pat<<"\n";
            return true;
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
    return false;
}
void computeLPSArray(string pat, int M, int lps[])
{
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
    int count=0;
    cin >> s;
    int s_substr = 0;
    int i=1;
    while (s_substr <= s.size()/2)
    {   
        
        pat = s.substr(0,i);
        txt = s.substr(i,i);
        if(pat == txt){
            count ++;
        }
        i++;
        s_substr++;
        


    }
    cout << count;

}