class RandomizedSet {
    private List<Integer> list;
    private Map<Integer, Integer> indexMap;
    private Random random;
    
    public RandomizedSet() {
        list = new ArrayList<>();
        indexMap = new HashMap<>();
        random = new Random();
    }
    
    public boolean insert(int val) {
        if (indexMap.containsKey(val)) {
            return false;
        }
        
        indexMap.put(val, list.size());
        list.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        if (!indexMap.containsKey(val)) {
            return false;
        }
        
        int index = indexMap.get(val);
        int lastVal = list.get(list.size() - 1);
        
        list.set(index, lastVal);
        indexMap.put(lastVal, index);
        
        list.remove(list.size() - 1);
        indexMap.remove(val);
        
        return true;
    }
    
    public int getRandom() {
        int index = random.nextInt(list.size());
        return list.get(index);
    }
}
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */