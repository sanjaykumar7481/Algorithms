class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(auto i:bills)
        {
            if(i>5){
                int rem=i-5;
                if(rem==5){
                    if(five)five--;
                    else return false;
                    ten++;
                }
                else{
                    if(ten and five)
                    {
                        ten--;
                        five--;
                    }
                    else if(five>=3)five-=3;
                    else return false;
                }
            }
            else five++;
        }
        return true;
    }
};