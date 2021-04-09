class TopVotedCandidate {
public:    
    vector<pair<int,int>> v;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int,int> map;
        int maxi=0,p;
        for(int i=0;i<persons.size();i++)
        {
            map[persons[i]]++;
            if(map[persons[i]]>=maxi)
            {
                maxi=map[persons[i]];
                p=persons[i];
            }
            v.push_back({times[i],p});
        }
    }
    
    int q(int t) {
        if(t>=v.back().first)
            return v.back().second;
        int low=0,high=v.size(),ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(v[mid].first<=t)
            {
                ans=v[mid].second;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */