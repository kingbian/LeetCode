#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverseString(vector<char>& s){

    
    int end= s.size()-1; 

    for(int i=0; i<s.size()/2; ++i){

        // if(i==end){
        //     break;
        // }
        char temp = s[i]; 
        s[i] = s[end]; 
        s[end] = temp; 
        end--; 
    }

    for( auto i : s){
        cout<<i<<","; 
    }

}


int main(){

    vector<char> s {'h','e','l','l','o'};

    reverseString(s);
}