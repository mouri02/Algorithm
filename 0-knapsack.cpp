#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int dp[20][20];
int val[10] = {1,4,5,7};
int wt[10] = {1,3,4,5};
int n =  4;
int cap = 7;
void knapsack ()
{
    int i , j, k;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= cap; j++)
        {
            if(i == 0 || j == 0)
            dp[i][j] = 0;

            if(j < wt[i])
                dp[i][j] = dp[i - 1][j];

            else
            {
                dp[i][j] = max(dp[i - 1][j] , val[i] + dp[i - 1][j - wt[i]]);
            }
        }
    }
}

void print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= cap; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}
int main()
{
   knapsack();
   print();

}
