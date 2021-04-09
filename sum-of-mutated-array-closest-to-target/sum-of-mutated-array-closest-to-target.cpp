class Solution {
public:
    int get_sum(vector<int>& arr, int k)
    {
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>k)
                sum+=k;
            else
                sum+=arr[i];
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int low=0,high=*max_element(arr.begin(),arr.end());
        int mini=INT_MAX,ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int val=get_sum(arr,mid);
            if(val>target)
            {
                if(val-target<mini)
                {
                    mini=val-target;
                    ans=mid;
                }
                else if(val-target==mini)
                {
                    ans=min(ans,mid);
                }
                high=mid-1;
            }
            else
            {
                if(target-val<mini)
                {
                    mini=target-val;
                    ans=mid;
                }
                if(target-val==mini)
                {
                    ans=min(ans,mid);
                }
                low=mid+1;
            }
        }
        return ans;
    }
};