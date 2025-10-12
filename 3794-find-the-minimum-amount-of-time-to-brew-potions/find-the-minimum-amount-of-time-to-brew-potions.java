class Solution {
    public long minTime(int[] skill, int[] mana) {
        long temp[]=new long[skill.length];
        Arrays.fill(temp,0);
        for(int j=0;j<mana.length;j++)
        {
            long start=temp[0];
            // System.out.println(start);
            long totalAddition=0;
            for(int i=0;i<skill.length;i++){
                if(j==0){
                    temp[i]=(i>0?temp[i-1]:0) + (skill[i]*mana[j]);
                }
                else{
                    long addition=Math.max(0,temp[i]-start);
                    totalAddition+=addition;
                    start+=addition+(skill[i]*mana[j]);
                }
            }
            if(j==0)continue;
            // System.out.println(totalAddition);
            for(int i=0;i<skill.length;i++)
            {
                temp[i]=(i>0?temp[i-1]:totalAddition+temp[i]) + (skill[i]*mana[j]);
                // System.out.print(temp[i]+" ");


            }
            System.out.println();
        }
        return temp[skill.length-1];
    }
}