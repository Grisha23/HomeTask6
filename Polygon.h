//
// Created by gri on 16.04.16.
//

#ifndef HOMETASK6_POLYGON_H
#define HOMETASK6_POLYGON_H


//#include <bits/mathdef.h>
#include <math.h>
#include <string>
#include "string.h"

class Polygon {

private:

    void calc_perimeter();

protected:
    int vertices;
    double **coordinates;
    double perimeter;


public:

    Polygon(double **coordinates, int vertices); // Конструктор в protected?
    virtual ~Polygon();


    int get_vertices();

    double ** get_coords()
    {
        double **coord_tmp = new double*[vertices];

        for (int i = 0; i < vertices; ++i)
        {
            coord_tmp[i] = new double[2];
            coord_tmp[i][0] = coordinates[i][0];
            coord_tmp[i][1] = coordinates[i][1];
        }

        return coord_tmp;
    }

    virtual double get_perimeter(); // Сделаю виртуальным, чтобы сократить вычисления.

    virtual std::string type() {
        std::string tmp(std::to_string(this->vertices));
        tmp += "-угольник";
        return (tmp);
    }
    virtual double get_area();

   // virtual std::istream& operator >> (std::istream &istream, Polygon &polygon);


};


class Triangle : public Polygon {
private:
    double a;
    double b;
    double c;

    void calculate();

protected:


public:
//    std::ostream& operator << (std::ostream &ostream,const Polygon &polygon); // в Stack.cpp !!!

    Triangle(double **coordinates) : Polygon(coordinates, 3) { a = 0; b = 0; c = 0;  calculate(); } // ?
    ~Triangle();

    double get_a() { return a; }
    double get_b() { return b; }
    double get_c() { return c; }



    double get_perimeter();



    std::string type() { return "Треугольник"; }

    double get_area();

    double* medians_intersection(); //Точки пересечения
    double* bisectors_intersection();
    double* height_intersection();

    double* medians_calc();// Длины
    double* bisectors_calc();
    double* height_calc();






};


class Rectangle: public Polygon {
private:
    double a;
    double b;
    double c;
    double d;


    void calculate();

protected:


public:

 //   std::ostream& operator << (std::ostream &ostream,const Polygon &polygon); //

    Rectangle(double** coordinates) : Polygon(coordinates, 4) {a = 0; b = 0; c = 0;  calculate(); };
    ~Rectangle();

    double get_a() { return a;};
    double get_b() { return b;};
    double get_c() { return c;};
    double get_d(){ return d;};

    std::string type() { return "Прямоугольник"; }

    double get_perimeter();
    double get_area() { return (a*b); }
    double diagonals_length();







};


#endif //HOMETASK6_POLYGON_H
