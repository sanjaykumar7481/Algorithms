/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void construct(HashMap<Integer,TreeNode>mp,String temp,int level)
    {
        int depth=level-1;
        System.out.println(temp+ " "+depth);
        TreeNode nn=new TreeNode(Integer.parseInt(temp));
        if(depth>=0)
        {
            TreeNode par=mp.get(depth);
            if(par.left==null)par.left=nn;
            else par.right=nn;
        }
        mp.put(level,nn);
    }
    public TreeNode recoverFromPreorder(String traversal) {
        HashMap<Integer,TreeNode>mp=new HashMap<>();
        int level=0,i=0;
        String temp="";
        while(i<traversal.length()){
            while(i<traversal.length() && traversal.charAt(i)!='-'){
                temp+=traversal.charAt(i);
                i++;
            }
            if(temp.length()>0)
            {
                construct(mp,temp,level);
                level=0;
            }
            
            temp="";
            level++;
            i++;

        }
        return mp.get(0);

    }
}