#include <iostream>
using namespace std;

class PupilModel {
	private:
		string FName;
		string LName;
		int Mark[256];
	public:
		int i = 0;
		string getFName();
		string getLName();
  	PupilModel(string str1, string str2);
    PupilModel(int mark);
		void setMark(int m);
		int getMark();
		float getAvMark();
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
	i = mark;
  void setMark(int m);
	float getAvMark();
}

string PupilModel::getFName() { 
	return FName;
}

string PupilModel::getLName() { 
	return LName;
}

void PupilModel::setMark(int m) {
	Mark[i] = m;
	i++;
}

int PupilModel::getMark() {
	return Mark[i];
}

string PupilModel::getFullname() {
	return FName + LName;
}

float PupilModel::getAvMark() {
	float AvMark;
	for (int j = 1; j <= i; j++) {
		AvMark += Mark[j];
	}
	AvMark /= i;
	return AvMark;
}

