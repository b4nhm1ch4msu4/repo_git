#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CSV_Handler {
public:
  CSV_Handler(string);
  // ~CSV_Handler();
  void Create();
  void Read();
  void Delete();
  void Update();

private:
  fstream file;
  string filePath;
};
