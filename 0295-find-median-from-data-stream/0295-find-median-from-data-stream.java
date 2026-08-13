import java.util.*;

class MedianFinder {

    PriorityQueue<Integer> small = new PriorityQueue<>(Collections.reverseOrder());
    PriorityQueue<Integer> large = new PriorityQueue<>();

    public MedianFinder() {
    }

    public void addNum(int num) {
        small.add(num);

        if (!large.isEmpty() && small.peek() > large.peek()) {
            large.add(small.poll());
        }

        if (small.size() > large.size() + 1) {
            large.add(small.poll());
        }

        if (large.size() > small.size()) {
            small.add(large.poll());
        }
    }

    public double findMedian() {
        if (small.size() == large.size()) {
            return (small.peek() + large.peek()) / 2.0;
        }

        return small.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */