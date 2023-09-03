import javax.lang.model.element.NestingKind;
import javax.sound.midi.SysexMessage;
import java.util.*;

public class TopKFrequent {

    public static void main(String[] args) {

        int[] nums = {4,1,-1,2,-1,2,3};
        int k = 2;

       for(int i:topKFrequent(nums, k)){
            System.out.println(i);
       }


    }


    static public int[] topKFrequent(int[] nums, int k) {

        if (nums.length == 0) {
            return nums;
        }

        Map<Integer, Integer> map = new HashMap<>();
      

        for (int i = 0; i < nums.length; i++) {
            int key = nums[i];
            if (!map.containsKey(key)) {
                map.put(key, 0);
            }
            map.put(key, map.get(key) + 1);
        }

        PriorityQueue<Map.Entry<Integer, Integer>> maxHeap = new PriorityQueue<>( (a, b) -> (b.getValue()- a.getValue()));
        maxHeap.addAll(map.entrySet());



        int[] ans = new int[k];

        for(int i=0; i<k; i++){

            Map.Entry<Integer, Integer> max = maxHeap.poll();

            ans[i]= max.getKey();
        }



        return ans;
    }
}
