#include <iostream>
using namespace std;

class PupilModel {
	private:
		string FName;
		string LName;
	public:
		string getFName();
		string getLName();
  		PupilModel(string str1, string str2);
    	PupilModel(int mark);
		string getFullname();
};

PupilModel::PupilModel(string str1, string str2) {
	FName = str1;
	LName = str2;
	string getFName();
	string getLName();
	string getFullname();
}

PupilModel::PupilModel(int mark) {
    void setMark(int m);
}

string PupilModel::getFName() { 
	return FName;
}

string PupilModel::getLName() { 
	return LName;
}

string PupilModel::getFullname() {
	return FName + LName;
}