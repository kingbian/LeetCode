#include <iostream> 
#include <vector>

using namespace std; 

int richestCustomer(const vector<vector<int>>& accounts ){

    int richest =0; 

    for(int i=0; i<accounts.size(); ++i){
        int amount=0; 
        for(int j=0; j<accounts.at(i).size(); ++j){
            amount += accounts.at(i).at(j);
        }
        if(amount> richest){
            richest = amount;
        }
    }
    return richest; 
}