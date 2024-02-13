#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

/**
 *  Fibonacci Recursively
 */
int fibRecursive(int n) {

	if (n <= 1) return n;

	return fibRecursive(n - 1) + fibRecursive(n - 2);
}

/**
 * Dynamic Programming
 */
int fibDynamic(int n) {

	vector<int> fibonacci(n + 1);
	fibonacci[0] = 0;
	fibonacci[1] = 1;

	for (int i = 2; i <= n; ++i) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	return fibonacci[n];
}
