#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

class Point
{
public:
	Point(char *n, char *add, int y);
	~Point();
	void ShowData() const;
private:
	char* name;
	char* address;
	int year;
};

Point::Point(char *n, char *add, int y)
{
	name = new char[100];
	strncpy(name, n, 100);
	
	address = new char[200];
	strncpy(address, add, 200);

	year = y;
}

Point::~Point()
{
	delete[] name;
	delete[] address;
}

void Point::ShowData() const
{
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Year: " << year << endl;
}

int main()
{
	char *name = new char[100];
	char *address = new char[200];
	int year;

	cout << "Enter name: ";
	cin >> name;
	cout << "Enter address: ";
	cin >> address;
	cout << "Enter year: ";
	cin >> year;
	cout << endl;

    Point *pt = new Point(name, address, year);
	pt->ShowData();

	delete pt;
	delete[] name;
	delete[] address;
	return 0;
}