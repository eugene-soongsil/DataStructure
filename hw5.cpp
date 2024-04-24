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
    this -> color = color 
//this는 객체자신(시작주소)을 가리키는 포인터, 매개변수 string color가 class의 변수 color와 이름이 같아서 사용
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
    if(type == "sedan") cout << serial << ": Run as fast as you can" << endl;
}

void Car::display(){
    cout << "Car Info" << endl;
    cout << "[" << type << "] [" << color << "] [" << serial << "]" << endl; << endl;
}

int main(){
    //Car객체를 가르키는 car포인터 3개 생성(초기화 x)
    Car* car[3];

    for(int i = 0; i < 3; i++)
    car[i] = new Car;
    //각각의 car포인터에 Car객체의 크기만큼의 공간을 할당함(new) - 초기화
    //여기서는 delete 없어도 되는지..? -> 있어야 한다 ! 근데 교수님 코드엔 없음

    car[0] -> setColor("white");
    car[0] -> setType("truck");
    car[0] -> setSerial("1234");

    car[1] -> setColor("black");
    car[1] -> setType("Sedan");
    car[1] -> setSerial("3456");

    car[2] -> setColor("Red");
    car[2] -> setType("Sedan");
    car[2] -> setSerial("5678");

    for(int i = 0; i < 3; i++)
    car[i] -> display();
    for(int i = 0; i < 3; i++)
    car[i] -> operation();
    //for(int i = 0; i < 3; i++) delete Car;
}

