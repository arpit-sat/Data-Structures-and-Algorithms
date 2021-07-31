class Solution {
public:
    int get_val(vector<int> &a, vector<int> &b)
    {
        int ans =0 ;
        for(int i=0 ; i<a.size(); i++)
            ans += (a[i] == b[i]) ? 1 : 0;
        return ans;
    }
    
    int solve(vector<vector<int>> &student, vector<vector<int>> &mentor, vector<bool> &visited, int index)
    {
        int n = mentor.size();
        if(index == n)
            return 0;
        int ans = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                int currAns = solve(student , mentor , visited , index+1) + get_val(student[index] , mentor[i]);
                visited[i] = 0;
                ans = max(ans , currAns);
            }
        }
        return ans;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentor) 
    {
        vector<bool> visited(mentor.size());
        int ans = solve(students , mentor , visited , 0);
        return ans;
    }

};