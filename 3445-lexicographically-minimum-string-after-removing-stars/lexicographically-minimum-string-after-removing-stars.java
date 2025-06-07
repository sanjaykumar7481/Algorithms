
class Solution {
    class Pair<U,V> implements Comparable<Pair> {
        private U first;
        private V second;

        public Pair(U a,V b){
            first=a;
            second=b;
        }

        public U getFirst(){return first;}
        public V getSecond(){return second;}

        @Override
        public int compareTo(Pair obj){
            char a=(char)first;
            char b=(char)obj.getFirst();
            if(a<b)return -1;
            else if(a==b)return (int)obj.getSecond()-(int)second;
            else return 1;
        }
        
    }
    HashMap<Integer,Integer>mp=new HashMap<>();
    public String clearStars(String s) {
        PriorityQueue<Pair<Character,Integer>>pq=new PriorityQueue();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='*'){
                Pair top=pq.poll();
                System.out.println(top.getFirst()+" "+top.getSecond());
                mp.put((int)top.getSecond(),0);
                continue;
            }
            Pair<Character,Integer>p=new Pair<>(s.charAt(i),i);
            pq.add(p);
        }
        StringBuilder res=new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!='*' && !mp.containsKey(i)){
                res.append(s.charAt(i));
            }
        }
        return res.toString();
    }
}