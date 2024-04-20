#include <iostream>
using namespace std;

class Car{
    string type;
    string color;
    string serial;

    public:
    
    void setType(string t){
        type = t;
    }
    string getType(){
        return type;
    }
    void setColor(string);
    string getColor();
    void setSerial(string);
    string getSerial();

    void display();
    void operation();
};

void Car::setColor(string color){
    this -> color = color;
}
string Car::getColor(){
    return color;
}
void Car::setSerial(){
    return serial;
}

void Car::operation(){
    if(type == "truck")
    cout << serial << ": Load as much as you can" << endl;
    if(type == "Sedan")
    cout << serial << ": Run as fast as you can" << endl;
}
void Car::display(){
    cout << "Car Info" << endl;
    cout << "[" << type << "] [" << color << "] [" << serial << "]" << endl << endl;
}

int main(){
    Car car1;
    car1.setColor("white");
    car1.setType("truck");
    car1.setSerial("1234");

    Car car2;
    car2.setColor("black");
    car2.setType("Sedan");
    car2.setSerial("3456");

    Car car3;
    car3.setColor("Red");
    car3.setType("Sedan");
    car3.setSerial("5678");

    car1.display();
    car2.display();
    car3.display();

    car1.operation();
    car2.operation();
    car3.operation();
}