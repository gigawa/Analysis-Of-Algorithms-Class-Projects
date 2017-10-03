#include <iostream>
#include <fstream>

using namespace std;

ofstream fout;

void printWorkedArray(char array[], int n, int left, int right) {
  cout << "Whole Array: ";
  fout << "Whole Array: ";
  for(int i = 0; i < n; i++){
    cout << array[i] << " ";
    fout << array[i] << " ";
  }
  cout << endl << "Worked Portion: ";
  fout << endl << "Worked Portion: ";
  for(int i = left; i < right; i++){
    cout << array[i] << " ";
    fout << array[i] << " ";
  }
  cout << endl;
  fout << endl;
}

void printArray(char array[], int n) {
  for(int i = 0; i < n; i++){
    cout << array[i] << " ";
    fout << array[i] << " ";
  }
  cout << endl;
  fout << endl;
}

void bubbleSort(char array[], int n) {
  bool swapped = true;
  int j = 0;
  int k = n;
  char temp;
  while (swapped) {
    swapped = false;
    for (int i = j; i < k-1; i++) {
      if (array[i] > array[i + 1]) {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
      }
    }
    cout << "Left to Right:" << endl;
    fout << "Left to Right:" << endl;
    printWorkedArray(array, n, j, k);
		k--;

    for (int i = k; i > j; i--) {
      if (array[i] < array[i - 1]) {
        temp = array[i];
        array[i] = array[i - 1];
        array[i - 1] = temp;
        swapped = true;
      }
    }
    cout << "Right to Left:" << endl;
    fout << "Right to Left:" << endl;
    printWorkedArray(array, n, j, k);
		j++;
  }
}

void readArray (char array[], int n) {
  cout << "Enter Array: ";
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
  printWorkedArray(array, n, 0, 0);
  bubbleSort(array, n);
}

int main(int argc, char const *argv[]) {
  int n;

  cout << "Enter the length of the array: ";
  cin >> n;

  char array [n];
  cout << "Enter Array: ";
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
  fout.open("log.txt");
  printArray(array, n);
  bubbleSort(array, n);
  printArray(array, n);
  fout.close();

  return 0;
}
