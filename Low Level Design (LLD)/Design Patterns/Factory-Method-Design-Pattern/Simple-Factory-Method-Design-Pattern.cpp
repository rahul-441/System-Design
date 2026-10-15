#include<iostream>

using namespace std;

// Definition : A factory class that decides which concrete class to instantiate.

class Burger{
    public:
      
      virtual void prepare() = 0; // Pure virtual function
      
      virtual ~Burger(){}        // Destructure
};

class BasicBurger : public Burger {
    public:
        void prepare() override {
            cout << "Preparing for Basic Burger !!!" << endl;
        }
};

class StandardBurger : public Burger {
    public:
        void prepare() override {
            cout << "Preparing for Standard Burger !!!" << endl;
        }
};

// Factory 
class BurgerFactory{
    public:

      Burger * createBurger(string type){
            if(type == "basic"){
                return new BasicBurger();
            }else if(type == "standard"){
                return new StandardBurger();
            }else{
                return nullptr;
            }
      }
};

int main(){

     BurgerFactory * burgerFact = new BurgerFactory();

     Burger * burger = burgerFact->createBurger("basic");

     burger -> prepare();

    return 0;
}



