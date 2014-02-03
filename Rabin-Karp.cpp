/*(base)(10*(31245-30000)+2)=12452*/
/*Hashing done in constant time expect when hashed for the first time, as we are using
the above property of numbers*/
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    int d,p,t,i,j,k,mod=1000000007,hval;
    string txt,pat;
    while(1)
    {
        getline(cin,txt);
        getline(cin,pat);
        int indx[1000]={0};
        d=256;/*Hashing the string to base 256 as their are 256 characters*/
        p=t=k=0;
        int l=pat.length();
        int n=txt.length();
        hval=1;
        for(i=0;i<l-1;i++) /*100=pow(10,2) length of 100=3*/
        {
            hval=(hval*d)%mod;
        }
        for(i=0;i<l;i++)/*calculating the numeric value of the string*/
        {
            p=(d*p+pat[i])%mod;
            t=(d*t+txt[i])%mod;
        }
        for(i=0;i<=n-l;i++)
        {
            if(p==t)
            {
                for(j=0;j<l;j++)
                {
                    if(txt[i+j]!=pat[j])
                        break;
                }
                if(j==l)
                {
                    indx[k]=i;
                    k++;
                }
            }
            if(i<n-l)/*finding the hashed value of next shift in O(1) time
                      using the property 10*(31245-10000*3)+2=12452*/
                      /*here base is 256*/
                t=(d*(t-txt[i]*hval)+txt[i+l])%mod;
             if(t<0)
                t+=mod;
        }
        if(k==0)
            printf("Pattern not found\n");
        else
        {
        printf("Pattern found at indices\n");
        for(i=0;i<k;i++)
            printf("%d ",indx[i]);
        printf("\n");
        }
    }
    return 0;
}
