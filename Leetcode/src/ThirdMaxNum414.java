import java.util.*;

public class ThirdMaxNum414 {

    public int thirdMax(int[] nums) {
       PriorityQueue<Integer> numQ = new PriorityQueue<>();

        Iterator<Integer> test= numQ.iterator();


       for(Integer i: nums){
           numQ.add(i);
       }


       if(numQ.size()<3){

       }
return 1;
    }
}
