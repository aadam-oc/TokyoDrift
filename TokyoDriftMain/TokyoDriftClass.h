//TokyoDriftClass.h
#pragma once
#include <iostream>

using namespace std;

class TDClassCharacters
{
private:
	int Speed;
	int Distance;
	int Nitro;
	string Name;

public:
	int getSpeed();
	int getDistance();
	int getNitro();
	string getName();
	void getStats();
	void setSpeed(int cSpeed);
	void updateSpeed(int cSpeed);
	void decreaseSpeed(int cSpeed);
	void setDistance(int cDistance);
	void updateDistance(int cDistance);
	void setNitro(int cNitro);
	void updateNitro(int cNitro);
	void setName(string cName);
	void setBuilder(int cSpeed, int cDistance, int cNitro, string cName);
};


class TDClassCarStats
{
private:
	string Brand;
	string Model;
	int HP;
	int MaxSpeed;
	string Motor;

public:
	string getBrand();
	string getModel();
	int getHP();
	int getMaxSpeed();
	string getMotor();
	void getStats();
	void setBrand(string cBrand);
	void setModel(string cModel);
	void setHP(int cHP);
	void setMaxSpeed(int cMaxSpeed);
	void setMotor(string cMotor);
	void setBuilder(string cBrand, string cModel, int cHP, int cMaxSpeed, string cMotor);
};

