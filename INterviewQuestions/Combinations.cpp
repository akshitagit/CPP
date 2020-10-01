//Given two integers A and B, return all possible combinations of B numbers out of 1 2 3 ... A.
//just return the vector of vector.
void solve(vector<int>v,vector<vector<int>>&a,int index,vector<int>q,int B)
{
    if(B==0)
    {
        a.push_back(q);
        return;
    }
    for(int i=index;i<v.size();i++)
    {
        if(v.size()-i>=B)
        {
            q.push_back(v[i]);
            solve(v,a,i+1,q,B-1);
            q.pop_back();
        }
        else
        {
            return;
        }
    }
    return;
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<int>v,q;
    for(int i=0;i<A;i++)
    {
        v.push_back(i+1);
    }
    vector<vector<int>>a;
    solve(v,a,0,q,B);
    return a;
}