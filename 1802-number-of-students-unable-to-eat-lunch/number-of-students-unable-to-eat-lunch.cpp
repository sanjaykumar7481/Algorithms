class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int square=0,circle=0;
        queue<int>q;
        for(auto i:students)
        {
            q.push(i);
            if(i==1)square++;
            else circle++;
        }
        int i=0;
        while(!q.empty())
        {
            if(q.front()!=sandwiches[i])
            {
                if(sandwiches[i]==1 and square==0)return q.size();
                if(sandwiches[i]==0 and circle==0)return q.size();
            }
            while(q.front()!=sandwiches[i])
            {
                auto a=q.front();
                q.pop();
                q.push(a);
            }
            if(q.front()==sandwiches[i])
            {
                if(q.front()==1)square--;
                else circle--;
                q.pop();
                i++;
            }
        }
        return 0;
        
    }
};