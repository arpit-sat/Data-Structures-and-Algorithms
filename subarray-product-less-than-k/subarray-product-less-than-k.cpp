class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0,prod=1,j=0;
        for(int i=0;i<nums.size();i++)
        {
            prod=prod*nums[i];
            while(prod>=k&&j<=i)
            {
                prod=prod/nums[j];
                j++;
            }
            count=count+i-j+1;
        }
        return count;
    }
};