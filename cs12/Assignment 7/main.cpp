// Course: CS 12 Spring 2012
//
// First Name: Zachary 
// Last Name: Sells
// Course username: zsell001
// email address: zsell001@ucr.edu
//
// Lecture Section: 001
// Lab Section: 025
// TA: Mirebrahim, Seyed Hamid
//
// Assignment: assn7
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================
#include <cmath>
#include "instinct.h"

// global consts:
const double PI = 3.14159265;
const double LENGTH = 25;
const double MIN_DISTANCE = 0.25;
const unsigned HEX_SIDES = 6;

double distance(Line l);

void print_flake(Point p,double length);


int instinct_main()
{
  // test harness for recursive function
  win.coord(0.0,0.0,100.0,100.0);
  Point p(50,50);//Center of coordinate plane
  print_flake(p,LENGTH);//You can change the second argument to however big you want the first line to be.
  win.output_buffer();//After all the recursion, output to window.
  return 0;
}
 
double distance(Line l)//Helper function to calculate length of a given line.
{
    double x,x1,y,y1;
    //Uses distance formula
    x = l.get_start().get_x();
    x1 = l.get_end().get_x();
    y = l.get_start().get_y();
    y1 = l.get_end().get_y();
    return sqrt((x1 - x) * (x1 - x) + (y1 - y)*(y1-y));
}

void print_flake(Point p, double length)
{
    Point p1(p.get_x() + length,p.get_y());
    Line l(p,p1);
    if(distance(l) < MIN_DISTANCE) return;//You can change how small you want to allow the line to get.
    win << l;
    
    for(unsigned i = 1; i <= HEX_SIDES; i++)
    {
        double x = p.get_x() + length * cos(i * (PI / 3));//Get new x coordinate
        double y = p.get_y() + length * sin(i * (PI / 3));//Get new y coordinate
        Point p2(x,y);//Construct point out of the new coordinates
        Line a(p,p2);//Construct line from current center to new point.
        win << a;//Send to window buffer
        print_flake(p2,(length/3));//Recursivly call print_flake with new center, and smaller length.
    }
}
