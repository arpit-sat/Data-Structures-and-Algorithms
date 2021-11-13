class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int maxi=0,mini=0,taps=0;
        while(maxi<n)
        {
            for(int i=0;i<ranges.size();i++)
            {
                int a=i-ranges[i];
                int b=i+ranges[i];
                if(a<=mini&&b>maxi)
                    maxi=b;
            }
            if(mini==maxi)
                return -1;
            taps++;
            mini=maxi;
        }
        return taps;
    }
};