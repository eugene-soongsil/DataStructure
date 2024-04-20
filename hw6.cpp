#include <iostream>
using namespace std;

class Car{
    string type;
    string color;

    protected:
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
void Car::setSerial(string s){
    serial = s;
}
string Car::getSerial(){
    return serial;
}

void Car::operation(){
    if(type == "truck")
    cout << serial <<": Load as much as you can" << endl;
    if(type == "Sedan")
    cout << serial <<": Run as fast as you can" << endl;
}

void Car::display(){
    cout << "Car Info" << endl;
    cout << "[" << type << "] [" << color << "] [" << serial << "]" << endl << endl;
}

class Truck : public Car{
    int capacity;

    public:
    void setCapacity(int c){
        capacity = c;
    }
    int getCapacity(){
        return capacity;
    }

    void operation(){
        cout << "Truck" << serial << ": Load as much as you can" <, endl;
    }
};

class Sedan : public Car{
    int num_of_passengers;

    public:
    void setNum(int c){
        num_of_passengers = c;
    }
    int getNum(){
        return num_of_passengers;
    }

    void operation(){
        cout << "Sedan" << serial << ": Run as fast as you can" << endl;
    }
};

int main(){
    Truck* truck[3];
    Sedan* sedan[3];

    truck[0] = new Truck;
    truck[0] -> setColor("white");
    truck[0] -> setType("truck");
    truck[0] -> setSerial("1234");

    sedan[0] = new Sedan;
    sedan[0] -> setColor("black");
    sedan[0] -> setType("sedan");
    sedan[0] -> setSerial("3456");

    sedan[1] = new Sedan;
    sedan[1] -> setColor("Red");
    sedan[1] -> setType("sedan");
    sedan[1] -> setSerial("5678");

    truck[0] -> display();
    sedan[0] -> display();
    sedan[1] -> display();

    truck[0] -> operation();
    sedan[0] -> operation();
    sedan[1] -> operation();
    //delete 해줘야함
}