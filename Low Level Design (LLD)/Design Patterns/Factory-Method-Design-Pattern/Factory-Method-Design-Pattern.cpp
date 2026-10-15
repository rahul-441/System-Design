#include<iostream>

using namespace std;

// Definition : Defines an interface for creating object but allows sub-classes to decide which class to instantiate.

// Product(Burger) Class and Sub-classes
class Burger {
    public:
        virtual void prepare() = 0;

        virtual ~Burger() {}
};

class BasicBurger : public Burger {
    public:
        void prepare() override{
            cout << "Preparing Basic Burger !!!" << endl;
        }
};

class StandardBurger : public Burger {
    public:
        void prepare() override{
            cout << "Prepare Standard Burger !!!" << endl;
        }
};


class BasicWheatBurger : public Burger {
    public:
        void prepare() override {
            cout << "Preparing Wheat Basic Burger !!!" << endl;
        }
};

class StandardWheatBurger : public Burger {
    public:
        void prepare() override {
            cout << "Preparing Wheat Standard Burger !!!" << endl;
        }
};

// Abstract Burger Factory
class BurgerFactory {
    public:
        virtual Burger * createBurger(string &type) = 0;
};

// Sub-Factory 1
class SinghBurger : public BurgerFactory {
    public: 
        Burger * createBurger(string &type) override{
            if(type == "basic"){
                return new BasicBurger();
            }else if(type == "standard"){
                return new StandardBurger();
            }else{
                cout << "Invalid Burger Type !!!" << endl;
                return nullptr;
            }
        }
};

// Sub-Factory 2
class KingBurger : public BurgerFactory {
    public:
        Burger * createBurger(string &type) override{
            if(type == "basicWheat"){
                return new BasicWheatBurger();
            }else if(type == "standardWheat"){
                return new StandardWheatBurger();
            }else{
                cout << "Invalid Burger Type !!!" << endl;
                return nullptr;
            }
        }
};

int main() {
    string type = "standardWheat";

    BurgerFactory * burgerFactory = new KingBurger();
    Burger * burger = burgerFactory->createBurger(type);

    burger -> prepare();

    return 0;
}