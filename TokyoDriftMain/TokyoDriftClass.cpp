//TokyoDriftClass.cpp

#include "TokyoDriftClass.h"


//CHARACTERS

//GET
int TDClassCharacters::getSpeed()
{
	return Speed;
}

int TDClassCharacters::getDistance()
{
	return Distance;
}

int TDClassCharacters::getNitro()
{
	return Nitro;
}

string TDClassCharacters::getName()
{
	return Name;
}

void TDClassCharacters::getStats()
{
	cout << "\t Name: " << TDClassCharacters::getName() << "\n\t Speed: " << TDClassCharacters::getSpeed() << "\n\t Distance: " << TDClassCharacters::getDistance() << "\n\t Nitros left: " << TDClassCharacters::getNitro();
}


//SET
void TDClassCharacters::setSpeed(int cSpeed) {
	Speed = cSpeed;
}

void TDClassCharacters::setDistance(int cDistance) {
	Distance = cDistance;
}

void TDClassCharacters::setNitro(int cNitro) {
	Nitro = cNitro;
}

void TDClassCharacters::setName(string cName) {
	Name = cName;
}

void TDClassCharacters::setBuilder(int cSpeed, int cDistance, int cNitro, string cName) {
	Speed = cSpeed;
	Distance = cDistance;
	Nitro = cNitro;
	Name = cName;
}


//UPDATE
void TDClassCharacters::updateSpeed(int cSpeed) {
	Speed = Speed + cSpeed;
}
void TDClassCharacters::decreaseSpeed(int cSpeed) {
	Speed = Speed - cSpeed;
}

void TDClassCharacters::updateDistance(int cDistance) {
	Distance = Distance + cDistance;
}

void TDClassCharacters::updateNitro(int cNitro) {
	Nitro = Nitro - cNitro;
}






//CAR STATS

//GET
string TDClassCarStats::getBrand()
{
	return Brand;
}
string TDClassCarStats::getModel()
{
	return Model;
}
int TDClassCarStats::getHP()
{
	return HP;
}
int TDClassCarStats::getMaxSpeed()
{
	return MaxSpeed;
}
string TDClassCarStats::getMotor()
{
	return Motor;
}
void TDClassCarStats::getStats()
{
	cout << "\n\n\nMarca: " << TDClassCarStats::getBrand() << "\n\nModelo: " << TDClassCarStats::getModel() << "\n\nPotencia: " << TDClassCarStats::getHP() << "cv \n\nVelocidad maxima: " << TDClassCarStats::getMaxSpeed() << "Km/h \n\nMotor: " << TDClassCarStats::getMotor();
}


//SET
void TDClassCarStats::setBrand(string cBrand) {
	Brand = cBrand;
}

void TDClassCarStats::setModel(string cModel) {
	Model = cModel;
}

void TDClassCarStats::setHP(int cHP) {
	HP = cHP;
}

void TDClassCarStats::setMaxSpeed(int cMaxSpeed) {
	MaxSpeed = cMaxSpeed;
}

void TDClassCarStats::setMotor(string cMotor) {
	Motor = cMotor;
}

void TDClassCarStats::setBuilder(string cBrand, string cModel, int cHP, int cMaxSpeed, string cMotor) {
	Brand = cBrand;
	Model = cModel;
	HP = cHP;
	MaxSpeed = cMaxSpeed;
	Motor = cMotor;
}
