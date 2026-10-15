#include <iostream>

using namespace std;

// Implementing a Strategy Design Pattern 
// Definition : Defines family of algorithms and put them into separate class
//              so that, they can be changed at the run-time

// Strategy : interface for walking
class WalkableRobot{
    public:
        virtual void walk() = 0;

        // Destructure
        virtual ~WalkableRobot() {}
};

// Concrete Stategies For Walking
class NormalWalk : public WalkableRobot{
   public:
        void walk(){
            cout << "Normal Walk Started....!" << endl;
        }
};

class NonWalkable : public WalkableRobot {
    public:
        void walk(){
            cout << "Non-walkable Robots can not walk !!" << endl;
        }
};

// Strategy : interface for Talking
class TalkableRobot{
    public:
        virtual void talk() = 0;

        // Destructure
        virtual ~TalkableRobot() {}
};

// Concrete Strategies For Talk
class NormalTalk : public TalkableRobot{
   public:
        void talk(){
            cout << "Normal talk Started....!" << endl;
        }
};

class NonTalkable : public TalkableRobot {
    public:
        void talk(){
            cout << "Non-talkable Robots can not talk !!" << endl;
        }
};

class Robot{
    private:
        WalkableRobot * walkingBehaviour;
        TalkableRobot * talkingBehaviour;

    public:
       Robot(WalkableRobot * w, TalkableRobot * t){
           this->walkingBehaviour = w;
           this->talkingBehaviour = t;
       }

       void walk(){
            walkingBehaviour->walk();
       }

       void talk(){
            talkingBehaviour->talk();
       }

       virtual void projection() = 0;

};

// Concrete Robot Type Class 1
class CompanionRobot : public Robot{
    public:
        
       CompanionRobot(WalkableRobot * w, TalkableRobot * t) : Robot(w, t){}

        void projection(){
            cout << "Projection for Companion Robot ...!" << endl;
        }
};

// Concrete Robot Type Class 2
class WorkingRobot : public Robot {
    public:

       WorkingRobot(WalkableRobot * w, TalkableRobot * t): Robot(w, t){}

       void projection(){
        cout << "Projection for Working Robot ....!" << endl;
       }
};

int main(){

    Robot * Robo_1 = new CompanionRobot(new NormalWalk(), new NonTalkable());

    Robo_1->walk();
    Robo_1->talk();
    Robo_1->projection();

    Robot * Robo_2 = new WorkingRobot(new NormalWalk(), new NormalTalk());

    Robo_2->walk();
    Robo_2->talk();
    Robo_2->projection();

    // Conclusion :
    //              1. Encapsulate ---> What varies & keet it separate from what remains same.
    //              2. Solution to inheritance is not more inheritance.
    //              3. Composition should be favoured over inheritance. Class Diagram -- > Assocaition --> Object Association)
    //              4. Code To interface and not to concretion
    //              5. Do not Repreat Yourself (DRY - Rule)

    return 0;
}


