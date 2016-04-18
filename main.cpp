#include <iostream>
#include "Polygon.h"

std::ostream& operator << (std::ostream &ostream, Polygon& polygon)
{
    double **tmp;

    ostream << "Тип: " << polygon.type() << "\n";
    ostream << "Количество вершин : " << polygon.get_vertices() << "\n";

    tmp = polygon.get_coords();

    ostream << "Координаты вершин : " << "\n";
    for (int i = 0; i < polygon.get_vertices(); ++i)
    {
        ostream << "(" << tmp[i][0] << " ; " << tmp[i][1] << ")" << "\n";
        delete[] tmp[i];
    }
    delete[] tmp;

    ostream << "Периметр: " << polygon.get_perimeter() << "\n";
    ostream << "Площадь: " << polygon.get_area() << "\n";

    return ostream;

}

std::ostream& operator << (std::ostream &ostream, Triangle& t)
{

    double **tmp;

    ostream << "Тип: " << t.type() << "\n";
    ostream << "Количество вершин : " << t.get_vertices() << "\n";

    tmp = t.get_coords();



    ostream << "Координаты вершин : " << "\n";
    for (int i = 0; i < t.get_vertices(); ++i)
    {
        ostream << "(" << tmp[i][0] << " ; " << tmp[i][1] << ")" << "\n";
        delete[] tmp[i];
    }
    delete[] tmp;
    tmp = NULL;

    ostream << "Длины сторон: " << t.get_a() << " ; " << t.get_b() << " ; " << t.get_c() << "\n";
    ostream << "Периметр: " << t.get_perimeter() << "\n";
    ostream << "Площадь: " << t.get_area() << "\n";

    double *arr;
    arr = t.medians_calc();

    ostream << "Длины медиан: " << arr[0] << " ; " << arr[1] << " ; " << arr[2] << "\n";

    delete[] arr;

    arr = t.bisectors_calc();

    ostream << "Длины биссектрис: " << arr[0] << " ; " << arr[1] << " ; " << arr[2] << "\n";

    delete[] arr;

    arr = t.height_calc();

    ostream << "Длины высот: " << arr[0] << " ; " << arr[1] << " ; " << arr[2] << "\n";

    delete[] arr;

    arr = t.medians_intersection();

    ostream << "Пересечение медиан: (" << arr[0] << " ; " << arr[1] << ")\n";

    delete[] arr;

    arr = t.bisectors_intersection();

    ostream << "Пересечение биссектрис: (" << arr[0] << " ; " << arr[1] << ")\n";

    delete[] arr;

    arr = t.height_intersection();

    ostream << "Пересечение высот: (" << arr[0] << " ; " << arr[1] << ")\n";

    delete[] arr;

    return ostream;

}


std::ostream& operator << (std::ostream &ostream, Rectangle& r)
{

    double **tmp;

    ostream << "Тип: " << r.type() << "\n";
    ostream << "Количество вершин : " << r.get_vertices() << "\n";

    tmp = r.get_coords();



    ostream << "Координаты вершин : " << "\n";
    for (int i = 0; i < r.get_vertices(); ++i)
    {
        ostream << "(" << tmp[i][0] << " ; " << tmp[i][1] << ")" << "\n";
        delete[] tmp[i];
    }
    delete[] tmp;
    tmp = NULL;

    ostream << "Длины сторон: " << r.get_a() << " ; " << r.get_b() << " ; " << r.get_c() << " ; " << r.get_d() <<"\n";
    ostream << "Длина диагоналей: " << r.diagonals_length() <<"\n";
    ostream << "Периметр: " << r.get_perimeter() << "\n";
    ostream << "Площадь: " << r.get_area() << "\n";


}

int main() {

    int v1 = 3;
    int v2 = 4;
    int v3 = 6;
    double **coord1;
    double **coord2;
    double **coord3;

    coord1 = new double*[v1];
    coord2 = new double*[v2];
    coord3 = new double*[v3];

    for (int j = 0; j < v1; ++j) {
        coord1[j] = new double[2];
    }

    for (int j = 0; j < v2; ++j) {
        coord2[j] = new double[2];
    }

    for (int j = 0; j < v3; ++j) {
        coord3[j] = new double[2];
    }


    coord1[0][0] = 2.5;
    coord1[0][1] = 8.1;
    coord1[1][0] = 1.8;
    coord1[1][1] = 3.0;
    coord1[2][0] = 3.0;
    coord1[2][1] = 1.0;

    coord2[0][0] = 2.0;
    coord2[0][1] = 5.5;
    coord2[1][0] = 2.0;
    coord2[1][1] = 2.0;
    coord2[2][0] = 3.0;
    coord2[2][1] = 2.0;
    coord2[3][0] = 3.0;
    coord2[3][1] = 5.5;

    coord3[0][0] = 0.3;
    coord3[0][1] = 5.0;
    coord3[1][0] = 0.2;
    coord3[1][1] = 1.0;
    coord3[2][0] = 1.0;
    coord3[2][1] = 0.8;
    coord3[3][0] = 5.0;
    coord3[3][1] = 4.0;
    coord3[4][0] = 1.8;
    coord3[4][1] = 3.1;
    coord3[5][0] = 2.3;
    coord3[5][1] = 6.0;




    int n = 3;
    Polygon *array[n];

    array[0] = new Triangle(coord1);


    array[1] = new Rectangle(coord2);
    array[2] = new Polygon(coord3, 6);

    std::cout << *(array[0]) << "\n";
    std::cout << *(array[1]) << "\n";
    std::cout << *(array[2]) << "\n";

    delete array[0];
    delete array[1];
    delete array[2];
    // Теперь не по ссылке.


    Triangle *t = new Triangle(coord1);
    Rectangle *r = new Rectangle(coord2);
    Polygon *p = new Polygon(coord3, 5);


    std::cout << *t << "\n";
    std::cout << *r << "\n";
    std::cout << *p << "\n";\

    delete t;
    delete r;
    delete p;


    for (int i = 0; i < v1; ++i) {
        delete[] coord1[i];
    }

    for (int i = 0; i < v2; ++i) {
        delete[] coord2[i];
    }

    for (int i = 0; i < v3; ++i) {
        delete[] coord3[i];
    }

    delete[] coord1;
    delete[] coord2;
    delete[] coord3;

    return 0;
}