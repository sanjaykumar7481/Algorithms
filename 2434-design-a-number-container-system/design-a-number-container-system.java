class NumberContainers {
    HashMap<Integer,Integer>mp;
    HashMap<Integer,TreeSet<Integer>>st;
    public NumberContainers() {
        mp=new HashMap<>();
        st=new HashMap<>();
    }
    
    public void change(int index, int number) {
        if(mp.containsKey(index)){
            st.get(mp.get(index)).remove(index);
            if(st.get(mp.get(index)).size()==0)st.remove(mp.get(index));
        }
        if(st.containsKey(number)==false){
            st.put(number,new TreeSet<>());
        }
        mp.put(index,number);
        st.get(number).add(index);
    }
    
    public int find(int number) {
        if(st.containsKey(number)==false)return -1;
        // int a=st.get(number).pollF
        return st.get(number).first();
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */