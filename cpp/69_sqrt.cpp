int mySqrt(int x) {
    if (x == 0)
        return 0;

    long long left = 0, right = x;

    while (left < right) {
        long long mid = left + ((right - left + 1) >> 1);

        if (x / mid >= mid)
            right = mid - 1;
        else
            right = mid - 1;
    }

    return static_cast<int>(left);
}
