#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <chrono>
using namespace std;

void check_set(int count) {
	set<int> myset;

	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < count; ++i)
		myset.insert(i);
	auto finish = std::chrono::high_resolution_clock::now();
	cout << "set add all -> " << count << " -> " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << endl;

	start = chrono::high_resolution_clock::now();
	myset.insert(count);
	finish = std::chrono::high_resolution_clock::now();
	cout << "set add -> " << count << " -> " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << endl;

	start = chrono::high_resolution_clock::now();
	set<int>::iterator it = myset.find(count * 0.703);
	finish = std::chrono::high_resolution_clock::now();
	cout << "set find -> " << count << " -> " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << endl;
}

void check_unordered_set(int count) {
	unordered_set<int> myset;
	clock_t t;

	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < count; ++i)
		myset.insert(i);
	auto finish = std::chrono::high_resolution_clock::now();
	cout << "unordered_set add all -> " << count << " -> " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << endl;

	start = chrono::high_resolution_clock::now();
	myset.insert(count);
	finish = std::chrono::high_resolution_clock::now();
	cout << "unordered_set add -> " << count << " -> " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << endl;

	start = chrono::high_resolution_clock::now();
	unordered_set<int>::iterator it = myset.find(count * 0.703);
	finish = std::chrono::high_resolution_clock::now();
	cout << "unordered_set find -> " << count << " -> " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << endl;
}

int main()
{
	check_set(1000);
	check_set(10000);
	check_set(100000);
	check_set(1000000);

	check_unordered_set(1000);
	check_unordered_set(10000);
	check_unordered_set(100000);
	check_unordered_set(1000000);

	getchar();
	return 0;
}