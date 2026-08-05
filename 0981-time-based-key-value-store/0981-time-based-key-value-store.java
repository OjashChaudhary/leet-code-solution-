class TimeMap {
    HashMap<String, ArrayList<String[]>> map = new HashMap<>();

    public TimeMap() {
    }

    public void set(String key, String value, int timestamp) {
        map.putIfAbsent(key, new ArrayList<>());
        map.get(key).add(new String[]{value, String.valueOf(timestamp)});
    }

    public String get(String key, int timestamp) {
        if (!map.containsKey(key)) return "";

        ArrayList<String[]> list = map.get(key);
        int left = 0, right = list.size() - 1;
        String ans = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int time = Integer.parseInt(list.get(mid)[1]);

            if (time <= timestamp) {
                ans = list.get(mid)[0];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
}