#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int findPair(int currSpell, const vector<int>& potions,
                   long long success) {

  int low = 0;
  int high = potions.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    long long product =(long long) potions[mid] * currSpell;

    if (product >= success) {
        
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
    
  return potions.size()-1-high;;
}

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                            long long success) {
  vector<int> pairs;

  sort(potions.begin(), potions.end());
  cout << endl;

  for (int i = 0; i < spells.size(); ++i) {
    int pair = 0;

  
    pair = findPair(spells[i], potions, success);

    pairs.push_back(pair);
  }


  return pairs;
}

signed main() {
  vector<int> spells{3,1,2};
  vector<int> potion{8,5,8};
  successfulPairs(spells, potion, 16);

  //  cout<<"[";
  //   for(int i: ){

  //     cout<<i<<",";
  //   }
  //    cout<<"]"<<endl;
}