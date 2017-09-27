#include <iostream>

using namespace std;

template <typename T>
void printArray(T array[], int n, int left, int right) {
  cout << "Hole Array: ";
  for(int i = 0; i < n; i++){
    cout << array[i] << " ";
  }
  cout << endl << "Worked Portion: ";
  for(int i = left; i < right; i++){
    cout << array[i] << " ";
  }
  cout << endl;
}

template <typename T>
void bubbleSort(T array[], int n) {
  bool swapped = true;
  int j = 0;
  int k = n;
  char tmp;
  while (swapped) {
    swapped = false;
    for (int i = j; i < k; i++) {
      if (array[i] > array[i + 1]) {
        tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
        swapped = true;
      }
    }
    cout << "Left to Right:" << endl;
    printArray(array, n, j, k);
		k--;

    if(swapped) {
      swapped = false;
      for (int i = k; i > j; i--) {
        if (array[i] < array[i - 1]) {
          tmp = array[i];
          array[i] = array[i - 1];
          array[i - 1] = tmp;
          swapped = true;
        }
      }
      cout << "Right to Left:" << endl;
      printArray(array, n, j, k);
		  j++;
    }
  }
}

template <typename T>
void readArray (T array[], int n) {
  cout << "Enter Array: ";
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
  bubbleSort(array, n);
}

int main(int argc, char const *argv[]) {
  int n;
  string type;
  cout << "Enter the length of the array: ";
  cin >> n;
  cout << "Enter type of Elements(char, int): ";
  cin >> type;
  if(type == "char") {
    char array[n];
    readArray(array, n);
  }else if(type == "int") {
    int array[n];
    readArray(array, n);
  }

  return 0;
}
