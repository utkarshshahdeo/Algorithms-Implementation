/*Space optimised program of Knapsack Problem*/
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[2][2000001];
int wt[505],val[501];
int main()
{
    int k,n,i,j;
    scanf("%d %d",&k,&n);
    for(i=1;i<=n;i++)
        scanf("%d %d",&val[i],&wt[i]);
    dp[0][0]=0;
    dp[1][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(j>=wt[i])
                dp[(i&1)][j]=max(dp[!(i&1)][j],(dp[!(i&1)][j-wt[i]]+val[i]));
            else
                dp[(i&1)][j]=dp[!(i&1)][j];
        }
    }
    printf("%d\n",dp[(n&1)][k]);
    return 0;
}

