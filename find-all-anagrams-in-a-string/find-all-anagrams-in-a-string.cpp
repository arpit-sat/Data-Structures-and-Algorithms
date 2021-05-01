class Solution {
public:
    bool isvalid(vector<int> &v)
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=0)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s2, string s1) {
        if(s1.length()>s2.length())
            return {};
        vector<int> s1map(26);
        for(int i=0;i<s1.size();i++)
        {
            s1map[s1[i]-'a']++;
        }
        int n=s1.length();
        for(int i=0;i<n-1;i++)
        {
            s1map[s2[i]-'a']--;
        }
        vector<int> res;
        int j=0;
        for(int i=n-1;i<s2.size();i++)
        {
            s1map[s2[i]-'a']--;
            if(isvalid(s1map))
                res.push_back(j);
            s1map[s2[j]-'a']++;
            j++;
        }
        return res;
    }
};