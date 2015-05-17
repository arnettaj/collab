//Author: Aaron Choi Austin Arnett Brian Bauer
//Course title: Data Structures
//Course Number: CS2028
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

//every class is derived from this polygon class
class Polygon{

  public:
    virtual int area() = 0;
    virtual int perimeter() = 0;
    
    

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
      return 0;
    }
    int perimeter(int x, int y){
      return 0;
    }

};
class Equallateral: public Triangle{
  //todo find area using side basic geometry remember the angles and stuff im too lazy
  public:
    int area(int side){
      return 0;
    }
    int perimeter(int side){
      return side*3;
    }

};
class Quadrilateral: public Polygon{
  
  public:
    virtual int area() = 0;
    virtual int perimeter() = 0;

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
      return (2 * height) * (2 * width);
    }

};
class Pentagon: public Polygon{
//theres a weird formula for area implement it
  public:
    int area(int side){
      return 0;
    }
    
    int perimeter(int side){
      return side * 5;
    }

};
class Hexagon: public Polygon{
//implement area of hexagon
  public:
    int area(int side){
      return 0;
    }
    int perimeter(int side){
      return side * 6;
    }
};

class Octagon: public Polygon{
//implement area of octogon
  public:
    int area(int side){
      return 0;
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
      cout << triangle.area(side) << "is your area and your perimeter is: " << triangle.perimeter(side);
      
    }
  }
  else if(polygon_type == "quadrilateral"){
    cout << "Is your quadrilateral a square or a rectangle";
    cin >> secondary_type;
  }
  else if(polygon_type == "pentagon"){
    cout << "Please enter the length of one of the sides.";
  
  }
  else if(polygon_type == "hexagon"){
  
    cout << "Please enter the length of one of the sides.";
  }
  else if(polygon_type == "octagon"){
  
    cout << "Please enter the length of one of the sides.";
  }
  else{
  
    cout << "Something went wrong. Please try again.";
  } 
  
  return 0;
}
