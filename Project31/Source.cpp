#include <iostream>
using namespace std;
int total = 0;
template<typename T = string, const int MAX_C = 5>

class libraryitem {
	string title;
	int copies[MAX_C];
	inline static int count;
public:
	libraryitem() {
		title = nullptr;
		id = nullptr;
		for (int i = 0; i < MAX_C; i++) {
			copies[i] = 0;
		}
		total++;
	}
	libraryitem(string t)
	{
		title = t;
		for (int i = 0; i < MAX_C; i++) {
			copies[i] = 0;
		}
		total++;
	}
	~libraryitem() {
		total--;
		count = total;
	}
	void addcopy(T i) {
		copies[i] = 1;
	}
	void removecopy(T i) {
		copies[i] = 0;
	}
	int gettotalitems() {
		count = total;
		return count;
	}
	int getcopiescount() {
		int counter = 0;
		for (int i = 0; i < MAX_C; i++) {
			if (copies[i] == 0) {
				counter++;
			}
		}
		return counter;
	}
};

int main() {
	libraryitem<int, 5> obj("original");
	libraryitem<double, 5> obj1("original");
	libraryitem<string, 5> obj2("original");
	obj.addcopy(0);
	cout << obj.gettotalitems() << endl;
	cout << obj.getcopiescount() << endl;
}