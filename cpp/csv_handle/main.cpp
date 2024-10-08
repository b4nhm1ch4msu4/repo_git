#include "include/csv_fileHandler.h"

int main(int argc, char *argv[]) {
  string filePath = "data.csv";
  CSV_Handler handler = CSV_Handler(filePath);
  handler.Read();

  return 0;
}
