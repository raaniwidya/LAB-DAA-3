#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct datamhs
{
    int no;
    string nim;
    string nama;
    string tgllahir;
    int jlhmatkul;
    string matkul[50];
};

int jlhmhs = 0;
struct datamhs mhs[125];

void newdata(int no)
{
    int jlh;
    cout<<"NIM              : ";
    cin>> mhs[no].nim;

    cout<<"Nama             : ";
    cin.ignore();
    getline(cin, mhs[no].nama);


    cout<<"Tanggal Lahir            : ";
    cin>> mhs[no].tgllahir;

    cout<<"Jumlah Mata Kuliah : ";
    cin>>jlh;
    fflush(stdin);
    mhs[no].jlhmatkul = jlh;

    cout<<"Mata Kuliah   : \n";
    for (int i = 0; i < jlh; i++)
    {
        cout<<i + 1<<". ";
        cin.ignore();
        getline(cin, mhs[no].matkul[i]);
    }
}

void create()
{
    int temp;
    cout << "Masukkan Jumlah Mahasiswa : ";
    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        cout<<"\nKe - "<< jlhmhs + 1<<"\n";
        newdata(jlhmhs);
        mhs[jlhmhs].no = jlhmhs + 1;
        jlhmhs++;
    }
}

void read()
{
    if (jlhmhs == 0)
    {
        cout<<"\nTambahkan data terlebih dahulu" << endl;
    }
    else
    {
        cout<<"+==================================+\n";
        cout<<"|         Data Mahasiswa          |\n";
        cout<<"+==================================+\n";
        for (int i = 0; i < jlhmhs; i++)
        {
            if (!mhs[i].no)
                continue;
            cout<<"Mahasiswa ke - \n"<<i + 1<<"\n";
            cout<<"NIM            : "<<mhs[i].nim<<"\n";
            cout<<"Nama           : "<<mhs[i].nama<<"\n";
            cout<<"Tanggal Lahir  : "<<mhs[i].tgllahir<<"\n";
            cout<<"Mata Kuliah    : "<<mhs[i].jlhmatkul;
            for (int j = 0; j < mhs[i].jlhmatkul; j++)
            {
                cout<<"\n"<< j + 1<<". "<< mhs[i].matkul[j].c_str();
            }
            cout<<"\n";
        }
    }
    cout << "Tekan sembarang untuk kembali..." << endl;
    char hold_view;
    hold_view = getch();
}

void update()
{
    int no;
    cout<<"Nomor mahasiswa : ";
    cin >> no;
    newdata(no - 1);
}

void del()
{
    int no;
    cout<<"Nomor mahasiswa : ";
    cin >> no;
    no--;
    mhs[no].nim      = "";
    mhs[no].nama     = "";
    mhs[no].tgllahir = "";
    int jlh = mhs[no].jlhmatkul;
    mhs[no].jlhmatkul = 0;
    for (int i = 0; i < jlh; i++)
    {
        mhs[no].matkul[i] = "";
    }
}

int main()
{
    int pil;
    while (true)
    {
        system("cls");
        cout<<"Program CRUD Mahasiswa :\n";
        cout<<"1. Tambah data mahasiswa \n";
        cout<<"2. Tampilkan data mahasiswa\n";
        cout<<"3. Perbarui data mahasiswa\n";
        cout<<"4. Hapus data mahasiswa\n";
        cout<<"Pilihan: ";
        cin>>pil;
        cout<<"\n";
        switch (pil)
        {
        case 1:
            create();
            break;
        case 2:
            read();
            break;
        case 3:
            update();
            break;
        case 4:
            del();
            break;
        default:
            cout<<"\nPilihan anda tidak tersedia";
            return 0;
        }
    }
}