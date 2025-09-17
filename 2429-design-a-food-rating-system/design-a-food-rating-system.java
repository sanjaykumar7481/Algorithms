class FoodRatings {
    Map<String,Integer>foodRatings;
    Map<String,String>foodCuisines;
    Map<String,TreeMap<Integer,TreeSet<String>>>dataStructure;
    public FoodRatings(String[] food, String[] cuisines, int[] ratings) {
        dataStructure=new HashMap<>();
        foodRatings=new HashMap<>();
        foodCuisines = new HashMap<>();
        for(int i=0;i<ratings.length;i++) {
            foodRatings.put(food[i],ratings[i]);
            foodCuisines.put(food[i], cuisines[i]);
        }
        for(int i=0;i<cuisines.length;i++) {
            dataStructure.putIfAbsent(cuisines[i],new TreeMap<>());
            TreeMap<Integer, TreeSet<String>> cur = dataStructure.get(cuisines[i]);
            cur.putIfAbsent(ratings[i], new TreeSet<>());
            cur.get(ratings[i]).add(food[i]);
        }
    }
    
    public void changeRating(String food, int newRating) {
        int foodRating = foodRatings.get(food);
        foodRatings.put(food, newRating);
        String cuisine = foodCuisines.get(food);
        TreeMap<Integer, TreeSet<String>> res = dataStructure.get(cuisine);
        res.get(foodRating).remove(food);
        if(res.get(foodRating).isEmpty())res.remove(foodRating);
        res.putIfAbsent(newRating,new TreeSet<>());
        res.get(newRating).add(food);
        // System.out.println(food+" "+newRating);
    }
    
    public String highestRated(String cuisine) {
        // System.out.println(cuisine);
        // TreeMap<Integer,TreeSet<String>>res=dataStructure.get(cuisine);
        // for(Integer i:res.keySet()){
        //     System.out.print(i+" ");
        // }
        // System.out.println();
        return dataStructure.get(cuisine).get(dataStructure.get(cuisine).lastKey()).first();
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */