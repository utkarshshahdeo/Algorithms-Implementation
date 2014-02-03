#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
string pat,txt;
int lps[1005];
int l1,l2;
void pi_func();
void kmp()
{
    pi_func();
    int i=0,j=0;
    while(i<txt.length())
    {
       if(txt[i]==pat[j])
       {
           i++;
           j++;
       }
       if(j==pat.length())
       {
           printf("Pattern found at index %d\n",i-j);
           j=lps[j-1];
       }
       else if(pat[j]!=txt[i])
       {
           if(j!=0)
            j=lps[j-1];
           else
            i=i+1;
       }
    }
}
void pi_func()
{
    int i,j,k=0;
    char c;
    for(i=1;i<pat.length();i++)
    {
            if(pat[i]==pat[k])
            {
                lps[i]=k+1;
                k+=1;
            }
            else if(pat[i]!=pat[k])
            {
                lps[i]=0;
                k=0;
            }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>txt>>pat;
        memset(lps,0,sizeof(lps));
        kmp();
    }
    return 0;
}
