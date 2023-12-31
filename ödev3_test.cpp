//
// Created by sahin on 25.12.2023.
//

#include "ödev3.h"


using namespace std;

int main() {
    // Nokta sınıfını test etme
    Nokta nokta1; // Parametresiz yapıcı
    Nokta nokta2(3.0); // Tek parametreli yapıcı
    Nokta nokta3(4.0, 5.0); // İki parametreli yapıcı
    Nokta nokta4(nokta3); // Başka bir noktanın kopyasını alarak yapıcı
    Nokta nokta5(nokta4, 6.0, 7.0); // Başka bir nokta ve ofset ile yapıcı

    std::cout << "Nokta1: ";
    nokta1.yazdir();
    std::cout << std::endl;

    std::cout << "Nokta2: ";
    nokta2.yazdir();
    std::cout << std::endl;

    std::cout << "Nokta3: ";
    nokta3.yazdir();
    std::cout << std::endl;

    std::cout << "Nokta4: ";
    nokta4.yazdir();
    std::cout << std::endl;

    std::cout << "Nokta5: ";
    nokta5.yazdir();
    std::cout << std::endl;

    // DogruParcasi sınıfını test etme
    DogruParcasi dogruParca1(nokta1, nokta2);
    DogruParcasi dogruParca2(nokta3, nokta5);
    DogruParcasi dogruParca3(nokta2, nokta5);

    std::cout << "DogruParca1: ";
    dogruParca1.yazdir();
    std::cout << std::endl;

    std::cout << "DogruParca2: ";
    dogruParca2.yazdir();
    std::cout << std::endl;

    std::cout << "DogruParca3: ";
    dogruParca3.yazdir();
    std::cout << std::endl;

    std::cout << "DogruParca1 Uzunluk: " << dogruParca1.uzunluk() << std::endl;
    std::cout << "DogruParca2 Uzunluk: " << dogruParca2.uzunluk() << std::endl;
    std::cout << "DogruParca3 Uzunluk: " << dogruParca3.uzunluk() << std::endl;

    Nokta kesisimNoktasi = dogruParca1.kesisimNoktasi(nokta5);
    std::cout << "DogruParca1 ve Nokta5 Kesisim Noktasi: ";
    kesisimNoktasi.yazdir();
    std::cout << std::endl;

    Nokta ortaNokta = dogruParca2.ortaNokta();
    std::cout << "DogruParca2 Orta Nokta: ";
    ortaNokta.yazdir();
    std::cout << std::endl;

    // Ucgen sınıfını test etme
    Ucgen ucgen1(nokta1, nokta2, nokta3);
    Ucgen ucgen2(nokta2, nokta3, nokta5);
    Ucgen ucgen3(nokta2, nokta4, nokta5);

    std::cout << "Ucgen1 Alan: " << ucgen1.alan() << std::endl;
    std::cout << "Ucgen2 Alan: " << ucgen2.alan() << std::endl;
    std::cout << "Ucgen3 Alan: " << ucgen3.alan() << std::endl;

    std::cout << "Ucgen1 Cevre: " << ucgen1.cevre() << std::endl;
    std::cout << "Ucgen2 Cevre: " << ucgen2.cevre() << std::endl;
    std::cout << "Ucgen3 Cevre: " << ucgen3.cevre() << std::endl;

    std::vector<double> acilarUcgen1 = ucgen1.acilar();
    std::cout << "Ucgen1 Aci1: " << acilarUcgen1[0] << " derece" << std::endl;
    std::cout << "Ucgen1 Aci2: " << acilarUcgen1[1] << " derece" << std::endl;
    std::cout << "Ucgen1 Aci3: " << acilarUcgen1[2] << " derece" << std::endl;

    std::vector<double> acilarUcgen2 = ucgen2.acilar();
    std::cout << "Ucgen2 Aci1: " << acilarUcgen2[0] << " derece" << std::endl;
    std::cout << "Ucgen2 Aci2: " << acilarUcgen2[1] << " derece" << std::endl;
    std::cout << "Ucgen2 Aci3: " << acilarUcgen2[2] << " derece" << std::endl;

    std::vector<double> acilarUcgen3 = ucgen3.acilar();
    std::cout << "Ucgen3 Aci1: " << acilarUcgen3[0] << " derece" << std::endl;
    std::cout << "Ucgen3 Aci2: " << acilarUcgen3[1] << " derece" << std::endl;
    std::cout << "Ucgen3 Aci3: " << acilarUcgen3[2] << " derece" << std::endl;

    // Daire nesneleri oluşturuluyor
    Nokta merkez1(0, 0);
    Daire daire1(merkez1, 3);

    Nokta merkez2(5, 5);
    Daire daire2(merkez2, 2);

    // Daire bilgileri yazdırılıyor
    cout << "Daire1 Bilgileri:" << endl;
    daire1.yazdir();
    cout << "Alan: " << daire1.alan() << endl;
    cout << "Cevre: " << daire1.cevre() << endl;

    cout << endl;

    cout << "Daire2 Bilgileri:" << endl;
    daire2.yazdir();
    cout << "Alan: " << daire2.alan() << endl;
    cout << "Cevre: " << daire2.cevre() << endl;

    // İki dairenin kesişim durumu kontrol ediliyor
    int kesisimDurumu = daire1.kesisim(daire2);
    cout << "Kesişim Durumu: ";
    if (kesisimDurumu == 0) {
        cout << "Kesişim Yok" << endl;
    } else if (kesisimDurumu == 1) {
        cout << "İç İçe" << endl;
    } else {
        cout << "İki Daire Kesişiyor" << endl;
    }

    return 0;
}