//
// Created by gri on 16.04.16.
//


#include <iostream>
#include "Polygon.h"

double Polygon::get_area()
{
    double sum = 0.0;

    for (int i = 0; i < this->vertices-1; ++i) {
        sum += (this->coordinates[i][0] + this->coordinates[i+1][0])*(this->coordinates[i][1] - this->coordinates[i+1][1]);
    }
    sum *= 0.5;
    if (sum < 0) sum = -sum;
    return sum;
}

Polygon::Polygon(double **coordinates, int vertices)
{

    this->perimeter = 0.0;
    this->coordinates = new double*[vertices];
    for (int i = 0; i < vertices; ++i) {
        this->coordinates[i] = new double[2];
        this->coordinates[i][0] = coordinates[i][0];
        this->coordinates[i][1] = coordinates[i][1];
    }

    this->vertices = vertices;
}

Polygon::~Polygon()
{
    std::cout<<"Вызван деструктор <Polygon>"<<std::endl;
    for (int i = 0; i < this->vertices; ++i) {
        delete[] this->coordinates[i];
    }
    delete[] this->coordinates;
}


int Polygon::get_vertices() { return vertices; }


double Polygon::get_perimeter() {
    if (!perimeter) calc_perimeter();
    return perimeter;
}

void Polygon::calc_perimeter()
{
    double sum = 0;

    int i;
    for (i = 0; i < vertices-1; ++i)
    {
        sum += sqrt(pow((coordinates[i][0] - coordinates[i+1][0]),2) + pow((coordinates[i][1] - coordinates[i+1][1]),2));
    }
    sum+= sqrt(pow((coordinates[i][0] - coordinates[0][0]),2) + pow((coordinates[i][1] - coordinates[0][1]),2));
    perimeter = sum;
}


//std::ostream& Triangle::operator << (std::ostream &ostream,const Polygon &polygon)
//{

//}// в Stack.cpp !!!

Triangle::~Triangle()
{
    std::cout<<"Вызван деструктор <Triangle>"<<std::endl;

}


double Triangle::get_perimeter()
{
    if (!perimeter) {
        perimeter = a + b + c;
    }
    return perimeter;
}

void Triangle::calculate()
{
    a = sqrt(pow((coordinates[0][0] - coordinates[1][0]), 2) + pow((coordinates[0][1] - coordinates[1][1]), 2));
    b = sqrt(pow((coordinates[1][0] - coordinates[2][0]), 2) + pow((coordinates[1][1] - coordinates[2][1]), 2));
    c = sqrt(pow((coordinates[2][0] - coordinates[0][0]), 2) + pow((coordinates[2][1] - coordinates[0][1]), 2));
}

double Triangle::get_area()
{
    double x1 = coordinates[0][0];
    double x2 = coordinates[1][0];
    double x3 = coordinates[2][0];

    double y1 = coordinates[0][1];
    double y2 = coordinates[1][1];
    double y3 = coordinates[2][1];

    double area = (0.5* ((x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)));
    if (area < 0) area = -area;
    return area;
}

double* Triangle::medians_intersection()
{
    double *coord = new double[2];
    coord[0] = 1.0/3.0 * (this->coordinates[0][0] + this->coordinates[1][0] + this->coordinates[2][0]);
    coord[1] = 1.0/3.0 * (this->coordinates[0][1] + this->coordinates[1][1] + this->coordinates[2][1]);
    return coord;
}

double* Triangle::bisectors_intersection()
{
    double *coord = new double[2];
    double x1 = coordinates[0][0];
    double x2 = coordinates[1][0];
    double x3 = coordinates[2][0];

    double y1 = coordinates[0][1];
    double y2 = coordinates[1][1];
    double y3 = coordinates[2][1];

    coord[0] = (b*x1 + c*x2 + a*x3) / (a+b+c);
    coord[1] = (b*y1 + c*y2 + a*y3) / (a+b+c);
    return coord;
}


double* Triangle::height_intersection()
{
    double *coord = new double[2];
    double x1 = coordinates[0][0];
    double x2 = coordinates[1][0];
    double x3 = coordinates[2][0];

    double y1 = coordinates[0][1];
    double y2 = coordinates[1][1];
    double y3 = coordinates[2][1];

    coord[0] = ((y1 * ((x3*x1 + pow(y2,2)) - (x1*x2+pow(y3,2)))) - ((x2*x3+pow(y1,2))*(y2 - y3)) + (y2*(x1*x2+pow(y3,2)))-((x3*x1 + pow(y2,2))*y3)) / ((x1*(y2-y3) - y1*(x2-x3) + x2*y3 - y2*x3));
    coord[1] = ((pow(x1,2) + y2*y3) * (x2-x3) - x1 * ((pow(x2,2)+y3*y1) - (pow(x3,2) + y1*y2)) + ((pow(x2,2)+y3*y1)*x3 - (pow(x3,2) + y1*y2)*x2)) / ((x1*(y2-y3) - y1*(x2-x3) + x2*y3 - y2*x3));

    return coord;
}


double* Triangle::medians_calc()
{
    double* median = new double[3];
    median[0] = 0.5 * sqrt(2*pow(b,2) + 2*pow(c,2) - pow(a,2));
    median[1] = 0.5 * sqrt(2*pow(a,2) + 2*pow(c,2) - pow(b,2));
    median[2] = 0.5 * sqrt(2*pow(b,2) + 2*pow(a,2) - pow(c,2));
    return median;
}

double* Triangle::bisectors_calc()
{
    double* bis = new double[3];
    double p = this->get_perimeter()/2.0;
    bis[1] =2*sqrt(c*a*p*(p-b))/(c+a);
    bis[0] = 2*sqrt(c*b*p*(p-a))/(c+b);
    bis[2] = 2*sqrt(a*b*p*(p-c))/(a+b);
    return bis;
}

double* Triangle::height_calc()
{
    double *hieght = new double[3];
    double S = this->get_area();
    hieght[0] = 2*S / a;
    hieght[1] = 2*S / b;
    hieght[2] = 2*S / c;
    return hieght;

}


void Rectangle::calculate()
{
    a = sqrt(pow((coordinates[0][0] - coordinates[1][0]), 2) + pow((coordinates[0][1] - coordinates[1][1]), 2));
    b = sqrt(pow((coordinates[1][0] - coordinates[2][0]), 2) + pow((coordinates[1][1] - coordinates[2][1]), 2));
    c = sqrt(pow((coordinates[2][0] - coordinates[3][0]), 2) + pow((coordinates[2][1] - coordinates[3][1]), 2));
    d = sqrt(pow((coordinates[3][0] - coordinates[0][0]), 2) + pow((coordinates[3][1] - coordinates[0][1]), 2));

}

Rectangle::~Rectangle()
{
    std::cout<<"Вызван деструктор <Rectangle>"<<std::endl;

}

double Rectangle::diagonals_length()
{
    double length = 0;

    length = sqrt(pow(a,2) + pow(b,2));

    return length;

}

double Rectangle::get_perimeter()
{
    if (!perimeter)
    {
        perimeter = a + b + c + d;
    }
    return perimeter;
}

//std::ostream& Rectangle::operator << (std::ostream &ostream,const Polygon &polygon)
//{/

//}// в Stack.cpp !!!