class Solution {
public:
    int binaryGap(int n) {
        string s;
        for(int i=0;i<32;i++)
        {
            int t=n;
            if((t>>i)&1==1)
                s.push_back('1');
            else
                s.push_back('0');
        }
        int maxi=0,prev=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                int d=i-prev;
                if(prev!=-1)
                    maxi=max(maxi,d);
                prev=i;
            }
        }
        return maxi;
    }
};