//
// Created by sahin on 25.12.2023.
//

#ifndef UNTITLED_ÖDEV3_H
#define UNTITLED_ÖDEV3_H

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

class Nokta { // Nokta İlklendirmesi
private:
    double x;
    double y;

public:
    Nokta();
    Nokta(double value);
    Nokta(double x, double y);
    Nokta(Nokta& otherNokta);
    Nokta(Nokta& otherNokta, double offset_x, double offset_y);

    void setX(double X);
    double getX();
    void setY(double Y);
    double getY();
    void set(double X,double Y);
    std::string toString();
    void yazdir();
};

class DogruParcasi{ // Dogru parçası ilklendirmesi
private:
    Nokta nokta1;
    Nokta nokta2;

public:
    DogruParcasi(Nokta& n1, Nokta& n2);
    DogruParcasi(DogruParcasi& otherObject);
    DogruParcasi(Nokta& ortaNokta, double lenght, double slope);

    void setNokta1(Nokta nokta1);
    Nokta getNokta1();
    void setNokta2(Nokta nokta2);
    Nokta getNokta2();
    double uzunluk();
    Nokta kesisimNoktasi(Nokta nokta);
    Nokta ortaNokta();
    std::string toString();
    void yazdir();
};


class Daire{
private:
    Nokta merkez;
    double yaricap;
public:
    Daire(Nokta& merkez, double yaricap);
    Daire(Daire& daire1);
    Daire(Daire& daire1, double x);
    double alan();
    double cevre();
    double kesisim(Daire daire1);
    std::string toString();
    void yazdir();
};

class Ucgen{
private:
    Nokta nokta1;
    Nokta nokta2;
    Nokta nokta3;
public:
    Ucgen(Nokta& nokta1, Nokta& nokta2, Nokta& nokta3);
    void setNokta1(Nokta nokta1);
    Nokta getNokta1();
    void setNokta2(Nokta nokta2);
    Nokta getNokta2();
    void setNokta3(Nokta nokta3);
    Nokta getNokta3();
    double alan();
    double cevre();
    std::vector<double> acilar();
    std::string toString();
    void yazdir();

};

#endif //UNTITLED_ÖDEV3_H
