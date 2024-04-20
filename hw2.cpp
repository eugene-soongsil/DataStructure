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
        Cow(int w = 500) 
    }
}
