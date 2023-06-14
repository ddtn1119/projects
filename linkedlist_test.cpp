#include <iostream>
using namespace std;

//Write your code after this line

//part 1
class base_product {
    // members, accessors & mutators
    int PLU;
    char* description;
  public:
    int getPlu(){
      return PLU;
    }
    char* getDescription(){
      return description;
    }
    void setPLU(int p){
      PLU = p;
    }
    void setDescription(const char* d){
      if(description != nullptr){
        delete[] description;
      }
      int i = 0;
      while(d[i++] != '\0');
      description = new char[i];
      i = 0;
      while (d[i] != '\0') {
          description[i] = d[i];
          i++;
      }
      description[i] = '\0';
    }
    void print(){
      cout << "(" << PLU << ", " << description << ")" << endl;
    }
    // constructor
    base_product(int plu, const char* d){
      this->PLU = plu;
      description = nullptr;
      setDescription(d);
    }
    // destructor
    ~base_product(){
      if(description != nullptr){
        delete[] description;
      }
    }
};

//enum definition

enum TYPE {POUND=0, UNIT=5};

//Part 2

class product : public base_product {
private:
  double price;
  TYPE pt;
public:
  double getPrice(){
    return price;
  }
  TYPE getType(){
    return pt;
  }
  void setPrice(double p){
    price = p;
  }
  void setPT(TYPE t){
    pt = t;
  }
  void print(){
    cout << "(" << getPlu() << ", " << getDescription() << ", "
      << price << ", " << pt << ")" << endl;
  }
  product(int plu, const char* des, double p, TYPE t):
  base_product(plu, des){
    this->price = p;
    this->pt = t;
  }
  ~product(){}
};

//Part 3
class node {
public:
  product* payload;
  node* next;
  static int counter;
  node(){
    payload = nullptr;
    next = nullptr;
    counter++;
  }
  void print(){
    if(payload != nullptr){
      payload->print();
    }
  }
  ~node(){
    if(payload != nullptr){
      delete payload;
    }
    counter--;
  }
};

//Part 4
class linkedList {
    node* head;
public:
    linkedList(){
      head = nullptr;
    }
    ~linkedList(){
      node* it = head;
      node* itc = head;
      while (it != nullptr) {
          itc = it->next;
          delete it;
          it = itc;
      }
    }
    void append(node* nn){
      if (head != nullptr) {
          node* it = head;
          while (it->next != nullptr) {
              it = it->next;
          }
          it->next = nn;
      }
      else {
          head = nn;
      }
    }
    void print(){
      node* it = head;
      while(it != nullptr){
        it->print();
        it = it->next;
      }
    }
    int size(){
      return node::counter;
    }
    bool removeByProductPLU(int index){
      if(head == nullptr){
        return false;
      }
      node* it = head;
      node* prev = head;
      while(it->next != nullptr){
        prev = it;
        it = it->next;
      }
      prev->next = nullptr;
      delete it;
      return true;
    }
};

int node::counter = 0;
/***************************************************************/

int main() {


    //CODE FREEZE BEGIN
    int section = 4;      //Determines the test to be executed
    char subsection = 'e';//Determines the subsection to be executed

    std::cin >> section;
    std::cin >> subsection;

    switch (section) {
    case 1: {
        base_product* bp1 = nullptr;
        //1) Test part 1
        if (subsection >= 'b') {
            //Constructor
            bp1 = new base_product(12, "Pinneapple");
            cout << "Done (1b)" << endl;
        }
        if (subsection >= 'c') {
            //Setters/mutators
            bp1->setPLU(12345);
            bp1->setDescription("Fuji Apple");
            cout << "Done (1c)" << endl;
        }
        if (subsection >= 'd') {
            //Getters/accessors
            bp1->print();
        }
        if (bp1 != nullptr) {
            //e.- Destructor
            delete bp1;
        }
        break;
    }
    case 2: {
        //2) Test part 2
        product* p1 = nullptr;
        if (subsection >= 'b') {
            //Constructor
            p1 = new product(12, "Grapes", 2.4, POUND);
            cout << "Done (2b)" << endl;
        }
        if (subsection >= 'c') {
            //Setters/Mutators
            p1->setPLU(12345);
            p1->setDescription("Blueberry");
            p1->setPT((TYPE)0);
            p1->setPrice(4.56);
            cout << "Done (2c)" << endl;
        }
        if (subsection >= 'd') {
            //Getters/Mutators
            p1->print();
            //Inheritance/Polymorphism
            base_product* bp2 = (base_product*)p1;
            bp2->print();
        }
        if (p1 != nullptr) {
            //Destructor
            delete p1;
        }
        break;
    }
    case 3: {
        //3) Test part 3
        node* nn = nullptr;
        if (subsection >= 'b') {
            //Constructor
            nn = new node();
            product* p2 = new product(12, "Bananas", 1.45, UNIT);
            nn->payload = p2;
            cout << "Done (3b)" << endl;
        }
        if (subsection >= 'c') {
            //Function Member
            nn->print();
        }
        if (nn != nullptr) {
            //d.- Destructor
            delete nn;
        }
        break;
    }
    case 4: {
        //4) Test part 4
        linkedList* myList = nullptr;
        if (subsection >= 'a') {
            //a.- Constructor
            myList = new linkedList();
            cout << "Done (4a)" << endl;
        }
        if (subsection >= 'b') {
            int i;

            char shopping[][30] = { "Bananas", "Pineapple","Pear","Grapes", "Blueberry" };
            int types[] = { 0,5,5,0,0 };
            for (i = 0; i < 5; i++) {
                node* nn = new node();
                product* np = new product(78 * i, shopping[i], 1.25 * (i + 1), (TYPE)types[i]);
                nn->payload = np;
                //b.- Append
                myList->append(nn);
            }
            cout << "Done (4b)" << endl;
        }
        if (subsection >= 'c') {
            //c.- Print
            myList->print();
        }
        if (subsection >= 'd') {
            //d.- Size
            cout << myList->size() << endl;
        }
        if (subsection >= 'e') {
            //e.- Remove
            myList->removeByProductPLU(156);
            myList->print();
            cout << myList->size() << endl;
        }

        if (myList != nullptr) {
            //destructor
            delete myList;
        }
        break;
    }
    }
    return 0;
}
//CODE FREEZE END