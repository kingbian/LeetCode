import java.util.ArrayList;

class MedianFinder {
    ArrayList<Double> list = new ArrayList<>();

    public MedianFinder() {

    }

    public void addNum(int num) {
        list.add((double) num);
    }

    public double findMedian() {


        double ans = 0;
        for (int i = 0; i < list.size(); i++) {

            if(i == list.size() / 2) {
                if (list.size() % 2 == 0) {
                    ans = (list.get(i - 1) + list.get(i)) / 2;
                } else {
                    System.out.println("here");
                    ans = list.get(i);
                }
            }

        }

        return ans;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */