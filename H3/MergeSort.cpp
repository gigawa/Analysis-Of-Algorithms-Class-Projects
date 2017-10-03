#include <iostream>
#include <fstream>

using namespace std;

ofstream fout;

void printArray(char array[], int size)
{
   for (int i=0; i < size; i++) {
     cout << array[i] << " ";
     fout << array[i] << " ";
   }
   cout << endl;
   fout << endl;
}

// Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[]
void merge(char array[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 =  right - mid;

    char LeftArray[n1];
    char RightArray[n2];

    for (i = 0; i < n1; i++)
        LeftArray[i] = array[left + i];
    for (j = 0; j < n2; j++)
        RightArray[j] = array[mid + 1+ j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            array[k] = LeftArray[i];
            i++;
        }
        else
        {
            array[k] = RightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = RightArray[j];
        j++;
        k++;
    }
    cout << "Right Array: ";
    fout << "Right Array: ";
    printArray(RightArray, n2);
    cout << "Left Array: ";
    fout << "Left Array: ";
    printArray(LeftArray, n1);
    cout << endl;
    fout << endl;
}

// Iterative mergesort function
void mergeSort(char array[], int n)
{
   int size;
   int left;

   for (size = 1; size < n; size = 2 * size)
   {
       for (left = 0; left < n-1; left += 2 * size)
       {

           int mid = left + size - 1;

           int right = min(left + 2 * size - 1, n-1);

           merge(array, left, mid, right);
       }
   }
}


int main(int argc, char const *argv[]) {
  int n;
  string type;
  cout << "Enter the length of the array: ";
  cin >> n;

  char array[n];
  cout << "Enter Array: ";
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
  fout.open("mergeSortLog.txt");
  mergeSort(array, n);
  printArray(array, n);
  return 0;
}
