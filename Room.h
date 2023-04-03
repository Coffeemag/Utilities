#pragma once

class Tenant;
class Counter;

class Room
{
private:
	const char * _roomNumber {0};
	double _square {0.0};
	Counter* _countIdEnergy = nullptr;
	Counter* _countIdWater = nullptr;
	Tenant * _tenant = nullptr;
public:
	Room (const char * num): _roomNumber(num), _square(0.0){}
	Room (const char * num, double sqr): _roomNumber(num), _square(sqr) {}
	const char* getRoom()const { return _roomNumber; }
	void setSquare(double sq) { this->_square = sq; }
	void addCounterEnergy(Counter* cnt) { this->_countIdEnergy = cnt; }
	void addCounterWater(Counter* cnt) { this->_countIdWater = cnt; }
	void setTenant(Tenant* tn) { this->_tenant = tn; }
	~Room(){}
};

