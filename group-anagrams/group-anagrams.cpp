class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashmap;
        for(int i=0;i<strs.size();i++)
        {
            int count[26]={0};
            for(int j=0;j<strs[i].length();j++)
                count[strs[i][j]-'a']++;
            string s;
            for(int j=0;j<26;j++)
            {
                s.push_back(count[j]);
                s.push_back(' ');
            }
            hashmap[s].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto i=hashmap.begin();i!=hashmap.end();i++)
        {
            res.push_back(i->second);
        }
        return res;
    }
};