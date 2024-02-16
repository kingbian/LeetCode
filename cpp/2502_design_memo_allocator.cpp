#include <iostream>
#include <vector>

using namespace std;

class Allocator {
	vector<int> memory;

public:
	Allocator(int n) : memory(n, -1) {
	}

	int allocate(int size, int mID) {
		int track = 0;
		auto i = 0;
		for (; i < memory.size(); ++i) {
			if (track == size) break;
			if (memory[i] == -1) {
				track++;
			} else {
				track = 0;
			}
		}

		if (track == size) {

			for (int j = i - track; j < i; ++j) {
				memory[j] = mID;
			}

			return i - track;  // first index of mID
		}

		return -1;	// unable to allocate
	}

	int free(int mID) {
		int counter = 0;

		for (int i = 0; i < memory.size(); ++i) {
			if (memory[i] == mID) {
				counter++;
				memory[i] = -1;
			}
		}

		return counter;
	}

	void print() {
		for (int i = 0; i < memory.size(); ++i) {

			cout << i << " : mID: " << memory[i] << "\n";
		}
	}
};

int main() {
	Allocator allocator(10);

	// Manual allocation and freeing
	int index1 = allocator.allocate(1, 1);
	cout << "Allocated at index: " << index1 << endl;

	int index2 = allocator.allocate(1, 2);
	cout << "Allocated at index: " << index2 << endl;

	int index3 = allocator.allocate(1, 3);
	cout << "Allocated at index: " << index3 << endl;

	int freedBlocks = allocator.free(2);
	cout << "Freed " << freedBlocks << " blocks." << endl;

	int index4 = allocator.allocate(3, 4);
	cout << "Allocated at index: " << index4 << endl;

	int index5 = allocator.allocate(1, 1);
	cout << "Allocated at index: " << index5 << endl;

	freedBlocks = allocator.free(1);
	cout << "Freed " << freedBlocks << " blocks." << endl;

	allocator.print();

	// Additional sequence of operations
	cout << "Additional sequence of operations:\n";
	index1 = allocator.allocate(10, 2);
	cout << "Allocated at index: " << index1 << endl;

	freedBlocks = allocator.free(7);
	cout << "Freed " << freedBlocks << " blocks." << endl;

	allocator.print();
	return 0;
}