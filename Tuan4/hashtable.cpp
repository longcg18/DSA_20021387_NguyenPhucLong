#include <iostream>
#include <string>

using namespace std;

struct Student {
	int id;
	string name;
	Student() {};
	Student(int _id, string _name) {
		id = _id;
		name = _name;
	}
};

class Hashtable {
private:
	Student** data;
	int size;
	int current_size;
	int getIndex(int _id) {
		int i = _id % size;
		do {
			if (data[i] != NULL && data[i]->id == _id) return i;
			i++;
			if (i >= size) i -= size;
		} while (i != _id % size);
		return -1;
	}

public:
	Hashtable(int _size = 7) {
		size = _size;
		current_size = 0;
		data = new Student*[size];
		for (int i = 0; i < size; i++) data[i] = NULL;
	}

	bool put(int _id, string _name) {
		if (current_size >= size) return false;
		Student* s = new Student (_id, _name);
		int i = _id % size;
		do {
			if (data[i] == NULL) {
				data[i] = s;
				current_size++;
				return true;
				break;
			}
			i++;
			if (i >= size) i -= size;
		} while (i != _id % size);
		return false;
	}

	bool remove(int _id) {
		int index = getIndex(_id);
		if (index == -1) return false;
		Student* ptr = data[index];
		delete ptr;
		data[index] = NULL;
		current_size--;
		return true;
	}

	string get(int _id) {
		string r = "";
		int index = getIndex(_id);
		if (index == -1) return "NA,NA";
		Student* ptr = data[index];
		r += ptr->name;
		return r;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << "Index " << i << ": ";
			if (data[i] != NULL) {
				cout << data[i]->id << " - " << data[i]->name<< endl;
			} else cout << "NULL\n";
		}
	}

};


int main(int argc, char const *argv[])
{
	return 0;
}
