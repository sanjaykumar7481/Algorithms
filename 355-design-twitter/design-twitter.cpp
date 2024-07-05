class LinkedList{
  public:
    int val,time;
    LinkedList *next;
    LinkedList(int value,int timer)
    {
        this->val=value;
        this->time=timer;
        this->next=NULL;
    }
};
class Twitter {
public:
    unordered_map<int,LinkedList*>posts;
    unordered_map<int,unordered_map<int,int>>follows;
    long timer=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        LinkedList *nn=new LinkedList(tweetId,timer);
        if(posts.find(userId)==posts.end())
        {
            posts[userId]=nn;
        }
        else {
            nn->next=posts[userId];
            posts[userId]=nn;
        }
        follows[userId][userId]=0;
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<LinkedList*>headers;
        vector<int>res;
        for(auto i:follows[userId])headers.push_back(posts[i.first]);
        int recent=10;
        while(recent--)
        {
            int maxi=-1,ind=-1;
            for(int i=0;i<headers.size();i++)
            {
                if(headers[i] and headers[i]->time > maxi)
                {
                    maxi=headers[i]->time;
                    ind=i;
                }
            }
            if(ind==-1)break;
            res.push_back(headers[ind]->val);
            headers[ind]=headers[ind]->next;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId]=0;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */