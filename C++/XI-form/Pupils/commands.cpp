#include <iostream>
#include <fstream>
#include <sstream>
#include "PupilModel.cpp"
using namespace std;

// Tools:
void swap(string *str1, string *str2) {
  string temp;
  temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}

int st_count;
string Pupil_Name[100], FirstName[100], LastName[100];

// Option 1:
void Show_List() {
  ifstream file;
  string line, word, Fullname[50], temp;
  int n = 0, i = 1, j = 0;

  file.open("pupils_list.csv");
  while (file) {
    getline(file, line);
    istringstream ss(line);
    while (getline(ss, word, ',')) {
      Pupil_Name[i] = word;
      if ((i % 2 == 0) && (j % 2 == 1)) {
        n++;
        PupilModel Pupil(Pupil_Name[j], Pupil_Name[i]);
        Fullname[n] = Pupil.getFullname();
      }      
      i++;
      j++;
    }
  }
  
  for (i = 2; i <= n; i++) {
    for (j = 2; j <= n; j++) {
      if(Fullname[j-1] > Fullname[j]) {
        swap(Fullname[j-1], Fullname[j]);
      }
    }
  }
  
  for (i = 1; i <= n; i++) {
    cout << Fullname[i];
    cout << endl;
  }
  file.close();
}

// Option 2:
void Add_Pupil_Info_1() {
  string First_Name, Last_Name;
  fstream file;

  file.open("pupils_list.csv", ios::out | ios::app);
  cout << "Enter First name of the student: ";
  cin >> First_Name;
  cout << "Enter Last name of the student: ";
  cin >> Last_Name;
  PupilModel Pupil(First_Name, Last_Name);
  file << Pupil.getFName() << ", " << Pupil.getLName();
  file << "\n";
  st_count++;
  file.close();
}

// Option 3:
void Add_Pupil_Info_2() {
  fstream file1, file2;
  string line, checker = ", ";
  stringstream s(line);
  int i;

  file1.open("input_info.csv");
  for (st_count = 0; getline(file1, line); st_count++);
  file1.close();

  file1.open("input_info.csv");
  while (!file1.eof() && i <= st_count) {
    getline(file1, FirstName[i], ',');
    getline(file1, LastName[i]);
    file2.open("pupils_list.csv", ios::out | ios::app);
    PupilModel Pupil(FirstName[i], LastName[i]);
    file2 << Pupil.getFName() << "," << Pupil.getLName();
    file2 << "\n";
    file2.close();    
    i++;
  }
  file1.close();
}