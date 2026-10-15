#include<iostream>

using namespace std;

// Definition : Provides an interface for creating families of related objects without specifing their concrete class.

// Product(Burger) 1 Class and Sub-classes
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

// Product(Garglic-bread) 2 & Sub-classes
class GarlicBread {
    public:
        virtual void prepare() = 0;
    
        virtual ~GarlicBread() {}
};

class BasicGarlicBread : public GarlicBread {
    public:
        void prepare() override{
            cout << "Preparing Basic Garlic Bread !!!" << endl;
        }
};

class StandardGarlicBread : public GarlicBread {
    public:
        void prepare()  override{
            cout << "Preparing Standard Garlic Bread !!!" << endl;
        }
};

class BasicGarlicWheatBread : public GarlicBread {
    public:
        void prepare() override{
            cout << "Preparing Basic Garlic Wheat Bread !!!" << endl;
        }
};

class StandardGarlicWheatBread : public GarlicBread {
    public:
        void prepare()  override{
            cout << "Preparing Standard Garlic Wheat Bread !!!" << endl;
        }
};

// Abstract Factory Class
class MealFactory {
    public:
        virtual Burger * createBurger (string & type) = 0;

        virtual GarlicBread * createGarlicBread (string & type) = 0;
};

// Sub-Factory 1
class SinghBurger : public MealFactory {
    public: 
        Burger * createBurger(string &type) override{
            if(type == "basicBurger"){
                return new BasicBurger();
            }else if(type == "standardBurger"){
                return new StandardBurger();
            }else{
                cout << "Invalid Burger Type !!!" << endl;
                return nullptr;
            }
        }

        GarlicBread * createGarlicBread(string &type) override {
            if(type == "basicGarlicBread"){
                return new BasicGarlicBread();
            }else if(type == "standardGarlicBread"){
                return new StandardGarlicBread();
            }else{
                cout << "Invalid Garlic Bread Type !!!" << endl;
                return nullptr;
            }
        }
};

// Sub-Factory 2
class KingBurger : public MealFactory {
    public:
        Burger * createBurger(string &type) override {
            if(type == "basicWheatBurger"){
                return new BasicWheatBurger();
            }else if(type == "standardWheatBurger"){
                return new StandardWheatBurger();
            }else{
                cout << "Invalid Burger Type !!!" << endl;
                return nullptr;
            }
        }

        GarlicBread * createGarlicBread(string &type) override {
            if(type == "basicGarlicWheatBread"){
                return new BasicGarlicWheatBread();
            }else if(type == "standardGarlicWheatBread"){
                return new StandardGarlicWheatBread();
            }else{
                cout << "Invalid Garlic Wheat Bread Type !!!" << endl;
                return nullptr;
            }
        }
};

int main() {
    string garlicBreadType = "standardGarlicWheatBread";
    string burgerType = "basicWheatBurger";

    MealFactory * mealFactory = new KingBurger();

    GarlicBread * garlicBread = mealFactory->createGarlicBread(garlicBreadType);
    Burger * burger = mealFactory->createBurger(burgerType);

    garlicBread -> prepare();
    burger -> prepare();

    return 0;
}