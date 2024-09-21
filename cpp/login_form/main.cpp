#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <unistd.h>
#define FILENAME "data.txt"

using namespace std;

/**
 * display menu options
 */
void display_menu() {
  cout << "----------------------------------\n";
  cout << "---LOGIN FORM - WEBCOME PAGE!!!---\n";
  cout << "----------------------------------\n";
  cout << "\n";
  cout << "1. Login\n";
  cout << "2. Sign-up\n";
  cout << "3. Reset password\n";
  cout << "4. Quit\n";

  cout << "Enter your option ::";
}

/**
 * ---------------
 * ----Login------
 * ---------------
 * Get username and password from input and compare with records in data.txt
 */
int login() {
  string username, pass;
  cout << "LOGIN PAGE\n";
  cout << "Please enter username and password!\n";

  cout << "Username: ";
  cin >> username;
  pass = getpass("Password: ");
  string login_info{username + " " + pass};
  fstream file_data;
  file_data.open(FILENAME, ios::in);
  if (file_data.is_open()) {
    string line;
    while (getline(file_data, line)) {
      if (line.find(login_info) != string::npos) {
        cout << "Login Success\nWelcome " << username << endl;
        file_data.close();
        return 0;
      }
    }
    cout << "Login fail, Invalid Username or Password !!!\n";
    file_data.close();
    return 1;
  }
  cout << "Could not open data file !!!\n";
  return 1;
}

/**
 * ---------------
 * ----Sign-up----
 * ---------------
 * Get username and password from input and add new record to data.txt
 */

int sign_up() {
  string username, pass;
  cout << "SIGNUP PAGE\n";
  cout << "Create new user!\n";

  cout << "Username: ";
  cin >> username;
  // check if username is exist
  fstream file_data;
  file_data.open(FILENAME, ios::in);
  if (file_data.is_open()) {
    string line;
    while (getline(file_data, line)) {
      if (line.find(username) != string::npos) {
        cout << "Username is exist !!!\n";
        cout << "Sign-up fail !\n";
        file_data.close();
        return 1;
      }
    }
  }
  file_data.close();

  pass = getpass("Password: ");
  string re_type_pass{getpass("Re-type password: ")};
  if (pass != re_type_pass) {
    cout << "Password not match !!!\n";
    cout << "Sign-up fail!\n";
  } else {
    file_data.open(FILENAME, ios::app);
    if (file_data.is_open()) {
      file_data << username << " " << pass << "\n";
      cout << "Sign-up success !!!\n";
      cout << "New user " << username << " was added.\n";
      file_data.close();
      return 0;
    } else {
      cout << "Could not open data file !\n";
    }
    file_data.close();
  }
  return 1;
}

/**
 * ---------------
 * ----Reset------
 * ---------------
 * Copy all records in data.txt to temp.txt, excep record contains username
 * rename temp.txt -> data.txt
 * */
int reset_pass() {
  string username;
  cout << "Reset Password !!!\n";
  cout << "Enter your username: ";
  cin >> username;

  // remove username from data
  ifstream file_data{FILENAME};
  if (!file_data.is_open()) {
    cout << "Can't open file data. ERROR ERROR ERROR!!!\n";
    return 1;
  }
  ofstream temp_data{"temp.txt"};
  if (!temp_data.is_open()) {
    cout << "Can't create temp file data. ERROR ERROR ERROR!!!\n";
    return 1;
  }

  string line;
  while (getline(file_data, line)) {
    if (line.find(username) == string::npos) {
      temp_data << line << "\n";
    }
  }
  file_data.close();
  temp_data.close();

  filesystem::remove(FILENAME);
  filesystem::rename("temp.txt", FILENAME);

  cout << "Your account was deleted. Please create new one !\n";

  return 0;
}

int main(int argc, char *argv[]) {
  bool quit = false;

  display_menu();

  int option;
  cin >> option;
  switch (option) {
  case 1:
    login();
    break;
  case 2:
    sign_up();
    break;
  case 3:
    reset_pass();
    break;
  case 4:
    quit = true;
    break;
  default:
    cout << "Invalid option !!";
  }
  return 0;
}
