#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PupilModel.cpp"
using namespace std;

// cout << count << endl;

int count;
string FirstName[100], LastName[100];

// Option 1: -- needs fixes
void Show_List() {
  ifstream file;
  string line, Pupil_Name;
  int i = 0;

  file.open("pupils_list.csv");
  while (file) {
    getline(file, line);
    istringstream ss(line);
    while (getline(ss, Pupil_Name, ',')) {
      if (i == 2) {
        cout << endl;
        i = 0;
      }
      cout << Pupil_Name;
      i++;
    }
  }  
  cout << endl;
  file.close();
}

// Option 2:
void Add_Pupil_Info_1() {
  string First_Name, Last_Name;
  fstream file;

  file.open("pupils_list.csv", ios::out | ios::app);
  cout << "Enter First & Last name of the student: ";
  cin >> First_Name >> Last_Name;
  PupilModel Pupil(First_Name, Last_Name);
  file << Pupil.getFName() << ", " << Pupil.getLName();
  file << "\n";
  count++;
  file.close();
}

// Option 3: -- works fine -- not enough
void Add_Pupil_Info_2() {
  fstream file1, file2;
  string line, checker = ", ";
  stringstream s(line);
  int i;

  file1.open("input_info.csv");
  for (count = 0; getline(file1, line); count++);
  file1.close();

  file1.open("input_info.csv");
  while (!file1.eof() && i <= count) {
    getline(file1, FirstName[i], ',');
    getline(file1, LastName[i]);
    cout << FirstName[i] << " -" << LastName[i] << endl;
    file2.open("pupils_list.csv", ios::out | ios::app);
    PupilModel Pupil(FirstName[i], LastName[i]);
    file2 << Pupil.getFName() << "," << Pupil.getLName();
    file2 << "\n";
    // Pupil_Name[count] = Pupil.getFullname();
    file2.close();    
    i++;
  }
  file1.close();
}