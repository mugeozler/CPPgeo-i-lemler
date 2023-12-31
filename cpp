//
// 
//

#include "ödev3.h"

using namespace std;

// Nokta Sınıfı
Nokta::Nokta() {
    setX(0);
    setY(0);
}
// Tek parametreli yapıcı
Nokta::Nokta(double value){
    setX(value);
    setY(value);
}
// İki parametreli yapıcı
Nokta::Nokta(double x, double y){
    setX(x);
    setY(y);
}
// Başka bir noktayı alıp o noktanın bir kopyasını yeni nokta olarak üreten yapıcı
Nokta::Nokta(Nokta& otherNokta) {
setX(otherNokta.getX());
setY(otherNokta.getY());
}
// Başka bir nokta (Nokta nesnesi) ve iki double değişken (ofset_x ve ofset_y) alarak yeni bir nokta (Nokta nesnesi)
// üretir ve ofset değişkenlerin ilk giriş parametresi olarak alınan orijinal noktanın x ve y koordinatlarına ekler.
Nokta::Nokta(Nokta& otherNokta, double offset_x, double offset_y) {
    setX(otherNokta.getX() + offset_x);
    setY(otherNokta.getY() + offset_y);
}
// X in set metotu
void Nokta::setX(double X){
    this->x = X;
}
// x nin get metotu
double Nokta::getX(){
    return x;
}
// y in set metotu
void Nokta::setY(double Y){
    this->y = Y;
}
// X in get metotu
double Nokta::getY(){
    return y;
}
void Nokta::set(double X,double Y){
    // koordinat değerleerini değiştiren fonskiyon
    setX(X);
    setY(Y);
}
string Nokta::toString(){
    // noktanın koordinat gösterimlerini string gösterimine döndüren fonksiyon
    return "(" + to_string(getX())+ ", " + to_string(getY())+")";
}

void Nokta::yazdir(){
    // bu string gösterimini yazdıran fonksiyon
    cout << toString();
}


// Doğru Parçası sınıfı
DogruParcasi::DogruParcasi(Nokta& n1, Nokta& n2) {
    setNokta1(n1);
    setNokta2(n2);
}
DogruParcasi::DogruParcasi(DogruParcasi& otherObject){
    setNokta1(otherObject.nokta1);
    setNokta2(otherObject.nokta2);
}
DogruParcasi::DogruParcasi(Nokta& ortaNokta, double lenght, double slope){
    // bir doğru parçasının uç noktalarını bulan constructor

double deltaX = lenght / (2 * sqrt(1 + pow(slope, 2)));
    // matematik förmüllerine dayanarak önce delta x'i bulduk
    // onun sayesinde de deltaY bulundu
    double deltaY = slope * deltaX;

    // Uç noktalar
    nokta1 = Nokta(ortaNokta.getX() - deltaX, ortaNokta.getX() - deltaY);
    nokta2 = Nokta(ortaNokta.getX() + deltaX, ortaNokta.getX() + deltaY);
}
void DogruParcasi::setNokta1(Nokta nokta1){
    this -> nokta1 = nokta1;
}
Nokta DogruParcasi::getNokta1(){
    return nokta1;
}
void DogruParcasi::setNokta2(Nokta nokta2){
    this -> nokta2 = nokta2;
}
Nokta DogruParcasi::getNokta2(){
    return nokta2;
}
Nokta DogruParcasi::kesisimNoktasi(Nokta nokta){
    // kesişim noktası bulunur

    // var olan noktanın eğimi
    double slope = (nokta2.getY() - nokta1.getY()) / (nokta2.getX() - nokta1.getX());
    // y = ax+ uzunluk2 denkelmindeki uzunluk2 değeri
    double intercept = nokta1.getY() - slope * nokta1.getX();

    // dik olarak çizilecek doğru parçasının eğimi
    double perpendicularSlope = -1 / slope;
    // dik olarak çizilecek doğru parçasının uzunluk2 değeri
    double perpendicularIntercept = nokta.getY() - perpendicularSlope * nokta.getX();

    // x ve y koordinat değerleri
    double x = (perpendicularIntercept - intercept) / (slope - perpendicularSlope);
    double y = slope * x + intercept;

    return Nokta(x, y);
}

Nokta DogruParcasi::ortaNokta(){;
    return Nokta((nokta1.getX() + nokta2.getX()) / 2, (nokta1.getY() + nokta2.getY()) / 2);
}

string DogruParcasi::toString(){
    // Geçerli DogruParcasi nesnesini String olarak döndürür
    return "Nokta1 : (" + to_string(nokta1.getX()) + ", " + to_string(nokta1.getY()) + "), Nokta 2: ("
           + to_string(nokta2.getX()) + ", " + to_string(nokta2.getY()) + ")";
}

double DogruParcasi::uzunluk(){
    // doğru parçasının uzunluğu hesaplayıp döndürür.
    double result;
    result = sqrt(pow(nokta2.getX() - nokta1.getX(), 2) + pow(nokta2.getY() - nokta1.getY(), 2));
    return result;
}

void DogruParcasi::yazdir(){
    cout << toString() << endl;
}


// Daire sınıfı
Daire::Daire(Nokta& merkez, double yaricap){
    this->merkez = merkez;
    this->yaricap = yaricap;
}
Daire::Daire(Daire& daire1){
    this->merkez = daire1.merkez;
    this->yaricap = daire1.yaricap;
}
Daire::Daire(Daire& daire1, double x){
    this -> merkez = daire1.merkez;
    this -> yaricap = daire1.yaricap * x;
}

double Daire::alan(){
    return M_PI * pow(yaricap, 2);
}

double Daire::cevre(){
    return 2 * M_PI * yaricap;
}

double Daire::kesisim(Daire daire1){
    double distance = sqrt(pow(merkez.getX() - daire1.merkez.getX(), 2) +
                           pow(merkez.getY() - daire1.merkez.getY(),2));

    if (distance < fabs(yaricap - daire1.yaricap)){
        return 0;
    }
    else if(distance == yaricap + daire1.yaricap){
        return 1;
    }
    else{
        return 2;
    }
}

string Daire::toString(){
    return "Merkez: (" + to_string(merkez.getX()) + ", " + to_string(merkez.getY()) +
           "), Yarıçap: " + to_string(yaricap);
}

void Daire::yazdir(){
    cout << toString() << endl;
}



// Üçgen sınıfı

Ucgen::Ucgen(Nokta& nokta1, Nokta& nokta2, Nokta& nokta3){
    setNokta1(nokta1);
    setNokta2(nokta2);
    setNokta3(nokta3);
}


void Ucgen::setNokta1(Nokta nokta1){
    this -> nokta1 = nokta1;
}

Nokta Ucgen::getNokta1(){
    return nokta1;
}

void Ucgen::setNokta2(Nokta nokta2){
    this -> nokta2 = nokta2;
}

Nokta Ucgen::getNokta2(){
    return nokta2;
}

void Ucgen::setNokta3(Nokta nokta3){
    this -> nokta3 = nokta3;
}

Nokta Ucgen::getNokta3(){
    return nokta3;
}

double Ucgen::alan(){
//        return fabs((nokta1.getX()*(nokta2.getY() - nokta3.getY())+ nokta2.getX()*(nokta3.getY()-nokta2.getY()) +
//        nokta3.getX()*(nokta1.getY()-nokta2.getY())));
    double uzunluk1 = DogruParcasi(nokta1, nokta2).uzunluk();
    double uzunluk2 = DogruParcasi(nokta2, nokta3).uzunluk();
    double uzunluk3 = DogruParcasi(nokta1, nokta3).uzunluk();

    if ( uzunluk1 == 0 || uzunluk2 == 0 || uzunluk3 == 0)
        return 0;

    // Üçgen alanını bulmak için çevresinin yarısı lazım
    double halfOfPermeter = (uzunluk1 + uzunluk2 + uzunluk3) / 2.0;

    return fabs(sqrt(halfOfPermeter * (halfOfPermeter - uzunluk1) * (halfOfPermeter - uzunluk2)
                     * (halfOfPermeter - uzunluk3)));
}

double Ucgen::cevre(){
    DogruParcasi dogruParcasi1(nokta1,nokta2);
    DogruParcasi dogruParcasi2(nokta2,nokta3);
    DogruParcasi dogruParcasi3(nokta1,nokta3);
    return dogruParcasi1.uzunluk() + dogruParcasi2.uzunluk() + dogruParcasi3.uzunluk();
}

vector<double> Ucgen::acilar(){
    double uzunluk1 = DogruParcasi(nokta1, nokta2).uzunluk();
    double uzunluk2 = DogruParcasi(nokta2, nokta3).uzunluk();
    double uzunluk3 = DogruParcasi(nokta1, nokta3).uzunluk();

    // iç açıları hesaplanır
    double inner_product1 = acos(((uzunluk2 * uzunluk2) + (uzunluk3 * uzunluk3) - (uzunluk1 * uzunluk1))
                                 / (2.0 * uzunluk2 * uzunluk3)) * 180 / M_PI;

    double inner_product2 = acos(((uzunluk1 * uzunluk1) + (uzunluk3 * uzunluk3) - (uzunluk2 * uzunluk2))
                                 / (2.0 * uzunluk1 * uzunluk3)) * 180 / M_PI;

    double inner_product3 = acos(((uzunluk1 * uzunluk1) + (uzunluk2 * uzunluk2) - (uzunluk3 * uzunluk3))
                                 / (2.0 * uzunluk1 * uzunluk2)) * 180 / M_PI;

    vector<double> result = {inner_product1, inner_product2, inner_product3};
    return result;
}

string Ucgen::toString(){
    return "Üçgen; onun noktaları: (" + to_string(nokta1.getX()) + ", " + to_string(nokta1.getY())
           + "), " + "(" + to_string(nokta2.getX()) + ", " + to_string(nokta2.getY()) + "), "
           + "(" + to_string(nokta3.getX()) + ", " + to_string(nokta3.getY()) + ")";
}

void Ucgen::yazdir(){
    cout << toString() << endl;
}






