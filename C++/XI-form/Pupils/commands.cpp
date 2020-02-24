#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PupilModel.cpp"
using namespace std;

int count;

// Option 1:
void Show_List() {
  ifstream fin;
  
  fin.open("pupils_list.csv");
  string Pupil_Name[100];
  int i;
  while (fin.good()) {
    for (i = 1; i <= count; i++) {
      getline(fin, Pupil_Name[i], ',');
      cout << Pupil_Name[i];
    }
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
  fout << Pupil.getFullname();
  fout << "\n";
  count++;
}

