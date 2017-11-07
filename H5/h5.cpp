#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int weeks = 4;
int totals [4];
int high [4] = {5, 50, 5, 1};
int low [4] = {10, 1, 10, 10};

template <typename T>
void PrintTable(T table[4]) {
  for(int i = 0; i < weeks; i++) {
    cout << table[i] << " ";
  }
  cout << endl;
}

void OptimalPlanB(int weeks) {
  int values [4];
  for(int i = 0; i < weeks; i++) {
    if(i > 0) {
      if(high[i] > low[i] + low[i-1]) {
        values[i] = high[i];
        totals[i] = high[i] + totals[i-2];
      }else {
        values[i] = low[i];
        totals[i] = low[i] + totals[i-1];
      }
    }else {
      if(high[i] > low[i]) {
        values[i] = high[i];
        totals[i] = high[i];
      }else {
        values[i] = low[i];
        totals[i] = low[i];
      }
    }
  }
  PrintTable(values);
  PrintTable(totals);
  cout << endl;
}

void OptimalPlanC(int weeks) {
  int values [4];
  string choices [4];
  for(int i = 0; i < weeks; i++) {
    if(i > 0) {
      if(high[i] > low[i] + low[i-1]) {
        values[i] = high[i];
        choices[i] = "High";
        totals[i] = high[i] + totals[i-2];
      }else {
        values[i] = low[i];
        choices[i] = "Low";
        totals[i] = low[i] + totals[i-1];
      }
    }else {
      if(high[i] > low[i]) {
        values[i] = high[i];
        choices[i] = "High";
        totals[i] = high[i];
      }else {
        values[i] = low[i];
        choices[i] = "Low";
        totals[i] = low[i];
      }
    }
  }
  PrintTable(values);
  PrintTable(totals);
  PrintTable(choices);
  cout << endl;
}

void OptimalPlanD(int weeks) {
  int values [4];
  string choices [4];
  string solution [4];
  for(int i = 0; i < weeks; i++) {
    if(i > 0) {
      if(high[i] > low[i] + low[i-1]) {
        values[i] = high[i];
        choices[i] = "High";
        solution[i] = "High";
        solution[i-1] = "Rest";
        totals[i] = high[i] + totals[i-2];
      }else {
        values[i] = low[i];
        choices[i] = "Low";
        solution[i] = "Low";
        totals[i] = low[i] + totals[i-1];
      }
    }else {
      if(high[i] > low[i]) {
        values[i] = high[i];
        choices[i] = "High";
        solution[i] = "High";
        totals[i] = high[i];
      }else {
        values[i] = low[i];
        choices[i] = "Low";
        solution[i] = "Low";
        totals[i] = low[i];
      }
    }
  }
  cout << "Optimal Plan: ";
  PrintTable(solution);
  cout << endl;
}

int main() {
  OptimalPlanB(weeks);
  OptimalPlanC(weeks);
  OptimalPlanD(weeks);
}
