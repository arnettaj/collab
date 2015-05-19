//Author: Aaron Choi, Austin Arnett, Brian Bauer
//Course title: Data Structures
//Course Number: CS2028
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

//every class is derived from this polygon class
class Polygon{

  public:
    virtual int area(){return 0;}
    virtual int perimeter(){return 0;}



};
//there are also types of triangles hence the use of more inheritance
class Triangle: public Polygon{

  public:

    virtual int area(){
      return 0;
    }

    virtual int perimeter(){
      return 0;
    }

};
class Isosceles: public Triangle{
//todo take x and y find hypotenuse
//todo find area
//todo add 3 sides together to find perimeter
  public:
    int area(int x, int y){
      float hypo;
      float answer;
      if(x>y){
        hypo= sqrt(pow(x,2)-pow(y,2));
        answer=(y/2)*hypo;
      }
      else if(y>x){
        hypo= sqrt(pow(y,2)-pow(x,2));
        answer=(x/2)*hypo;
      }
      return hypo;
    }
    int perimeter(int x, int y){
      int answer;
      if(x>=y){answer=2*x+y;}
      else if(y>=x){answer=2*y+x;}
      return answer;
    }

};
class Equallateral: public Triangle{
  //todo find area using side basic geometry remember the angles and stuff im too lazy
  public:
    float area(int side){
      return (pow(3, .5)/4)*pow(side, 2);
    }
    int perimeter(int side){
      return side*3;
    }

};
class Quadrilateral: public Polygon{

  public:
    virtual int area(){
      return 0;
    }
    virtual int perimeter(){
      return 0;
    };

};

class Square: public Quadrilateral{

  public:
    int area(int side){
      return side * side;
    }
    int perimeter(int side){
      return side * 4;
    }


};
class Rectangle: public Quadrilateral{

  public:
    int area(int height, int width){
      return height * width;
    }
    int perimeter(int height, int width){
      return (2 * height) + (2 * width);
    }

};
class Pentagon: public Polygon{
//theres a weird formula for area implement it
  public:
    float area(int side){
      return (1.0/4.0)*sqrt(5*(5+2*sqrt(5)))*pow(side, 2);
    }

    int perimeter(int side){
      return side * 5;
    }

};
class Hexagon: public Polygon{
//implement area of hexagon
  public:
    float area(int side){
      return (3/2)*sqrt(3)*pow(side,2);
    }
    int perimeter(int side){
      return side * 6;
    }
};

class Octagon: public Polygon{
//implement area of octogon
  public:
    float area(int side){
      return 2*(1+sqrt(2))*pow(side, 2);
    }

    int perimeter(int side){
      return side * 8;
    }
};

int main() {
  string polygon_type = "";
  string secondary_type = "";

  cout << "Is your polygon a triangle, quadrilateral, pentagon, hexagon or octagon?\n";
  cin >> polygon_type;

  if(polygon_type == "triangle"){
    cout << "Is your triangle a isolsceles or equalateral triangle?";
    cin >> secondary_type;
    if(secondary_type == "isosceles"){
      cout << "Please enter the height and width of the triangle.";
    }
    else if(secondary_type =="equalateral"){
      cout << "Please enter one of the sides of the triangle.";
      int side = 0;
      Equallateral triangle;
      cin >> side;
      cout << triangle.area(side) << "is your area and your perimeter is: " << triangle.perimeter(side) << "\n";

    }
  }

  else if(polygon_type == "quadrilateral"){
    cout << "Is your quadrilateral a square or a rectangle? ";
    cin >> secondary_type;

    if(secondary_type == "square"){
      cout << "Please enter the length of a side of the square ";
      int side = 0;
      cin >> side;
      Square s;
      cout << s.area(side) << " is your area " << s.perimeter(side) << " is your perimeter" << "\n";
    }

    else if(secondary_type == "rectangle"){
      cout << "Please enter the height: ";
      int height = 0;
      int width = 0;
      cin >> height;
      cout << "Enter the width now: ";
      cin >> width;
      Rectangle r;
      cout << r.area(height, width) << " is your area " << r.perimeter(height, width) << " is your perimeter" << "\n";
    }

  }
  else if(polygon_type == "pentagon"){
    cout << "Please enter the length of the side.";
      int side = 0;
      cin >> side;
      Pentagon p;
      cout << p.area(side) << " is your area " << p.perimeter(side) << " is your perimeter." << "\n";
  }
  else if(polygon_type == "hexagon"){
    cout << "Please enter the length of one of the sides.";
    int side;
    cin>>side;
    Hexagon h;
    cout<<h.area(side) <<" is the area "<<h.perimeter(side)<<" is the perimeter. \n";
  }
  else if(polygon_type == "octagon"){

    cout << "Please enter the length of one of the sides.";
    int side;
    cin>>side;
    Octagon o;
    cout<<o.area(side)<<" is the area and "<<o.perimeter(side)<<" is the perimeter. \n";
  }
  else{

    cout << "Something went wrong. Please try again.";
  }

  return 0;
}
