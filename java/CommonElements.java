import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

class CommonElements {

    public static void main(String[] args) {
        int[] num1 ={4,3,2,3,1};
        int[] num2 ={ 2, 2, 5, 2, 3, 6};


        for(int i : findIntersectionValues(num1, num2)){
            System.out.println(i);
        }
    }

    public static int[] findIntersectionValues(int[] num1, int[] num2){

        if(num1.length ==0 || num2.length==0 ) return new int[]{};
        HashMap<Integer, Integer> map = new HashMap<>();
        int count1 =0;
        int count2 =0;

        for(int i: num2){
           map.put(i, 1);
        }

        for(int i: num1){
            if(map.containsKey(i)){
                count1++;
            }
        }

        map = new HashMap<>();

        for(int i: num1){
            map.put(i, 1);
        }

        for(int i: num2){
            if(map.containsKey(i)){
                count2++;
            }
        }

        return new int[]{count1, count2};

    }
}