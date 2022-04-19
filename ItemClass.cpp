#include <iostream>
#include <fstream>
#include <cstring>
#include "ItemClass.h"
#include "ReadUtils.h"
using namespace std;

ItemClass::ItemClass(){
  for(int i = 0; i < MAX_CHAR_LEN; i++){
    name[i] = '\0';
  }
  calories = 0;
  protien = 0;
  fat = 0;
  sodium = 0;
  fiber = 0;
  carbs = 0;
  sugar = 0;
  serving = 0;
  valid = false;
}

int ItemClass::print(ostream &out) {

  int temp = 0;
  while(name[temp] != '\0') {
    out << name[temp];
    temp++;
  }

  out << ";" << calories << ";" << protien << ";" << fat << ";" << sodium << ";" << fiber << ";" << carbs << ";" << sugar << ";" << serving << ";";

  return 0;
}

void ItemClass::readCereal(ifstream &inFile){
    inFile.get(name, ItemClass::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> calories;
    inFile.ignore(100,';');
    inFile >> protien;
    inFile.ignore(100,';');
    inFile >> fat;
    inFile.ignore(100,';');
    inFile >> sodium;
    inFile.ignore(100,';');
    inFile >> fiber;
    inFile.ignore(100,';');
    inFile >> carbs;
    inFile.ignore(100,';');
    inFile >> sugar;
    inFile.ignore(100,';');
    inFile >> serving;
    inFile.ignore(100,'\n');
    // If we reached the end of the file while reading, then the entry is not valid
    valid = !inFile.eof();
}

void ItemClass::newEntry(){
  char Name[100];
  cin.ignore(100,'\n');
  readCharArray("Name: ", Name);
  strcpy(name, Name);
  calories = readDouble("Calories: ");
  protien = readDouble("Protien: ");
  fat = readDouble("Fat: ");
  sodium = readDouble("Sodium: ");
  fiber = readDouble("Fiber: ");
  carbs = readDouble("Carbs: ");
  sugar = readDouble("Sugar: ");
  serving = readDouble("Serving: ");
}

void ItemClass::removeEntry(){
  for(int index = 0; index < 100; index++){
    name[index] = '\0';
  }
  calories = '\0';
  protien = '\0';
  fat = '\0';
  sodium = '\0';
  fiber = '\0';
  carbs = '\0';
  sugar = '\0';
  serving = '\0';
}