// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/*
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

int firstBadVersion(int n) {
  int left = 0, right = n, foundBadVersion = 0;

  while (left <= right) {

    int mid = left + (right - left) / 2;

    if (isBadVersion(mid) != true)
      left = mid + 1;
    else {
      foundBadVersion = mid;
      right = mid - 1;
    }
  }

  return foundBadVersion;
}
