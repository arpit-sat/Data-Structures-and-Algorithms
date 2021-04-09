class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int count=0,j=0,maxi=INT_MIN,end=0;
        for(int i=0;i<A.size();i++)
        {
            maxi=max(maxi,A[i]);
            if(maxi>R)
            {
                j=i+1;
                maxi=INT_MIN;
            }
            else
            {
                if(A[i]>=L)
                    end=i;
                if(maxi>=L)
                    count+=end-j+1;
            }
        }
        return count;
    }
};