class Solution {
public:
    int get_val(vector<int> &student,vector<int> &mentor)
    {
        int val=0;
        for(int i=0;i<student.size();i++)
        {
            if(student[i]==mentor[i])
            {
                val++;
            }
        }
        return val;
    }
void find_max(vector<vector<int>>&students, vector<vector<int>>& mentor,
int &max_score,int curr_score,int j,vector<bool> &visited)
{
	if(j==students.size())
	{
		max_score=max(max_score,curr_score);
	}
	for(int i=0;i<students.size();i++)
	{
		if(visited[i]==false)
		{
			visited[i]=true;
			int temp=get_val(students[i],mentor[j]);
			find_max(students,mentor,max_score,curr_score+temp,j+1,visited);
			visited[i]=false;
		}
	}
}

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) 
    {
        int max_score=0;
        int n=students.size();
        vector<bool> visited(n);
        find_max(students,mentors,max_score,0,0,visited);
        return max_score;
    }
};