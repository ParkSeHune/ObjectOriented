#include <iostream>

using namespace std;

class Point
{
public:
	Point();
	Point(int X, int Y);
	~Point();
	int GetX() { return x; }
	int GetY() { return y; }

private:
	int x;
	int y;
};

Point::Point()
{
}

Point::Point(int X, int Y)
{
	x = X;
	y = Y;
}

Point::~Point()
{
}

class Rectangle
{
private:
	Point p1;
	Point p2;
	int width;
	int height;
	int area;
public:
	Rectangle(Point point1, Point point2);
	~Rectangle();
	void calArea();
};

Rectangle::Rectangle(Point point1, Point point2)
{
	p1 = point1;
	p2 = point2;
}

Rectangle::~Rectangle()
{
}

void Rectangle::calArea()
{
	if (p1.GetX() >= p2.GetX())
	{
		width = p1.GetX() - p2.GetX();
	}
	else
	{
		width = p2.GetX() - p1.GetX();
	}

	if (p1.GetY() >= p2.GetY())
	{
		height = p1.GetY() - p2.GetY();
	}
	else
	{
		height = p2.GetY() - p1.GetY();
	}

	area = width * height;

	cout << "Area: " << area << endl;
}

int main()
{
	Point p1(10, 2);
	Point p2(4, 5);

	Rectangle rect(p1, p2);
	rect.calArea();

	return 0;
}