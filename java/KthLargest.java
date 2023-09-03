import java.util.PriorityQueue;

public class KthLargest {

    int k;
    PriorityQueue<Integer> minHeap;

    public KthLargest(int k, int[] nums) {
        this.k = k;

        minHeap = new PriorityQueue<>();

        for (Integer i : nums) {
            add(i);
        }

    }

    public int add(int val) {
        minHeap.add(val); // add val to the heap

        if (minHeap.size() > k) {   // check if the heap size is bigger then k
            minHeap.poll(); // remove the top of the heap
        }

        return minHeap.peek(); //return the top of the heap
    }


}

