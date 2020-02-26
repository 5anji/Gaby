#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PupilModel.cpp"
using namespace std;

int count;

// Option 1: -- needs fixes
void Show_List() {
  ifstream file;
  string line;
  int i;

  file.open("pupils_list.csv");
  for (count = 0; getline(file, line); count++);
  if (count == 0) {
    cout << "--|There is no students|--" << endl;
  }
    // needs fixes:
  // else {
  //   while (file.good()) {
  //     for (i = 1; i <= count; i++) {
  //       getline(file, Pupil_Name[i], '\n');
  //       cout << Pupil_Name[i] << endl;
  //     }
  //   }
  // }
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
  fstream file;
  string Pupil, c, FirstName[100], LastName[100], line, checker = ", ";
  stringstream s(line);
  int i;
  file.open("input_info.csv");
  for (count = 0; getline(file, line); count++);
  file.close();

  // cout << count << endl;

  file.open("input_info.csv");
  while (!file.eof() && i != count) {
    getline(file, FirstName[i], ',');
    getline(file, LastName[i]);
    // cout << FirstName[i] << " - " << LastName[i] << endl;      
    i++;
  }
  file.close();

  

  file.open("pupils_list.csv");
  for (i = 1; i <= count; i++) {
    // PupilModel Stud(FirstName[i], LastName[i]);
    file << /*Stud.getFName()*/FirstName[i] << ", " << /*Stud.getLName()*/LastName[i];
    file << "\n";
    // Pupil_Name[count] = Stud.getFullname();
  }
  file.close();
}