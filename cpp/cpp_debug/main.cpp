#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CSV_Handler {
public:
  CSV_Handler(string filePath) { this->filePath = filePath; }
  void Create() {
    file.open(filePath, ios::out | ios::app);
    if (!file.is_open()) {
      cout << "Error while opening file !!!" << endl;
    } else {
      cout << "Enter the details of 5 students:\n"
              "roll name maths phy chem bio"
           << endl;
      int roll, phy, chem, math, bio;
      string name;
      for (int i = 0; i < 5; i++) {
        cin >> roll >> name >> math >> phy >> chem >> bio;
        file << roll << "," << name << "," << math << "," << phy << "," << chem
             << "," << bio << "\n";
      }
    }
    file.close();
  }
  void Read() {
    file.open(filePath, ios::in);
    if (!file.is_open()) {
      cout << "Error while opening file !!!" << endl;
    } else {
      int rollnum, roll_Int, counter = 0;
      cout << "Enter the roll number " << "of the student to display details: ";
      cin >> rollnum;
      vector<string> row;
      string line, word, temp;
      while (getline(file, line)) {
        stringstream s(line);
        while (getline(s, word, ',')) {
          row.push_back(word);
        }
        string roll_str = row[0];
        cout << roll_str << endl;
        break;
        // roll_Int = stoi(roll_str);
        // if (roll_Int == rollnum) {
        //   counter = 1;
        //   cout << "Details of Roll " << row[0] << " : \n";
        //   cout << "Name: " << row[1] << "\n";
        //   cout << "Maths: " << row[2] << "\n";
        //   cout << "Physics: " << row[3] << "\n";
        //   cout << "Chemistry: " << row[4] << "\n";
        //   cout << "Biology: " << row[5] << "\n";
        //   break;
        // }
      }
      if (counter == 0) {
        cout << "Record not found\n";
      }
    }
    file.close();
  }
  // ~CSV_Handler();
  void Delete();
  void Update();

private:
  fstream file;
  string filePath;
};

int main(int argc, char *argv[]) {
  string filePath = "data.csv";
  CSV_Handler handler = CSV_Handler(filePath);
  handler.Read();

  return 0;
}
