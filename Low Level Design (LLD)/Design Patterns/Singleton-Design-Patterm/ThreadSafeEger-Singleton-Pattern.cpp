#include<iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    static Singleton* getInstance() {
        return instance;
    }
};
 
// Initialize static members : Initializing instance of object for class so, that we always get the same instance through getInstance() method
Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton* Obj1 = Singleton::getInstance();
    Singleton* Obj2 = Singleton::getInstance();

    cout << "Obj1 and Obj2 are same :: " << (Obj1 == Obj2) << endl;
}