#include<iostream>

using namespace std;

class NoSingleton {
public:
    NoSingleton() {
        cout << "Singleton Constructor called. New Object created." << endl;
    }
};

int main() {
    NoSingleton* Obj1 = new NoSingleton();
    NoSingleton* Obj2 = new NoSingleton();

    cout << "Obj1 and Obj2 are same :: " << (Obj1 == Obj2) << endl;
}