double max(const double a, const double b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}
int& getLargestElement(int* array, int length){
  int& largest = array[0];
  for(int i = 1; i < length; i++){
    if(array[i] > largest){
      largest = array[i];
    }
  }
  return largest;
}
