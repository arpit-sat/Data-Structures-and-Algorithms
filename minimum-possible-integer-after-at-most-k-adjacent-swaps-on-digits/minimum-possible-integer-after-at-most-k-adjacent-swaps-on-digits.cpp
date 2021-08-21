class Solution {
public:
    bool is_inc(string num)
    {
        for(int i=1;i<num.size();i++)
        {
            if(num[i]<num[i-1])
                return false;
        }
        return true;
    }
    string minInteger(string num, int k) {
        if(is_inc(num))
		    return num;
      for (int i = 0; i < num.size() - 1; i++) {
            char min = '0';
            int position;
            while (min <= '9') {
                position = num.find(min, i);
                if (position != num.npos) {
                    if (min == '9') break;
                    if (num[i] == min) break;
                    if (position - i <= k) {
                        num.erase(position, 1);
                        num.insert(i, 1, min);
                        k -= position - i;
                        break;
                    }
                }
                min += 1;
            }
        }
        return num;
    }

};