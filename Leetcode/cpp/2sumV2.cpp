#include <iostream>
#include <map>
#include <vector>


/**
 * MAP- IMPLEMENTATION
 * 
 * TIME COMPLEXITY: O(n log n)
 * 
 * not in-place 
*/

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
  std::map<int, int> map;
  std::vector<int> ans; 

  for (int i = 0; i < numbers.size(); i++) {
    
    if(map.count(target-numbers[i])==1){ //find the complement in the map, TIME COMPLEXITY: O(log n)
       
        ans.push_back(map[target-numbers[i]]); //get the index
        ans.push_back(i+1); //current element's index
        return ans;
    }
    
    if(map.count(numbers[i]) !=1){ // check if element exists TIME COMPLEXITY: O(log n)
         map.insert({numbers[i], i + 1});
    }
  }

  return ans;
}

/**
 * TWO POINTER IMPLEMENTATION
 * 
 * use pointer one to point to the left side of the array and the right pointer 
 * to point to the end of the array.
 * 
 * TIME COMPLEXITY: O(n)**BEST for sorted elements
*/
using namespace std;
std::vector<int> twoSumPointer(std::vector<int>& numbers, int target) {
  
  

  int leftPointer =0, rightPointer=numbers.size()-1;

  while(leftPointer<rightPointer){

    int currSum= numbers[leftPointer]+numbers[rightPointer]; //get the current sum of the elements at both pointers
    
 
    if(currSum== target){
     
      return {leftPointer+1, rightPointer+1};
    }else if(currSum<target){
      
      leftPointer++;
    }else{
     
      rightPointer--;
    }
  }

  return {}; 
}

/**
 * Binary-search implementation
 * 
 * TIME COMPLEXITY: O(n log n)
 * 
 * when things are sorted always try a binary search approach 
 * 
*/


vector<int> twoSumBinary(const vector<int>& numbers, int target){

  int low = 1; 
  int high= numbers.size()-1;

  while(low<=high){

    int currIndex=0; 

    int mid= low + (high-low)/2; 
    
    if(numbers[currIndex] + numbers[mid] == target){
      return {currIndex+1, mid+1};
    }else if(numbers[currIndex] + numbers[mid] >target){
      high=mid-1; 
    }else{
      low=mid+1; 
    }

    currIndex++;
  }


  return {};
}

int main(){
    
    std::vector<int> nums{2,7,11,15};
    for(const int& i: twoSumBinary(nums, 9)){
            std::cout<<i<<", ";
    }

    return 0; 
}