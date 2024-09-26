class MyCalendar {
public:
    set<pair<int,int>>st;
    vector<pair<int,int>>vec;
    MyCalendar() {
    }
    bool fun(int l,int r,vector<pair<int,int>>&v,int a,int b)
    {
        if(l>r)return false;
        int m=(l+r)/2;
        if(v[m].second<a) return fun(m+1,r,v,a,b);
        else
        {
            if(v[m].first<=b)return true;
            return fun(l,m-1,v,a,b);
        }
    }
    bool book(int start, int end) {
        vec.clear();
        for(auto i:st)vec.push_back({i.first,i.second});
        if(fun(0,vec.size()-1,vec,start,end-1)==false)
        {
            st.insert({start,end-1});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */