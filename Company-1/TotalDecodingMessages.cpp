int CountWays(string s){
		    // Code here
		    int n = s.size();
		    vector<int> dp(n,0);
		    int i;
		    if(s[i]-48 == 0)
		    return 0;
		    
		    dp[i]=1;
		    for(i=1;i<n;i++){
		        if(s[i]-48 != 0)
		        dp[i]=dp[i-1];
		        
		        int x = (s[i-1]-48)*10 + (s[i]-48);
		        if(x >= 10 && x<= 26){
		            dp[i] += (i-2>=0 ? dp[i-2] : 1);
		            dp[i] %= mod;
		        }
		        if(dp[i] == 0)
		        return 0;
		    }
		    return dp[n-1];
		}
