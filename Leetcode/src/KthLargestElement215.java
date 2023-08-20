import java.util.Collections;
import java.util.PriorityQueue;

public class KthLargestElement215 {


    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>();

        for(Integer i : nums){
            maxHeap.add(i); // add the current element into the heap

            if(maxHeap.size() >k){ //check if size if > k
                maxHeap.poll(); //pop the element
            }
        }

        return maxHeap.peek(); // return the first element in the heap


    }




}
