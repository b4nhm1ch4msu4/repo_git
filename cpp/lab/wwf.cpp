#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {
  /*cout << "Working with file" << "\n";*/

  fstream myfile;
  /*myfile.open("text.txt", ios::out);*/
  /*if(myfile.is_open()){*/
  /*  myfile << "hello world \n";*/
  /*  myfile << "second line \n";*/
  /*  myfile.close();*/
  /*}*/
  /**/
  /*myfile.open("text.txt", ios::app);*/
  /*if(myfile.is_open()){*/
  /*  myfile << "hello second time \n";*/
  /*  myfile.close();*/
  /*}*/


  myfile.open("text.txt", ios::in);
  if(myfile.is_open()){
    /*cout << "reading from a file .\n";*/
    string line;
    while (getline(myfile, line, ' ')) {
      cout << line << endl;
    }
    myfile.close();
  }

  return 0;

}
