class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto i:words)
        {
            int x=0,y=i.size()-1;
            while(x<=y and i[x]==i[y]){
                x++;
                y--;
            }
            if(x>y)return i;
            if(y==x+1 and i[x]==i[y])return i;
        }
        return "";
    }
};