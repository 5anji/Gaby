#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cstring>
#include "PupilModel.cpp"
using namespace std;

// Tools:
void swap(string *str1, string *str2) {
  string temp;
  temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}

bool check_number(string str) {
  for (int i = 2; i < str.length(); i++) {
    if (isdigit(str[i]) == false) return false;
  }
  return true;
}

void eraseFileLine(string path, string eraseLine) {
  string line;
  ifstream fin;

  fin.open(path);
  ofstream temp;
  temp.open("temp.csv");

  while (getline(fin, line)) {
    if ( ! (line.find(eraseLine) != string::npos)) {
      temp << line << endl;
    }
  }

  temp.close();
  fin.close();

  const char *p = path.c_str();
  remove(p);
  rename("temp.csv", p);
}

float findSmallestElement(float arr[], int n) {
  float temp = arr[1];

  for(int i = 1; i <= n; i++) {
    if(temp > arr[i]) {
      temp = arr[i];
    }
  }
  
  return temp;
}

float findLargestElement(float arr[], int n) {
  float temp = arr[1];

  for(int i = 1; i <= n; i++) {
    if(temp < arr[i]) {
      temp = arr[i];
    }
  }

  return temp;
}
// -------------

int st_count;

// Option 1:
void Show_List() {
  ifstream file;
  string line, word, Fullname[128], Pupil_Name[256];
  int n = 0, i = 1, j = 0;

  file.open("pupils_list.csv");
  while (file) {
    LOOP1:
    getline(file, line);
    istringstream ss(line);
    while (getline(ss, word, ',')) {
      if (check_number(word)) goto LOOP1;
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
  string FirstName[256], LastName[256], line, checker = ", ";
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

// Option 4:
void Remove_Pupil() {
  ifstream file;
  string line, word, Fullname[128], Pupil_Name[256], checker, checker1;
  char c;
  int n = 0, i = 1, j = 0;

  file.open("pupils_list.csv");
  while (file) {
    LOOP2:
    getline(file, line);
    istringstream ss(line);
    while (getline(ss, word, ',')) {
      if (check_number(word)) goto LOOP2;
      Pupil_Name[i] = word;
      if ((i % 2 == 0) && (j % 2 == 1)) {
        n++;
        Fullname[n] = Pupil_Name[j] + "," + Pupil_Name[i];
      }      
      i++;
      j++;
    }
  }
  file.close();

  cout << "Input Pupil's Fullname to remove: ";
  cin >> checker >> checker1;
  checker += ", " + checker1;
  for (i = 1; i <= n; i++) {
    if (Fullname[i] == checker) {
      eraseFileLine("pupils_list.csv", checker);
    }
  }
}

// Option 5:
void Add_Mark_1() {
  ifstream file;
  ofstream temp;
  string line, word, Fullname[128], Pupil_Name[256], checker, checker1, mark;
  int n = 0, i = 1, j = 0;

  file.open("pupils_list.csv");
  while (file) {
    LOOP3:
    getline(file, line);
    istringstream ss(line);
    while (getline(ss, word, ',')) {
      if (check_number(word)) goto LOOP3;
      Pupil_Name[i] = word;
      if ((i % 2 == 0) && (j % 2 == 1)) {
        n++;
        Fullname[n] = Pupil_Name[j] + "," + Pupil_Name[i];
      }      
      i++;
      j++;
    }
  }
  file.close();

  cout << "Input Pupil's Fullname to add a mark: ";
  cin >> checker >> checker1;
  checker += ", " + checker1;

  for (i = 1; i <= n; i++) {
    if (Fullname[i] == checker) {
      cout << "Mark: ";
      cin >> mark;
      PupilModel Pupil(stoi(mark));
      Pupil.setMark(stoi(mark));

      file.open("pupils_list.csv");
      temp.open("temp.csv");

      while (getline(file, line)) {
        if ( ! (line.find(checker) != string::npos)) {
          temp << line << endl;
        }
        else {
          temp << line + ", " + mark + "\n";
        }
      }

      temp.close();
      file.close();

      remove("pupils_list.csv");
      rename("temp.csv", "pupils_list.csv");
    }
  }
}

// Option 6:
void Add_Mark_2() {
  ifstream file;
  ofstream temp;
  string line, mark;
  int n = 0, i = 1, j = 0;

  cout << "Mark: ";
  cin >> mark;
  
  file.open("pupils_list.csv");
  temp.open("temp.csv");

  while (getline(file, line)) {
    PupilModel Pupil(stoi(mark));
    Pupil.setMark(stoi(mark));
    temp << line + ", " + mark + "\n";
  }

  temp.close();
  file.close();
  
  remove("pupils_list.csv");
  rename("temp.csv", "pupils_list.csv");
}

// Option 7:
void Show_Full_Info() {
  ifstream file;
  string word, line, Names[128], Pupil_Name[256];
  int n = 0, i = 1, j = 0, Marks[64][128];
  int m = 1, k = 1, temp = 1;

  file.open("pupils_list.csv");
  while(file) {
    getline(file, line);
    istringstream ss(line);
    while (getline(ss, word, ',')) {
      if (check_number(word)) {
        Marks[temp][k] = stoi(word);
        k++;
        m++;
      }
      else {
        Pupil_Name[i] = word;
        if ((i % 2 == 0) && (j % 2 == 1)) {
          n++;
          PupilModel Pupil(Pupil_Name[j], Pupil_Name[i]);
          Names[n] = Pupil.getFullname();
        }      
        i++;
        j++;
        
      }
      
    }
    temp++;    
  }

  
  for (i = 1; i <= n; i++) {
    cout << "Fullname: ";
    cout << Names[i];
    cout << endl;
    cout << "Marks: ";
    for (k = 1; k <= m; k++) {
      if (Marks[i][k] != 0) {
        cout << Marks[i][k] << " ";
      }
    }
    cout << endl;
  }

  file.close();
}

// Option 8:
void Show_MidMark() {
  ifstream file;
  string word, line;
  int temp = 0;
  float mark = 0;

  file.open("pupils_list.csv");
  while(file) {
    getline(file, line);
    istringstream ss(line);
    while (getline(ss, word, ',')) {
      if (check_number(word)) {
        mark += stoi(word);
        temp++;
      }
    }
  }
  
  mark /= temp;
  cout << "Class Mark is: " << mark << endl;
  
  file.close();
}

// Option 9:
void Show_Max_MidMark() {
  ifstream file;
  string word, line, Names[128], Pupil_Name[256];
  int n = 0, i = 1, j = 0, Marks[64][128];
  int m = 1, k = 1, temp = 1;
  float tempMark[32], MarkChecker;

  file.open("pupils_list.csv");
  while(file) {
    getline(file, line);
    istringstream ss(line);
    while (getline(ss, word, ',')) {
      if (check_number(word)) {
        Marks[temp][k] = stoi(word);
        k++;
        m++;
      }
      else {
        Pupil_Name[i] = word;
        if ((i % 2 == 0) && (j % 2 == 1)) {
          n++;
          PupilModel Pupil(Pupil_Name[j], Pupil_Name[i]);
          Names[n] = Pupil.getFullname();
        }      
        i++;
        j++;
      }
    }
    temp++;    
  }

  for (i = 1; i <= n; i++) {
    temp = 0;
    for (k = 1; k <= m; k++) {
      if (Marks[i][k] != 0) {
        tempMark[i] += Marks[i][k];
        temp++;
      }
    }
    tempMark[i] /= temp;
  }

  MarkChecker = findLargestElement(tempMark, n);
  
  for (i = 1; i <= n; i++) {
    if (MarkChecker == tempMark[i]) {
      cout << Names[i] << endl; 
    }
  }
  file.close();
}

// Option 10:
void Show_Min_MidMark() {
  ifstream file;
  string word, line, Names[128], Pupil_Name[256];
  int n = 0, i = 1, j = 0, Marks[64][128];
  int m = 1, k = 1, temp = 1;
  float tempMark[32], MarkChecker;

  file.open("pupils_list.csv");
  while(file) {
    getline(file, line);
    istringstream ss(line);
    while (getline(ss, word, ',')) {
      if (check_number(word)) {
        Marks[temp][k] = stoi(word);
        k++;
        m++;
      }
      else {
        Pupil_Name[i] = word;
        if ((i % 2 == 0) && (j % 2 == 1)) {
          n++;
          PupilModel Pupil(Pupil_Name[j], Pupil_Name[i]);
          Names[n] = Pupil.getFullname();
        }      
        i++;
        j++;
      }
    }
    temp++;    
  }

  for (i = 1; i <= n; i++) {
    temp = 0;
    for (k = 1; k <= m; k++) {
      if (Marks[i][k] != 0) {
        tempMark[i] += Marks[i][k];
        temp++;
      }
    }
    tempMark[i] /= temp;
  }

  MarkChecker = findSmallestElement(tempMark, n);
  
  for (i = 1; i <= n; i++) {
    if (MarkChecker == tempMark[i]) {
      cout << Names[i] << endl; 
    }
  }
  file.close();
}

// Option 11:
void Higher_X() {
  ifstream file;
  string word, line, Names[128], Names1[128], Pupil_Name[256];
  int n = 0, i = 1, j = 0, Marks[64][128];
  int m = 1, k = 1, temp = 1;
  float tempMark[32], MarkChecker;

  file.open("pupils_list.csv");
  while(file) {
    getline(file, line);
    istringstream ss(line);
    while (getline(ss, word, ',')) {
      if (check_number(word)) {
        Marks[temp][k] = stoi(word);
        k++;
        m++;
      }
      else {
        Pupil_Name[i] = word;
        if ((i % 2 == 0) && (j % 2 == 1)) {
          n++;
          PupilModel Pupil(Pupil_Name[j], Pupil_Name[i]);
          Names[n] = Pupil.getFullname();
        }      
        i++;
        j++;
      }
    }
    temp++;    
  }

  for (i = 1; i <= n; i++) {
    temp = 0;
    for (k = 1; k <= m; k++) {
      if (Marks[i][k] != 0) {
        tempMark[i] += Marks[i][k];
        temp++;
      }
    }
    tempMark[i] /= temp;
  }
  
  cout << "Input Mark(float), to show Pupils with Average mark Higher than it: ";
  cin >> MarkChecker;
  temp = 0;
  for (i = 1; i <= n; i++) {
    if (MarkChecker <= tempMark[i]) {
      temp++;
      Names1[temp] = Names[i];
    }
  }
  
  for (i = 2; i <= temp; i++) {
    for (j = 2; j <= temp; j++) {
      if(Names1[j-1] > Names1[j]) {
        swap(Names1[j-1], Names1[j]);
      }
    }
  }

  for (i = 1; i <= temp; i++) {
    cout << Names1[i];
    cout << endl;
  }
  file.close();
}

// Option 12:
void Lower_X() {
  ifstream file;
  string word, line, Names[128], Names1[128], Pupil_Name[256];
  int n = 0, i = 1, j = 0, Marks[64][128];
  int m = 1, k = 1, temp = 1;
  float tempMark[32], MarkChecker;

  file.open("pupils_list.csv");
  while(file) {
    getline(file, line);
    istringstream ss(line);
    while (getline(ss, word, ',')) {
      if (check_number(word)) {
        Marks[temp][k] = stoi(word);
        k++;
        m++;
      }
      else {
        Pupil_Name[i] = word;
        if ((i % 2 == 0) && (j % 2 == 1)) {
          n++;
          PupilModel Pupil(Pupil_Name[j], Pupil_Name[i]);
          Names[n] = Pupil.getFullname();
        }      
        i++;
        j++;
      }
    }
    temp++;    
  }

  for (i = 1; i <= n; i++) {
    temp = 0;
    for (k = 1; k <= m; k++) {
      if (Marks[i][k] != 0) {
        tempMark[i] += Marks[i][k];
        temp++;
      }
    }
    tempMark[i] /= temp;
  }
  
  cout << "Input Mark(float), to show Pupils with Average mark Lower than it: ";
  cin >> MarkChecker;
  temp = 0;
  for (i = 1; i <= n; i++) {
    if (MarkChecker >= tempMark[i]) {
      temp++;
      Names1[temp] = Names[i];
    }
  }
  
  for (i = 2; i <= temp; i++) {
    for (j = 2; j <= temp; j++) {
      if(Names1[j-1] > Names1[j]) {
        swap(Names1[j-1], Names1[j]);
      }
    }
  }

  for (i = 1; i <= temp; i++) {
    cout << Names1[i];
    cout << endl;
  }
  file.close();
}