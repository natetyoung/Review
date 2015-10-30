#include <iostream>
#include <ctime>
using namespace std;

class TestObj{
private:
	int val;
public:
	TestObj(int a){val = a;}
	void printTimeAndValue();
	void setValue(int val);
};
void TestObj::printTimeAndValue(){
	time_t curTime;
	time(&curTime);
	cout << "Value was "<<val <<" at "<< curTime;
}
void TestObj::setValue(int val){
	(*this).val = val;
}