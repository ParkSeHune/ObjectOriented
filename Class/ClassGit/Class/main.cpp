#include <iostream>
#include <string>

using namespace std;

class Car
{
public:
	Car(string id);
	~Car();

private:
	string gamerID;
	int fuelGauge;
	int curSpeed;
	char input;

	public:
		void Accel();
		void Break();
		void ShowState() const;
		void Game();
};

Car::Car(string id)
{
	gamerID = id;
	curSpeed = 0;
	fuelGauge = 1000;
}

Car::~Car()
{
}

void Car::Accel()
{
	if (fuelGauge <= 0)
	{
		return;
	}
	else
	{
		fuelGauge -= 1;
	}

	if (curSpeed + 10 >= 180)
	{
		curSpeed = 180;
	}
	else
	{
		curSpeed += 10;
	}
}

void Car::Break()
{
	if (fuelGauge <= 0)
	{
		return;
	}
	else
	{
		fuelGauge -= 1;
	}

	if (curSpeed >= 0)
	{
		curSpeed = 0;
	}
	else
	{
		curSpeed = 0;
	}
}

void Car::ShowState() const
{
	cout << "fuelGauge: " << fuelGauge << endl;
	cout << "curSpeed: " << curSpeed << endl << endl;
}

void Car::Game()
{
	cout << "a, b, s. �� �ϳ��� �Է� �� �ֽʽÿ�." << endl;
	cout << "a: Accel, b: Break, s: ShowState" << endl << endl;

	while (fuelGauge > 0)
	{
		cin >> input;

		if (input == 'a')
		{
			Accel();
			ShowState();
		}
		else if (input == 'b')
		{
			Break();
			ShowState();
		}
		else if (input == 's')
		{
			ShowState();
		}
		else
		{
			cout << "�߸��� Ű�� �Է��Ͽ����ϴ�. a, b, s. �� �ϳ��� �Է� �� �ֽʽÿ�." << endl;
		}

		if (fuelGauge <= 0)
		{
			break;
			cout << "���� ����" << endl;
		}
	}
}

int main() 
{
	string userID;
	cout << "���̸� ���̵� �Է�: ";
	cin >> userID;
	cout << endl;

	Car myCar(userID);
	cout << "���̸� ���̵�: " << userID << endl;

	myCar.Game();

	return 0;
}	