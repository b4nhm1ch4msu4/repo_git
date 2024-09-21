#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

string pass_gen(int len) {
  string chars =
      "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";
  int chars_size = size(chars);
  srand(time(0));
  string password{""};
  for (int i = 0; i < len; i++) {
    int random_num = rand() % chars_size;
    password += chars[random_num];
  }
  return password;
}

int main(int argc, char *argv[]) { 

  int pass_len;
  cout << "----------------------------\n";
  cout << "-----Password Generator-----\n";
  cout << "----------------------------\n";
  cout << "\n\n";
  cout << "Enter the password length :: ";
  cin >> pass_len;
  string output = pass_gen(pass_len);

  cout << "\nYour password is :: " << output << endl;


  return 0; 
}
