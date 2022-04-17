#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Timer.h"
using namespace std;

template<class T>
void Swap(T* a, T* b)
{
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

template<class T>
void SortPointers(vector<T*>a)
{
	for (int i = 0; i < a.size()-1; i++)
	{
		for (int j = i+1; j < a.size(); j++)
		{
			if (*a[i] > *a[j])
			{
				Swap(a[i], a[j]);
			}
		}
	}
}

int Count_if_And_Find(string& s, string& vowes)
{
	return count_if(s.begin(), s.end(), [&vowes](char& c)
		{
			return vowes.find(c) != string::npos;
		});
}

int Count_if_And_For(string& s, string& vowes)
{
	return count_if(s.begin(), s.end(), [&vowes](char& c)
		{
			for (auto& symbol : vowes)
			{
				if (c == symbol)
				{
					return true;
				}
			}
			return false;
		});
}

int For_And_Find(string& s, string& vowes)
{
	int cnt =0;
	for (auto& c : s)
	{
		if (vowes.find(c) != string::npos)
		{
			cnt++;
		}
	}
	return cnt;
}

int For_And_For(string& s, string& vowes)
{
	int cnt =0;
	for (auto& c : s)
	{
		for (auto& search_element : vowes)
		{
			if (c == search_element)
			{
				cnt++;
				break;
			}
		}
	}
	return cnt;
}

void Task3(ifstream& file)
{
	int64_t quantity=0;
	file.seekg(0, std::ios::end);
	size_t size = file.tellg();
	file.seekg(0);
	string s(size, ' ');
	file.read(&s[0], size);

	string vw = "АЕЁИОУЫЭЮЯаеёиоуыэюя";
	Timer t;
	int cnt;
	t.start("Count_if and find");
	cnt = Count_if_And_Find(s, vw);
	t.print();

	t.start("Count_if and for");
	cnt = Count_if_And_For(s, vw);
	t.print();

	t.start("For and find");
	cnt = For_And_Find(s, vw);
	t.print();

	t.start("For and for");
	cnt = For_And_For(s, vw);
	t.print();
	cout << cnt;
}


void print(vector<int*>arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << *arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	ifstream file("Война и мир.txt");
	Task3(file);
	vector<int*>arr;
	for (int i = 0; i < 10; i++)
	{
		int* t = new int(rand() % 10);
		arr.push_back(t);
	}
	print(arr);
	SortPointers(arr);
	print(arr);

	for (auto i : arr)
	{
		delete i;
	}
}