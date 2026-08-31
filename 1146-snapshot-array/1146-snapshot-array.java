class SnapshotArray {
    private List<TreeMap<Integer, Integer>> history;
    private int snapId;
    
    public SnapshotArray(int length) {
        history = new ArrayList<>();
        snapId = 0;
        
        for (int i = 0; i < length; i++) {
            TreeMap<Integer, Integer> map = new TreeMap<>();
            map.put(0, 0);
            history.add(map);
        }
    }
    
    public void set(int index, int val) {
        history.get(index).put(snapId, val);
    }
    
    public int snap() {
        snapId++;
        return snapId - 1;
    }
    
    public int get(int index, int snap_id) {
        Map.Entry<Integer, Integer> entry = history.get(index).floorEntry(snap_id);
        return entry.getValue();
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */