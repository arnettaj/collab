//Author: Aaron Choi, Austin Arnett, Brian Bauer
//Course title: Data Structures
//Course Number: 20CS2028
//Abstract:  This program finds the area and parimeter of the shape chosen.  The polygons are all regular. Only special polygons are isoceles, equalateral triangles and squares and rectangles which are the only quadrilaterals calculated. We did not see a scalene triangle req. so dont try that. You must choose from the list the program gives you.
//Preconditions:  Follow the prompts.  Enter the name exactly as it appears or else.
//Postconditions: Answer printed out. Or a giant pikachu will appear and eat you.
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
    virtual float area()= 0;
    virtual int perimeter()=0;

  protected:
  float area_poly;
  int perimeter_poly;

};
//there are also types of triangles hence the use of more inheritance
class Triangle: public Polygon{

  public:

    virtual float area(){
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
    
    int iso_area(int base, int other){
      float height;
      float answer;
      height= sqrt(pow(other,2)-pow(base/2,2));
      answer=base*height/2;
      return answer;
    }
    int iso_perimeter(int x, int y){
      return x+2*y;
    }
    
    void response(){
     
      int side1=0;
      int side2=0;
      cout << "Please enter the base of the triangle.";
      cin>>side1;
      cout<<"Please enter the length of one of the two equal sides.";
      cin>>side2;
      area_poly = iso_area(side1, side2);
      perimeter_poly = iso_perimeter(side1, side2);
      if((side1 + side2) < side2){
        cout << "Who you tryna fool these sides can't make up a triangle";
      }
      else if((side2+side2)< side1){
        cout << "Who you tryna fool these sides can't make up a triangle";
      }
      else
      cout<< "The area is "<< area() << " and the perimeter is " << perimeter() <<endl;
    }
    virtual float area(){
    
      return area_poly;
    }
    virtual int perimeter(){
    
      return perimeter_poly;
    }

};
class Equallateral: public Triangle{
  //todo find area using side basic geometry remember the angles and stuff im too lazy
  public:
    float equal_area(int side){
      return (pow(3, .5)/4)*pow(side, 2);
    }
    int equal_perimeter(int side){
      return side*3;
    }
    void response(){
      int side = 0;
      cout << "Please enter one of the sides of the triangle.";
      cin >> side;
      area_poly = equal_area(side);
      perimeter_poly = equal_perimeter(side);
      cout << "The area is "<< area() << " and the perimeter is " << perimeter() <<endl;
    }
    virtual float area(){
      return area_poly;
    }
    virtual int perimeter(){
    
      return perimeter_poly;
    }

};
class Quadrilateral: public Polygon{

  public:
    virtual float area(){
      return 0;
    }
    virtual int perimeter(){
      return 0;
    }

};

class Square: public Quadrilateral{

  public:
    int s_area(int side){
      return side * side;
    }
    int s_perimeter(int side){
      return side * 4;
    }
    void response(){
      int side = 0;
      cout << "Please enter the length of a side of the square ";
      cin >> side;
      area_poly = s_area(side);
      perimeter_poly = s_perimeter(side);
      cout << "The area is "<< area() << " and the perimeter is " << perimeter() <<endl;
    }
    virtual float area(){
      return area_poly;
    }
    virtual int perimeter(){
      return perimeter_poly;
    
    }


};
class Rectangle: public Quadrilateral{

  public:
    int r_area(int height, int width){
      return height * width;
    }
    int r_perimeter(int height, int width){
      return (2 * height) + (2 * width);
    }
    void response(){
      int height = 0;
      int width = 0;
      cout << "Please enter the height: ";
      
      cin >> height;
      cout << "Enter the width now: ";
      cin >> width;
      area_poly = r_area(height, width);
      perimeter_poly = r_perimeter(height, width);
      cout << "The area is "<< area() << " and the perimeter is " << perimeter() <<endl;
    }
    virtual float area(){
     return area_poly;
    }
    virtual int perimeter(){
    return perimeter_poly;
    
    }

};
class Pentagon: public Polygon{
//theres a weird formula for area implement it
  public:
    float p_area(int side){
      return (1.0/4.0)*sqrt(5*(5+2*sqrt(5)))*pow(side, 2);
    }

    int p_perimeter(int side){
      return side * 5;
    }
    void response(){
      cout << "Please enter the length of the side.";
      int side = 0;
      cin >> side;
      area_poly = p_area(side);
      perimeter_poly = p_perimeter(side);
      cout << "The area is "<< area() << " and the perimeter is " << perimeter() <<endl;
    }
    virtual float area(){
      return area_poly;
    }
    virtual int perimeter(){
      return perimeter_poly;
    }
};
class Hexagon: public Polygon{
//implement area of hexagon
  public:
    float h_area(int side){
      return (3.0/2.0)*sqrt(3.0)*pow(side,2);
    }
    int h_perimeter(int side){
      return side * 6;
    }
    void response(){
      cout << "Please enter the length of the side.";
      int side = 0;
      cin >> side;
      area_poly = h_area(side);
      perimeter_poly = h_perimeter(side);
      cout << "The area is "<< area() << " and the perimeter is " << perimeter() <<endl;
    }
    virtual float area(){
     return area_poly;
     
    }
    virtual int perimeter(){
      return perimeter_poly;
    
    }
};

class Octagon: public Polygon{
//implement area of octogon
  public:
    float o_area(int side){
      return 2*(1+sqrt(2))*pow(side, 2);
    }

    int o_perimeter(int side){
      return side * 8;
    }
    void response(){
      cout << "Please enter the length of the side.";
      int side = 0;
      cin >> side;
      area_poly = o_area(side);
      perimeter_poly = o_perimeter(side);
      cout << "The area is "<< area() << " and the perimeter is " << perimeter() <<endl;
    }
    virtual float area(){
     return area_poly;
    }
    virtual int perimeter(){
      return perimeter_poly;
    
    }
};

int main() {
  string polygon_type = "";
  string secondary_type = "";

  cout << "Is your polygon a triangle, quadrilateral, pentagon, hexagon or octagon?\n";
  cin >> polygon_type;

  if(polygon_type == "triangle"){
    cout << "Is your triangle a isosceles or equalateral triangle?";
    cin >> secondary_type;
    if(secondary_type == "isosceles"){
      Isosceles triangle;
      triangle.response();
    }
    else if(secondary_type =="equalateral"){
      Equallateral triangle;
      triangle.response();
    }
  }

  else if(polygon_type == "quadrilateral"){
    cout << "Is your quadrilateral a square or a rectangle? ";
    cin >> secondary_type;

    if(secondary_type == "square"){
      
      Square s;
      s.response();
    }

    else if(secondary_type == "rectangle"){
      
      Rectangle r;
      r.response();
    }

  }
  else if(polygon_type == "pentagon"){
    
      Pentagon p;
      p.response();
  }
  else if(polygon_type == "hexagon"){
    
    Hexagon h;
    h.response();
  }
  else if(polygon_type == "octagon"){

    Octagon o;
    o.response();;
  }
  else{

    cout << "Something went wrong. Please try again or just give me an A and be on your merry way :) I used to be a ta too you know. I know the pain.";
  }

  return 0;
}
