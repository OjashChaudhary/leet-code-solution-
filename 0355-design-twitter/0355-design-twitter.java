class Twitter {
    private Map<Integer, Set<Integer>> followMap;
    private Map<Integer, List<int[]>> tweetMap;
    private int timestamp;
    
    public Twitter() {
        followMap = new HashMap<>();
        tweetMap = new HashMap<>();
        timestamp = 0;
    }
    
    public void postTweet(int userId, int tweetId) {
        tweetMap.putIfAbsent(userId, new ArrayList<>());
        tweetMap.get(userId).add(new int[]{timestamp, tweetId});
        timestamp++;
    }
    
    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        
        Set<Integer> followees = followMap.getOrDefault(userId, new HashSet<>());
        followees.add(userId);
        
        for (int followeeId : followees) {
            List<int[]> tweets = tweetMap.get(followeeId);
            if (tweets == null) {
                continue;
            }
            
            int n = tweets.size();
            int start = Math.max(0, n - 10);
            
            for (int i = start; i < n; i++) {
                pq.offer(tweets.get(i));
            }
        }
        
        List<Integer> result = new ArrayList<>();
        List<int[]> allTweets = new ArrayList<>();
        
        while (!pq.isEmpty()) {
            allTweets.add(pq.poll());
        }
        
        int limit = Math.min(10, allTweets.size());
        for (int i = 0; i < limit; i++) {
            result.add(allTweets.get(i)[1]);
        }
        
        return result;
    }
    
    public void follow(int followerId, int followeeId) {
        followMap.putIfAbsent(followerId, new HashSet<>());
        followMap.get(followerId).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (followMap.containsKey(followerId)) {
            followMap.get(followerId).remove(followeeId);
        }
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */