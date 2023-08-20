import java.util.*;

public class GroupAnagrams {
    public static void main(String[] args) {

        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

        System.out.println(groupAnagrams(strs));


    }


    static public List<List<String>> groupAnagrams(String[] strs) {

        Map<String, ArrayList<String>> map = new HashMap<>();



        if(strs.length==0){
            return new ArrayList<>();
        }



        for(String i : strs){
            char[] curr = i.toCharArray();
            Arrays.sort(curr);
            String key = new String(curr);

            if(!map.containsKey(key)){
                map.put(key,new ArrayList<>());
            }

            map.get(key).add(i);
        }

        return new ArrayList<>(map.values());
    }
}
