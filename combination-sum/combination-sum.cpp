class Solution {
public:
    void find_all(vector<int> &v,int target,int i,vector<int> curr,vector<vector<int>> &res)
{
        if(target<0||i==v.size())
            return ;
        if(target==0)
        {
            res.push_back(curr);
            return ;
        }
        curr.push_back(v[i]);
        find_all(v,target-v[i],i,curr,res);
        curr.pop_back();
        find_all(v,target,i+1,curr,res);
}

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> curr;
	    find_all(arr,target,0,curr,res);
	    return res;

    }
};