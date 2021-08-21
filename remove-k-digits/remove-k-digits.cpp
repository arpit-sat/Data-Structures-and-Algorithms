class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        stack<char> st;
        for(int i=0;i<num.length();i++)
        {
            while(k>0&&!st.empty()&&num[i]<st.top())
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0)
        {
            k--;
            st.pop();
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        while(res.length()>1&&res[0]=='0')
            res=res.substr(1);
        if(res.length()==0)
            return "0";
        return res;
    }
};