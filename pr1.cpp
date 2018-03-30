// #include "stdafx.h" 
#include <iostream> // Будем работать с стандарьным выводом
using namespace std;
const double PI = 3.1415926535897932384626433832795;
// объект ФИГУРА
class shape {
    int abscissa, ordinate;
public:
shape();
shape(int x, int y);
virtual ~shape();
void move(int x, int y);
virtual void draw() = 0;
};
shape::shape() : abscissa(0), ordinate(0) {
}
shape::shape(int x, int y): abscissa(x), ordinate(y){
}
shape::~shape() {
}
void shape::move(int x, int y) {
    abscissa = x;
    ordinate = y;
}
// Наследуем новый объект -окружность
class circle : public shape {
    float radius;
public:
    circle(float rad); //Обычный конструктор
    circle(float rad, int newAbscissa, int newOrdinate); // конструктор с перезагрузкой
    ~circle();
    void setRadius(float newRadius);
    float getRadius() const;
    float getArea() const;
    float getPerimeter() const;
    int isEqual(circle c) const; 
    void SetNewLocation(int newAbscissa, int newOrdinate);
    void draw();
};
circle::circle(float rad) : shape(), radius(rad) {
if(rad>10){
    throw ("Radius over 10");
  }
}
circle::circle(float rad, int newAbscissa, int newOrdinate): shape(newAbscissa, newOrdinate),
radius(rad) {
if(newAbscissa>10||newAbscissa<-10){
    throw ("newAbscissa over 10"); // проверка на исключение
  }
if(newOrdinate>10||newAbscissa<-10){
    throw ("newAbscissa over 10");
  }
}
circle::~circle(){
}
void circle::setRadius(float newRadius){
    radius = newRadius;
}
float circle::getRadius() const {
    return radius;
}
float circle::getArea() const {
    return PI*radius*radius;
}
float circle::getPerimeter() const {
    return 2*radius*PI;
}
int circle::isEqual(circle c) const {
    return (c.getArea()==getArea());
};
void circle::SetNewLocation(int newAbscissa, int newOrdinate) {
    move(newAbscissa,newOrdinate);
}
// Выводит информацию об объекте, упрощенная проп\рисовка
void circle::draw() {
 cout << "circle with radius: " << radius << endl << "Area: " << getArea() << endl <<
 "Perimeter: " << getPerimeter() << endl;
}
// Наследуем новый объект - прямоугольник, можно и другие создавать
/*
class rect : public shape{
    int width, height;
public:
    rect(int w, int h);
 ~rect();
 void draw();
};
rect::rect(int w, int h) : shape(), width(w), height(h) {
}
rect::~rect() {
}
void rect::draw() {   
    cout << "Rectangle with width: " << width << " and height: " << height << end1;
}
*/
int main(int argc, char* argv[]) {
    //Определяем окружность и создаем ее
    circle *c = new circle(10);
   // Для лучшего понимания идеи будем работать как с фигурой
    shape *s;
    s = c;
    //Выводим информацию об объекте
    s->draw();
    //Вызываем исключение
    circle *c2 = new circle(10, 11, 34); // координаты не входят в пределы
    circle *c3 = new circle(11, 5, 5); // радиус больше
    return 0;
}