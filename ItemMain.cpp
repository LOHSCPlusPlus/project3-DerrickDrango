#include "ItemDB.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ItemDB callCereal;
    int input;
    cout << endl;
    while (true){
  input = readInt("1.Reload database from the file\n2.Print Cereal\n3.Add new entry\n4.Remove entry\n5.Print all Cereals\n6.Save database to the file\n7.Quit\n\nEnter a Number: ");

  if(input == 1){
    callCereal.reloadArray();
    cout << endl;
  }
  if(input == 2){
    cout << endl;
    callCereal.printArrayIndexToScreen(readInt("Enter an Index: "));
    cout << endl << endl;
  }
  if(input == 3){
    cout << endl;
    callCereal.addNew(readInt("Enter an Index: "));
    cout << endl;
  }
  if(input == 4){
    cout << endl;
    callCereal.remove(readInt("Enter an Index: "));
    cout << endl;
  }
  if(input == 5){
    cout << endl;
    callCereal.printArrayToScreen();
    cout << endl;
  }
  if(input == 6){
    callCereal.printArrayToFile("Cereal.txt");
    cout << endl;
  }
  if(input == 7){
    return 0;
  }
}
    return 0;
}
