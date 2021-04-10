class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int W) {
        if(hand.size()%W!=0)
            return false;
        map<int,int> hashmap;
        for(int i=0;i<hand.size();i++)
        {
            hashmap[hand[i]]++;
        }
        int count=0,prev=-1;
        while(hashmap.size()>0)
        {
            for(auto i=hashmap.begin();i!=hashmap.end();i++)
            {
                if(prev!=-1&&i->first!=prev+1)
                    return false;
                if(i->second>0)
                {
                    i->second--;
                    count++;
                    if(count%W==0)
                    {
                        prev=-1;
                        break;
                    }
                    else
                        prev=i->first;
                }
                if(i->second==0)
                    hashmap.erase(i->first); 
            }
        }
        return true;
    }
};