class Solution {
public:
    int fun(int i,vector<string>& words, vector<int>& letters, vector<int>& scores)
    {
        if(i>=words.size())return 0;
        int ans=0,score=0,j=0;
        // ans=max(ans,fun(i+1,words,letters,scores));
        vector<int>temp=letters;
        for(j=0;j<words[i].size();j++)
        {
            if(letters[words[i][j]-'a']==0)break;
            else
            {
                letters[words[i][j]-'a']--;
                score+=scores[words[i][j]-'a'];
            }   
        }
        if(j==words[i].size())ans=max(ans,score+fun(i+1,words,letters,scores));
        ans=max(ans,fun(i+1,words,temp,scores));
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        for(auto i:letters)freq[i-'a']++;
        return fun(0,words,freq,score);
    }
};