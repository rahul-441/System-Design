#include<iostream>

using namespace std;

class Singleton {
private:
    static Singleton* instance;

    // Creating private constructure so, that it can not be accessible form outside of class
    Singleton(){
        cout << "New object creating....!" << endl;
    }

public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* Obj1 = Singleton::getInstance();
    Singleton* Obj2 = Singleton::getInstance();

    cout << "Obj1 and Obj2 are same :: " << (Obj1 == Obj2) << endl;
}