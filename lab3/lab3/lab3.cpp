#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
using namespace std;

void check_vector(int count, bool useReserve = false)
{
	vector<int> v;

	if (useReserve) v.reserve(count);

	for (int i = 0; i < count; i++)
	{
		v.push_back(i);
	}

	int size1 = v.size();

	auto start = chrono::high_resolution_clock::now();
	v.erase(remove(v.begin(), v.end(), count * 0.703));
	auto finish = std::chrono::high_resolution_clock::now();
	cout << "removed: " << size1 - v.size() << ", ";
	string s = (useReserve ? "(reserve)" : "");
	cout << "vector" << s << " remove -> " << count << " -> " << chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << endl;
}

void check_list(int count)
{
	list<int> l;
	for (int i = 0; i < count; i++)
	{
		l.push_back(i);
	}
	int size1 = l.size();
	
	auto start = chrono::high_resolution_clock::now();
	l.erase(remove(l.begin(), l.end(), count * 0.703));
	auto finish = std::chrono::high_resolution_clock::now();

	cout << "removed: " << size1 - l.size() << ", ";
	cout << "list remove -> " << count << " -> " << chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << endl;
}

void show_list(list<int>&a)
{
	for (const auto & item : a)
	{
		cout << item << " ";
	}
}


int main()
{
	/*list<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "size before: " << v.size() <<endl;
	show_list(v);
	auto it = remove(begin(v), end(v), 5);
	cout << endl << "size after: " << v.size() << endl;
	show_list(v);

	v.erase(it);
	cout << endl << "size erase after: " << v.size() << endl;
	show_list(v);

	getchar();
	return 0;*/

	check_vector(1000);
	check_vector(10000);
	check_vector(100000);
	check_vector(1000000);
	check_vector(10000000);

	check_vector(1000, true);
	check_vector(10000, true);
	check_vector(100000, true);
	check_vector(1000000, true);
	check_vector(10000000, true);

	check_list(1000);
	check_list(10000);
	check_list(100000);
	check_list(1000000);
	check_list(10000000);

	getchar();
	return 0;
}