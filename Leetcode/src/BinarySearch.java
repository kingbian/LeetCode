public class BinarySearch {

    public static void main(String[] args) {
        int[] nums = {-1, 0, 3, 5, 9, 12};

        search(nums, 9);
    }

    public static int search(int[] nums, int target) {
        int low = 0;
        int high = nums.length ;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            if (target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;


    }

    public int mySqrt(int x) {

        int low=0;

        int high=x;

        while(low<=high){

            int mid= low +(high+low)/2;

            if(mid*mid == x){
                return (int) Math.floor(mid);
            }

            if(mid*mid <x){
                low= mid+1;
            }
            if(mid*mid > x){
                high= mid -1;
            }


        }
        return -1;
    }
}