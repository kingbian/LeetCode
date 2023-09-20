#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> array;
  int n, q;
  cin >> n >> q;
  int count = 0;
  for (int i = 0; i < n; ++i) {  // reads in cols
    int k;
    cin >> k;
    vector<int> subArray(k);
    for (int j = 0; j < k; ++j) {  // reads in rows
      cin >> subArray[j];
    }
    count++;
    array.push_back(subArray);
  }

  // get the queries

  for (int i = 0; i < q; ++i) {
    int index, subIndex;
    cin >> index >> subIndex;
    cout << array.at(index).at(subIndex) << endl;
  }
}