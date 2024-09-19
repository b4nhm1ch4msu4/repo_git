#include <iostream> 
#include <ostream>
#include <string> 
#include <fstream>
/*#include <termios.h>*/
#include <unistd.h>

using namespace std;

/**
 * display menu options
*/
void display_menu(){
  cout << "LOGIN FORM - WEBCOME PAGE!!!\n";
  cout << "\n";
  cout << "1. Login\n";
  cout << "2. Sign-up\n";
  cout << "3. Reset password\n";
}

/**
 * get username and password
 * @para 
 * @return string "[username] [password]"
 */
int login(){
  string username, pass;
  cout << "LOGIN PAGE\n";
  cout << "Please enter username and password!\n";

  cout << "Username: ";
  cin >> username;
  pass = getpass("Password: ");
  string login_info{username + " " + pass};
  fstream file_data;
  file_data.open("data.txt", ios::in);
  if(file_data.is_open()){
    string line;
    while (getline(file_data, line)) {
      if(line.find(login_info) != string::npos){
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
 * Create new user and add to data.txt
 */

int sign_up(){
  string username, pass;
  cout << "SIGNUP PAGE\n";
  cout << "Create new user!\n";

  cout << "Username: ";
  cin >> username;
  // check if username is exist
  fstream file_data;
  file_data.open("data.txt",ios::in);
  if(file_data.is_open()){
    string line;
    while(getline(file_data, line)){
      if(line.find(username) != string::npos){
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
  if (pass != re_type_pass){
    cout << "Password not match !!!\n";
    cout << "Sign-up fail!\n";
  }else {
    file_data.open("data.txt", ios::app);
    if(file_data.is_open()){
      file_data << username << " " << pass << "\n";
      cout << "Sign-up success !!!\n";
      cout << "New user " << username << " was added.\n";
      file_data.close();
      return 0;
    }else {
      cout << "Could not open data file !\n";
    }
    file_data.close();
  }
  return 1;
}

/**
 * Reset password
 * */
int reset_pass(){
  string username;
  cout << "Reset Password !!!\n";
  cout << "Enter your username: \n";
  cin >> username;
  fstream file_data;
  file_data.open("data.txt", ios::in);

  if(file_data.is_open()){
    /*string line;*/
    /*while (getline(file_data, line)) {*/
    /**/
    /*}*/
  }
  return 0;
}

int main (int argc, char *argv[]) {
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
      cout << "reset password\n";
      break;
    default:
      cout << "Invalid option !!";
  }
  return 0;

}
