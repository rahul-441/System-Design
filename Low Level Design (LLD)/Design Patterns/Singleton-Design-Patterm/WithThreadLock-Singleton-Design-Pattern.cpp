#include<iostream>
#include<mutex>

using namespace std;

// Definition: A class must initialize only once; only allow to have one object

class Singleton {
    private:
        static Singleton* instance;
        static mutex mtx;

        // Creating private constructure so, that it can not be accessible form outside of class
        Singleton(){
                cout << "New object creating....!" << endl;
        }

   public:
        
        // Static method belongs to class not to any object so, that why we can access it without any object of class.
        static Singleton * getInstance () {

            if(instance == nullptr){ // First check (no locking)

                // Mutex Lock :: To ensure that only one thread accesses a shared resource at a time, preventing race conditions.
                lock_guard<mutex> lock(mtx);  // Lock only if needed

                if(instance == nullptr){ // Second check (after acquiring lock)

                    instance = new Singleton();
                }
            }

            return instance;
        }  
};

// static data member belongs to the class, not to individual objects.
// So, traditionally, we declare it inside the class and define it outside.
Singleton * Singleton::instance = nullptr;

mutex Singleton::mtx;

int main(){

    Singleton * obj1 = Singleton::getInstance();
    Singleton * obj2 = Singleton::getInstance();

    cout << "Obj1 and Obj2 are same :: " << (obj1 == obj2) << endl;
    return 0;
}