#pragma once

class Room;

class Counter
{
private:
	const char* _numberCount{};
	bool _isWater{ false };
	double _startValue{0.0};
	Room * _roomId = nullptr;
public:
	Counter(){}
	Counter(const char * name, bool type): _numberCount(name), _isWater(type){}
	Counter(const char* name, bool type, double val, Room * rm )
	{
		this->_numberCount = name;
		this->_isWater = type;
		this->_startValue = val;
		this->_roomId = rm;
	}
	void attachRomm(Room* rm) { this->_roomId = rm; }
	void setValue(double val) { this->_startValue = val; }
	void setWaterCounter(bool wt) { this->_isWater = true; }
	~ Counter(){}
};

