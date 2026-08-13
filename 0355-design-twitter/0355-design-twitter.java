import java.util.*;

class Twitter {

    class Tweet {
        int id, time;
        Tweet next;

        Tweet(int id, int time) {
            this.id = id;
            this.time = time;
        }
    }

    HashMap<Integer, HashSet<Integer>> follow = new HashMap<>();
    HashMap<Integer, Tweet> tweets = new HashMap<>();
    int time = 0;

    public Twitter() {
    }

    public void postTweet(int userId, int tweetId) {
        Tweet t = new Tweet(tweetId, time++);
        t.next = tweets.get(userId);
        tweets.put(userId, t);
    }

    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<Tweet> pq = new PriorityQueue<>(
            (a, b) -> b.time - a.time
        );

        if (tweets.containsKey(userId)) {
            pq.add(tweets.get(userId));
        }

        if (follow.containsKey(userId)) {
            for (int id : follow.get(userId)) {
                if (tweets.containsKey(id)) {
                    pq.add(tweets.get(id));
                }
            }
        }

        List<Integer> ans = new ArrayList<>();

        while (!pq.isEmpty() && ans.size() < 10) {
            Tweet t = pq.poll();
            ans.add(t.id);

            if (t.next != null) {
                pq.add(t.next);
            }
        }

        return ans;
    }

    public void follow(int followerId, int followeeId) {
        follow.putIfAbsent(followerId, new HashSet<>());
        follow.get(followerId).add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        if (follow.containsKey(followerId)) {
            follow.get(followerId).remove(followeeId);
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