#include <iostream>
using namespace std;

void AddArray(int arr[], int arr2[], int arr3[], int a){ 
  for(int i = 0; i < a; i++)
    arr3[i] = arr[i] + arr2[i];
}

void SubArray(int arr[], int arr2[], int arr3[], int a){ 
  for(int i = 0; i < a; i++)
    arr3[i] = arr[i] - arr2[i];
}
void FillArray(int arr[], int a){ 
  for(int i = 0; i < a; i++)
    cin >> arr[i];
}

void PrintArray(int arr[], int a){ 
  for(int i = 0; i < a; i++)
    cout << arr[i] << " ";
}

int main(){
  int size;
  cin >> size;
  int array_1[size];
  FillArray(array_1, size);
  char znak;
  cin >> znak;
  int array_2[size];
  FillArray(array_2, size);
  int array_3[size];
  if(znak == '+')
    AddArray(array_1, array_2, array_3, size);
  else 
    SubArray(array_1, array_2, array_3, size);
  PrintArray(array_3, size);
}
