#include "ReadUtils.h"
#include <fstream>
using namespace std;
class ItemClass{
  public:    
    ItemClass();
    int print(ostream &out);
    void readCereal(ifstream &inFile);
    void newEntry();
    void removeEntry();

  private:
    enum {MAX_CHAR_LEN=100};
    char name[MAX_CHAR_LEN];
    double calories;
    double protien;
    double fat;
    double sodium;
    double fiber;
    double carbs;
    double sugar;
    double serving;
    bool valid;
};