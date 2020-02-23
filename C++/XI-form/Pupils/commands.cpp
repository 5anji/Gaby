#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PupilModel.cpp"
using namespace std;

// Option 1:
void Show_List() {
  fstream fin;
  
  fin.open("pupils_list.csv", ios::out | ios::app);
  string line;
  istringstream s(line);
  string field;
  while (getline(s, field,',')) {
    cout << line;
  }
  fin.close();
}

// Option 2:
void Add_Pupil_Info_1() {
  string First_Name, Last_Name;
  fstream fout;
  
  fout.open("pupils_list.csv", ios::out | ios::app);
  
  cout << "Enter First & Last name of the student: ";
  cin >> First_Name >> Last_Name;
  PupilModel Pupil(First_Name, Last_Name);
  fout << Pupil.getFullname() << "\n";
}

