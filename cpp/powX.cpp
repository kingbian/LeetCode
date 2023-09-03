#include <iostream>

/**
 * QUESTION:given two integers x and n what is x^n
 *
 * this is a recursive approach
 */



long pow(long x, long n) {
  if (n == 0) return 1;

  if (n % 2 == 0) {
    long y = pow(x, n / 2);
    return y *= y;
  }else
    return x * pow(x, n - 1);
}

int main(){

    std::cout<<pow(5,5)<<std::endl;

}