#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PupilModel.cpp"
using namespace std;

int count;
string Pupil_Name[100], FirstName[100], LastName[100];

// Option 1: -- needs fixes
void Show_List() {
  ifstream file;
  string line, checker = ", ";
  int i;

  file.open("pupils_list.csv");
  // cout << count << endl;
  if (count == 0) {
    cout << "--|There is no students|--" << endl;
  }
  else {
    while (file.good()) {
      for (i = 1; i <= count; i++) {
        getline(file, Pupil_Name[i], ',');
        cout << Pupil_Name[i];
      }
    }
  }
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
  string line, checker = ", ";
  stringstream s(line);
  int i;
  file.open("input_info.csv");
  for (count = 0; getline(file, line); count++);
  file.close();

  

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
    // PupilModel Pupil(FirstName[i], LastName[i]);
    file << /*Pupil.getFName()*/FirstName[i] << ", " << /*Pupil.getLName()*/LastName[i];
    file << "\n";
    // Pupil_Name[count] = Stud.getFullname();
  }
  file.close();
}