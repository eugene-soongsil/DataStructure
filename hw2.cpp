#include <string>
#include <stdio.h>

using namespace std;
class Animal{
    private:
    string color;

    protected:
    string type;

    public:
    void eat(){cout<<"EAT???"<<endl;}
    void sleep(){cout<<"I can sleep!"<<endl;}
    void setColor(string clr){color = clr;}
    string getColor(){retrun color;}
    void displayInfo(){
        cout<<"I am a"<<type<<endl;
        cout<<"My color is"<<color<<endl;}
};
class Dog:public Animal{
    int age;
    public:
    Dog(int age = 0){this->age = age;}
    void setType(string tp){type = tp;}
    void eat(){cout<<"I can eat everything!"<<endl;}
    void displayInfo(){
        cout<<"I am a "<<type<<endl;
        cout<<"I am "<<age<<"years old."<<endl;}
    };
class Cow:public Animal{
    int weight;
    public:
    Cow(int w = 500){weight = w;}
    void setType(string tp){type = tp;}
    void eat(){cout<<"I just eat vegetable."<<endl;}
    void displayInfo(){
        cout<<"I am a "<<type<<endl;
        cout<<"My weight is "<<weight<<"Kg."<<endl;
    };
};

int main(){
    Dog dog1(10);
    dog1.setColor("black");
    dog1.setType("pet");
    dog1.eat();
    dog1.sleep();
    dog1.displayInfo();

    cout<<endl<<endl;
    Cow cow1;
    cow1.setColor("brown");
    cow1.setType("livestock");
    cow1.eat();
    cow1.sleep();
    cow1.displayInfo();

    cout<<endl<<endl;

    Animal animal1;
    animal1.eat();
    animal1.setColor("white");
    animal1.displayInfo();
}



