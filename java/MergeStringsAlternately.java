public class MergeStringsAlternately {

    public static void main(String[] args) {

        System.out.println(mergeAlternately("abcd", "pq"));
    }

    public static String mergeAlternately(String word1, String word2) {
        // String result = "";
        // int sizeWord2 = word2.length();
        // int i=0;
        //
        // for(; i<word1.length(); ++i){
        //
        // result += word1.charAt(i);
        // if(i<word2.length()){
        // result += word2.charAt(i);
        // }else {
        // return result.concat(word1.substring(i+1, word1.length()));
        // }
        //
        // }
        // if(i<word2.length()){
        // return result.concat(word2.substring(i, word2.length()));
        // }
        // return result;

        /**
         * better implementation
         */
        int n = word1.length();
        int m = word2.length();
        int i = 0;

        StringBuilder result = new StringBuilder();
        while (i < n || i < m) {

            if (i < n) {// add word1 to result
                result.append(word1.charAt(i));
            }
            if (i < m) {// add word2 to result
                result.append(word2.charAt(i));
            }
            i++;
        }

        return result.toString();

    }

}
