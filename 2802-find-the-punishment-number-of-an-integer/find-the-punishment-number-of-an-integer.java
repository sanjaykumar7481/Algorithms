class Solution {
    public boolean equals(int i,String nn,int val,String temp,int tar)
    {
        if(i==nn.length())
        {
            if(val==tar && temp==""){
                //System.out.println(val);
                return true;
            }
            return false;
        }
        temp+=""+nn.charAt(i);
        return equals(i+1,nn,val,temp,tar) || equals(i+1,nn,val+Integer.parseInt(temp),"",tar);
    }
    public int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            String nn=""+(i*i);
            if(equals(0,nn,0,"",i)==true)
            {
                ans+=(i*i);
                System.out.println(nn+" "+i);
            }
        }
        return ans;
    }
}