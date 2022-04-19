#include <iostream>
#include <fstream>
#include <cstring>
#include "ItemDB.h"
using namespace std;

const int MAX_CEREAL=500;

ItemDB::ItemDB(){
  numCereal = 0;
  readCereals();
}

void ItemDB::readCereals() {
    ifstream cerealFile("Cereal.txt");
    while(cerealFile.peek() != EOF && numCereal < MAX_CEREAL) {
        cereals[numCereal].readCereal(cerealFile);
        numCereal++;
    }
}

void ItemDB::reloadArray(){
  int temp = numCereal;
  for(int index = 0; index < temp; index++){
    remove(0);
  }
  readCereals();  
}

void ItemDB::printArrayToScreen() {
  for (int index = 0; index < numCereal; index++) {
        cout << "Index " << index << ": ";
        cereals[index].print(cout);
        cout << endl;
    }
}

void ItemDB::printArrayIndexToScreen(int numCereal) {
  cereals[numCereal].print(cout);
}

void ItemDB::printArrayToFile(const char fileName[]) {
    ofstream outFile(fileName);
    for (int index = 0; index < numCereal; index++) {
        cereals[index].print(outFile);
        outFile << endl;
    }
}

void ItemDB::addNew(int index){
  cereals[index].newEntry();
}

void ItemDB::remove(int index){
  cereals[index].removeEntry();

  for(int count = index; count < numCereal; count++){
    cereals[count] = cereals[count+1];
  }
  numCereal--;
}
