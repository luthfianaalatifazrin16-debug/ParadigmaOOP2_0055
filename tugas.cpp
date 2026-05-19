#include <iostream>
using namespace std;

// Abstract Base Class
class RekeningBank
{
protected:
    string nama;
    double saldo;

public:
    RekeningBank(string pNama, double pSaldo)
    {
        nama = pNama;
        saldo = pSaldo;
    }

    virtual void potongAdmin() = 0;

    void tampilSaldo()
    {
        cout << "Nama  : " << nama << endl;
        cout << "Saldo : Rp " << saldo << endl;
    }
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank
{
public:
    RekeningSyariah(string pNama, double pSaldo)
        : RekeningBank(pNama, pSaldo) {}

    void potongAdmin() override
    {
        cout << "Rekening Syariah bebas biaya admin\n";
    }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank
{
public:
    RekeningKonvensional(string pNama, double pSaldo)
        : RekeningBank(pNama, pSaldo) {}

    void potongAdmin() override
    {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 dipotong\n";
    }
};

// Rekening Premium
class RekeningPremium : public RekeningBank
{
public:
    RekeningPremium(string pNama, double pSaldo)
        : RekeningBank(pNama, pSaldo) {}

    void potongAdmin() override
    {
        if (saldo > 10000000)
        {
            cout << "Saldo di atas 10 juta, bebas admin\n";
        }
        else
        {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 dipotong\n";
        }
    }
};

int main()
{

    RekeningBank *rb;

    RekeningSyariah rs("Andi", 5000000);
    RekeningKonvensional rk("Budi", 7000000);
    RekeningPremium rp("Caca", 9000000);

    // Syariah
    rb = &rs;
    rb->potongAdmin();
    rb->tampilSaldo();

    cout << endl;

    // Konvensional
    rb = &rk;
    rb->potongAdmin();
    rb->tampilSaldo();

    cout << endl;

    // Premium
    rb = &rp;
    rb->potongAdmin();
    rb->tampilSaldo();

    return 0;
}