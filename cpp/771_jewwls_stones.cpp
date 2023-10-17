#include <iostream>
#include <map>

using std::string; 

int numJewelsInStones(string jewels, string stones){
    int counter =0; 

    for(int i =0; i< jewels.size(); ++i){

        for(int j=0; j<stones.size(); ++j){

            if(jewels[i]== stones[j]){
                counter ++;
            }
        }
    }

    return counter; 
}