class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        // your code here
        long long dp[m+1];
        int i;
        dp[0]=dp[1]=1;
        for(i=2;i<=m;i++){
            dp[i]=1;
            dp[i] += dp[i-2];
        }
        return dp[m];
    }
};
