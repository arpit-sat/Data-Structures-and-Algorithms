class Solution {
public:
    int find_min(vector<int> &v)
    {
        int mini=INT_MAX;
        for(int i=0;i<v.size();i++)
        {
            mini=min(mini,v[i]);
        }
        return mini;
    }
    int minMoves(vector<int>& v) {
        int moves=0;
        int min_ele = find_min(v);
        for(int i=0;i<v.size();i++)
        {
            moves+=v[i]-min_ele;
        }
        return moves;
    }
};