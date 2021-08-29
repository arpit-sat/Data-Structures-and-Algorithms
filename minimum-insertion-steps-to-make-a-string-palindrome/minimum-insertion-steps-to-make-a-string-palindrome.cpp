class Solution {
public:
    int lps(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n));
        for(int i=0;i<n;i++) 
            dp[1][i]=1;
        for(int i=2;i<=n;i++) 
        {
            for(int j=0;j<n-i+1;j++) 
            {
                dp[i][j]=s[j]==s[i+j-1]?2+dp[i-2][j+1]:max(dp[i-1][j],dp[i-1][j+1]);
            }
        }
        return dp[n][0]; 
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
    int minInsertions(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        return s.length()-longestCommonSubsequence(s,r);
    }
};