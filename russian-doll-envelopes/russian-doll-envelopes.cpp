class Solution {
public:
    int lis(vector<vector<int>>& arr,int i,int prev,vector<vector<int>> &dp)
    {
        if(i==arr.size())
            return 0;
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        if(prev==arr.size()||(arr[i][0]>arr[prev][0]&&arr[i][1]>arr[prev][1]))
            dp[i][prev]=max(1+lis(arr,i+1,i,dp),lis(arr,i+1,prev,dp));
        else
            dp[i][prev]=lis(arr,i+1,prev,dp);
        return dp[i][prev];
    }
    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size(),res=1;
        if(n==0)
            return 0;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i][0]>arr[j][0]&&arr[i][1]>arr[j][1])
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};