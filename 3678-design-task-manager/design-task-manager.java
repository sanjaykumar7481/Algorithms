class TaskManager {
    Map<Integer,Integer>tasksPriority,userTasks;
    TreeMap<Integer,TreeSet<Integer>>prioritySorter;
    public TaskManager(List<List<Integer>> tasks) {
        tasksPriority=new HashMap<>();
        prioritySorter=new TreeMap<>();
        userTasks=new HashMap<>();
        for(List<Integer>i:tasks){
            userTasks.put(i.get(1),i.get(0));
            tasksPriority.put(i.get(1),i.get(2));
            prioritySorter.putIfAbsent(i.get(2),new TreeSet<>());
            prioritySorter.get(i.get(2)).add(i.get(1));
        }
    }
    
    public void add(int userId, int taskId, int priority) {
        userTasks.put(taskId,userId);
        tasksPriority.put(taskId,priority);
        prioritySorter.putIfAbsent(priority,new TreeSet<>());
        prioritySorter.get(priority).add(taskId);
    }
    
    public void edit(int taskId, int newPriority) {
        int oldPriority=tasksPriority.get(taskId);
        prioritySorter.get(oldPriority).remove(taskId);
        if(prioritySorter.get(oldPriority).isEmpty())prioritySorter.remove(oldPriority);
        tasksPriority.remove(taskId);
        prioritySorter.putIfAbsent(newPriority,new TreeSet<>());
        prioritySorter.get(newPriority).add(taskId);
        tasksPriority.put(taskId,newPriority);
    }
    
    public void rmv(int taskId) {
        int oldPriority=tasksPriority.get(taskId);
        prioritySorter.get(oldPriority).remove(taskId);
        if(prioritySorter.get(oldPriority).isEmpty())prioritySorter.remove(oldPriority);
        userTasks.remove(taskId);
        tasksPriority.remove(taskId);
    }
    
    public int execTop() {
        if(prioritySorter.isEmpty())return -1;
        int taskId=prioritySorter.get(prioritySorter.lastKey()).last();
        int userId=userTasks.getOrDefault(taskId,-1);
        rmv(taskId);
        return userId;

    }
}

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager obj = new TaskManager(tasks);
 * obj.add(userId,taskId,priority);
 * obj.edit(taskId,newPriority);
 * obj.rmv(taskId);
 * int param_4 = obj.execTop();
 */