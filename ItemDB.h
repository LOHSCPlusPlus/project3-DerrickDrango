#include "ItemClass.h"
class ItemDB{
  private:
    enum {MAX_CEREAL = 500};
    ItemClass cereals[MAX_CEREAL];
    int numCereal;

  public:
    ItemDB();
    void readCereals();
    void printArrayToScreen();
    void printArrayIndexToScreen(int numCereal);
    void printArrayToFile(const char fileName[]);
    void addNew(int index);
    void remove(int index);
    void reloadArray();
};