import javax.sound.midi.SysexMessage;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class IsAnagram {

    public static void main(String[] args) {
        int[] nums= {2,7,11,15};
        int target =9;

        for(int i: twoSum(nums, target)){
            System.out.println(i);
        }
    }

    static  public boolean isAnagram(String s, String t) {

        char[] arrS = s.toCharArray();
        Arrays.sort(arrS);
        char[] arrT = t.toCharArray();
        Arrays.sort(arrT);

       int ans= Arrays.compare(arrT, arrS);

       if(ans== 0) return true;


    return false;
    }

    static public int[] twoSum(int[] nums, int target) {

        HashMap<Integer, Integer> map = new HashMap<>();
        int[] res=null;
        for(int i =0; i<nums.length; i++){
            int complement= target- nums[i];

            if(map.containsKey(complement) ){
                return new int[] {map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        return null;
    }


}
