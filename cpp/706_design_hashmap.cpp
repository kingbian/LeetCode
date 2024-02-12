#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Naive implementation

// class MyHashMap {

// 	vector<pair<int, int>> hashMap;

// public:
// 	MyHashMap() {
// 	}

// 	void put(int key, int value) {

// 		for (auto& pairs : hashMap) {

// 			if (pairs.first == key) {
// 				pairs.second = value;
// 				return;
// 			}
// 		}

// 		hashMap.push_back(make_pair(key, value));
// 	}

// 	int get(int key) {

// 		for (const auto& pairs : hashMap) {
// 			if (pairs.first == key) {

// 				return pairs.second;
// 			}
// 		}

// 		return -1;
// 	}

// 	void remove(int key) {

// 		auto& ref = hashMap;
// 		for (auto it = hashMap.begin(); it != hashMap.end(); ++it) {
// 			if (it->first == key) {
// 				hashMap.erase(it);
// 				return;
// 			}
// 		}
// 	}

// 	void print() {

// 		for (int i = 0; i < hashMap.size(); ++i) {

// 			cout << "Key: " << hashMap[i].first << " Value: " << hashMap[i].second << endl;
// 		}
// 	}
// };

// Optimized

class MyHashMap {
	int hashMap[1000001];  // 10^4 calls at most

public:
	MyHashMap() {

		for (int i = 0; i < 1000001; ++i) {
			hashMap[i] = -1;
		}
	};

	void put(int key, int value) {

		hashMap[key] = value;
	}

	int get(int key) {

		int result = hashMap[key];
		if (result == -1) return -1;

		return result;
	}

	void remove(int key) {

		hashMap[key] = -1;
	}
};

int main() {

	MyHashMap* map = new MyHashMap;

	map->remove(1);
	map->put(1, 1);
	cout << "Added\n";
	map->put(2, 4);
	cout << "Added\n";
	map->put(3, 2);
	cout << "Added\n";
	map->put(4, 1);
	cout << "Added\n";
	map->put(4, 7);
	cout << "Added\n";
	map->put(5, 2);
	cout << "Added\n";
	map->put(6, 6);
	cout << "Added\n";
	map->put(8, 3);
	cout << "Added\n";
	map->put(7, 4);

	cout << "Added\n";
	map->print();

	cout << "Returned value for key: 8 is value: " << map->get(8) << endl;

	map->remove(4);
	map->print();

	cout << "Returned value for key: 4 is value: " << map->get(4) << endl;
	map->print();

	delete map;
	return 0;
}