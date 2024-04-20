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
    this ->color = color;
}
string Car::getColor(){
    return color;
}

void Car::setSerial(string s){
    serial = s;
}
string Car::getSerial(){
    return serial;
}

void Car::operation(){
    if(type == "truck") cout << serial << ": Load as much as you can" << endl;
    if(type == "Sedan") cout << serial << ":Run as fast as you can" << endl;
}
void Car::display(){
    cout << "Car Info" << endl;
    cout << "[" << type << "] [" << color << "] [" << serial << "]" << endl << endl;
}

int main(){
    Car car[3];

    car[0].setColor("white");
    car[0].setType("truck");
    car[0].setSerial("1234");

    car[1].setColor("black");
    car[1].setType("Sedan");
    car[1].setSerial("3456");

    car[2].setColor("Red");
    car[2].setType("Sedan");
    car[2].setSerial("5678");

    for(int i = 0; i < 3; i++)
    car[i].display();
    for(int i = 0; i < 3; i++)
    car[i].operation();
}
