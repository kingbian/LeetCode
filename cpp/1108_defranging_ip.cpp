#include <iostream>
#include <string>



std::string defangIPaddr(std::string address){

    std::string result=""; 
   for(int i=0; i< address.size(); ++i){

        if(address.at(i)== '.'){
            result +="[.]";
        }else{
            result += address.at(i);
        }
   }

    // for(char i : result){
    //     std::cout<<i; 
    // }
    // std::cout<<std::endl;

return result; 
    
}


int main(){
    using namespace std; 
    defangIPaddr("1.1.1.1");

    return 0;
}

