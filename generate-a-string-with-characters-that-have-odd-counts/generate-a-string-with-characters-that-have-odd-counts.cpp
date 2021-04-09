class Solution {
public:
    string generateTheString(int n) {
        
        string res;
        for(int i=0;i<n-1;i++)
        {
            res.push_back('a');
        }
        if(n%2==1)
            res.push_back('a');
        else
            res.push_back('b');
        return res;
    }
};