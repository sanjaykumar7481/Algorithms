class Solution {
public:
    string convert(string s,vector<string>&ones,vector<string>&elves,vector<string>&tens)
    {
        string res;
        if(s[0]!='0')res+=ones[s[0]-'0']+" Hundred";
        if(s[1]!='0')
        {
            if(s[1]=='1')
            {
                if(s[2]=='0'){
                    if(res!="")res+=" ";
                    return res+="Ten";
                }
                if(res!="")res+=" ";
                return res+elves[s[2]-'0'];
            }
            else 
            {
                if(res!="")res+=" ";
                res+=tens[s[1]-'0'];
            }
        }
        if(s[2]!='0')
        if(res!="")res+=" ";
        res+=ones[s[2]-'0'];
        return res;
    }
    string numberToWords(int num) {
        if(num==0)return "Zero";
        vector<string>ones,tens,elves,addons;
        ones={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        elves={"","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        tens={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        addons={""," Thousand"," Million"," Billion"};
        string ans,strnum=to_string(num);
        int parts=strnum.size()/3,rem=strnum.size()%3,n=strnum.size(),i;
        for(i=0;i<parts;i++)
        {
            n-=3;
            string r=convert(strnum.substr(n,3),ones,elves,tens);
            if(r!="")ans=r+addons[i]+" "+ans;
        }
        if(rem==1)ans=ones[strnum[0]-'0']+addons[i]+" "+ans;
        if(rem==2){
            string res,s=strnum;
            if(s[0]!='0')
            {
                if(s[0]=='1')
                {
                    if(s[1]=='0'){
                        ans="Ten"+addons[i]+" "+ans;
                        ans.pop_back();
                        return ans;
                        
                    }
                    else{
                        ans=elves[s[1]-'0']+addons[i]+" "+ans;
                        ans.pop_back();
                        return ans;
                    }
                }
                else res+=tens[s[0]-'0'];
            }
            if(s[1]!='0')
            res+=" "+ones[s[1]-'0'];
            ans=res+addons[i]+" "+ans;
        }
        ans.pop_back();
        // cout<<ans;
        return ans;
    }
};