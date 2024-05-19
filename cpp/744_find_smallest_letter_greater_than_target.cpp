

#include <iostream>
#include <vector>

/*
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
char nextGreaterLetter(std::vector<char> &letters, char target) {

  int left = 0, right = letters.size() - 1;
  char nextGreater = letters[0]; // initialize with the  first char of letters
  while (left <= right) {

    // get the mid
    int mid = left + (right - left) / 2;

    if (letters[mid] <= target)
      left = mid + 1; // go to the right of the mid point
    else {
      nextGreater = letters[mid];
      right = mid - 1; // go the left of the mid point
    }
  }

  if (nextGreater > target)
    return nextGreater;

  return letters[0];
}

int main() {
  std::vector<char> letters{'e', 'e', 'g', 'g'};

  std::cout << nextGreaterLetter(letters, 'g');
}
