#include <iostream>
#include <string>
#include <fstream>
#include "commands.h"

using namespace std;

int main() {
  short int checker;
  
  do {
    cout << "\033[31m 1\033[0m - Show pupils list" << endl;
    cout << "\033[31m 2\033[0m - Add a pupil information from CMD" << endl;
    cout << "\033[31m 3\033[0m - Add pupils information from input_info.csv" << endl;
    cout << "\033[31m 4\033[0m - Remove pupil by fullname" << endl;
    cout << "\033[31m 5\033[0m - Add mark to a pupil" << endl;
    cout << "\033[31m 6\033[0m - Add a mark to all pupils" << endl;
    cout << "\033[31m 7\033[0m - Show full information about a pupil" << endl;
    cout << "\033[31m 8\033[0m - Get average mark of class" << endl;
    cout << "\033[31m 9\033[0m - Get pupil with highest average mark" << endl;
    cout << "\033[31m10\033[0m - Get pupil with lowest average mark" << endl;
    cout << "\033[31m11\033[0m - Get all pupils full name with marks higher then X" << endl;
    cout << "\033[31m12\033[0m - Get all pupils full name with marks lower then X " << endl;
    cout << "\033[31m 0\033[0m - Exit the program" << endl;
    cout << "\033[32mSelect an option -->>\033[0m ";
    cin >> checker;
    switch (checker) {
    case 1:
      Show_List();
      break;
    case 2:
      Add_Pupil_Info_1();
      break;
    case 3:
      Add_Pupil_Info_2();
      break;
    case 4:
      Remove_Pupil(); 
      break;
    case 5:
      Add_Mark_1();
      break;
    case 6:
      Add_Mark_2();
      break;
    case 7:
      Show_Full_Info();
      break;
    case 8:
      Show_MidMark();
      break;
    case 9:
      /* code */
      break;
    case 10:
      /* code */
      break;
    case 11:
      /* code */
      break;
    case 12:
      /* code */
      break;
    case 0:
      cout << "\033[1;31m-> EXIT <-\033[0m" << endl;
      break;    
    default:
      cout << "Unknown Option" << endl;
      break;
    }
  } while (checker != 0);

  return 0;
}