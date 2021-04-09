class Solution {
public:
    bool is_palin(string &s)
    {
        int left=0,right=s.size()-1;
        while(left<right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(is_palin(s))
            return 1;
        else
            return 2;
    }
};