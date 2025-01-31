#include <iostream> //dava trista argyatama
#include <iomanip> 
#include <string>
#include <fstream> 

using namespace std;

struct Menu {
    string nama;
    int harga;
};

void tampilkanMenuMakanan(Menu menu[], int jumlahMenu) {
    cout << "Daftar Menu Makanan:\n";
    for (int i = 0; i < jumlahMenu; i++) {
        cout << i + 1 << ". " << menu[i].nama << " - Rp." << menu[i].harga << endl;
    }
}

void tampilkanMenuMinuman(Menu menu[], int jumlahMenu) {
    cout << "\nDaftar Menu Minuman:\n";
    for (int i = 0; i < jumlahMenu; i++) {
        cout << i + 1 << ". " << menu[i].nama << " - Rp." << menu[i].harga << endl;
    }
}

int hitungTotal(int pesanan[], Menu menu[], int jumlahPesanan) {//dava trista argyatama
    int total = 0;
    for (int i = 0; i < jumlahPesanan; i++) {
        total += pesanan[i] * menu[i].harga;
    }
    return total;
}

void tampilkanStruk(Menu makanan[], int pesananMakanan[], int jumlahMakanan, //Aditra Fajar Sabri Dirta
                    Menu minuman[], int pesananMinuman[], int jumlahMinuman,
                    int totalBayar) {
    cout << "\n========================================\n";
    cout << "            STRUK PEMBAYARAN          \n";
    cout << "========================================\n";
    
    cout << left << setw(25) << "Nama Makanan" 
         << "| " << setw(6) << "Jumlah" 
         << "| " << setw(10) << "Harga" 
         << endl;
    cout << "----------------------------------------\n";
    
    for (int i = 0; i < jumlahMakanan; i++) {
        if (pesananMakanan[i] > 0) {
            cout << left << setw(25) << makanan[i].nama 
                 << "| " << setw(6) << pesananMakanan[i] 
                 << "| Rp." << setw(8) 
                 << (pesananMakanan[i] * makanan[i].harga) 
                 << endl;
        }
    }

    cout << "\n----------------------------------------\n";
    cout << left << setw(25) << "Nama Minuman" 
         << "| " << setw(6) << "Jumlah" 
         << "| " << setw(10) << "Harga" 
         << endl;
    cout << "----------------------------------------\n";
    
    for (int i = 0; i < jumlahMinuman; i++) {
        if (pesananMinuman[i] > 0) {
            cout << left << setw(25) << minuman[i].nama 
                 << "| " << setw(6) << pesananMinuman[i] 
                 << "| Rp." 
                 << setw(8) 
                 << (pesananMinuman[i] * minuman[i].harga) 
                 << endl;
        }
    }

    cout << "----------------------------------------\n";
    
    cout << right;
    cout << setw(25)  <<"Total Pembayaran: "
         <<"|       | Rp." 
         << totalBayar 
         <<" \n";

    cout<< "\n========================================\n";
    cout<< "     Terima Kasih & Selamat Makan!     \n";
    cout<< "========================================\n";
}

void simpanStrukKeFile(Menu makanan[], int pesananMakanan[], int jumlahMakanan,
                        Menu minuman[], int pesananMinuman[], int jumlahMinuman,
                        int totalBayar, const string& namaFile) {
    
    ofstream file("dava.txt"); 
    
    if (!file.is_open()) {
        cerr << "Error: Tidak dapat membuka file untuk ditulis.\n";
        return;
    }

    file << "========================================\n";
    file << "            STRUK PEMBAYARAN          \n";
    file << "========================================\n";

    file << left << setw(25) << "Nama Makanan" 
         << "| " << setw(6) <<"Jumlah" 
         <<"| "<<setw(10)<<"Harga" 
         <<" \n";
    
    file<< "----------------------------------------\n";

   for (int i = 0; i < jumlahMakanan; i++) {
       if (pesananMakanan[i] > 0) {
           file<< left<<setw(25)<<makanan[i].nama
               <<"| "<<setw(6)<<pesananMakanan[i]
               <<"| Rp."<<setw(8)
              <<(pesananMakanan[i]*makanan[i].harga)
               <<" \n";
       }
   }

  
   file<< "\n----------------------------------------\n";
   file<< left<<setw(25)<< "Nama Minuman"
       <<"| "<<setw(6)<< "Jumlah"
       <<"| "<<setw(10)<< "Harga"
       <<" \n";

   file<< "----------------------------------------\n";

   for (int i = 0; i < jumlahMinuman; i++) {
       if (pesananMinuman[i] > 0) {
           file<< left<<setw(25)<<minuman[i].nama
               <<"| "<<setw(6)<<pesananMinuman[i]
               <<"| Rp."
               <<" "<<setw(8)
              <<(pesananMinuman[i]*minuman[i].harga)
               <<" \n";
       }
   }

   
   file<< "----------------------------------------\n";

  
   file<< right;
   file<< setw(25)<<"Total Pembayaran: "
       <<"|          | Rp."
       <<totalBayar
       <<" \n";


   file<< "\n========================================\n";
   file<< "     Terima Kasih & Selamat Makan!     \n";
   file<< "========================================\n";

   file.close(); 

   cout<<"Struk telah disimpan ke dalam "<< namaFile<<".\n"; //Aditra Fajar Sabri Dirta
}

int main() { //Bima ghiramustika putra
    const int MAX_MAKANAN = 5;
    const int MAX_MINUMAN = 3;

   
    Menu makanan[MAX_MAKANAN] = {
        {"Nasi Putih", 5000},
        {"Ayam Goreng", 11000},
        {"Lele Goreng", 10000},
        {"Nila Goreng", 13000},
        {"Bebek Goreng", 18000}
    };

    
    Menu minuman[MAX_MINUMAN] = {
        {"Es Teh", 3000},
        {"Es Jeruk", 5000},
        {"Teh Tawar", 2500}
    };

   int pesananMakanan[MAX_MAKANAN] = {0}; 
   int pesananMinuman[MAX_MINUMAN] = {0}; 

   int jumlahPesananMakanan = 0;
   int jumlahPesananMinuman = 0;

  
   tampilkanMenuMakanan(makanan, MAX_MAKANAN);

   
   cout<< "\nMasukkan jumlah jenis makanan yang ingin dipesan (maksimal "
       << MAX_MAKANAN<< "): ";
   cin >> jumlahPesananMakanan;

   for (int i = 0; i < jumlahPesananMakanan; i++) {
       int pilihan;
       cout<< "Pilih menu makanan ke-"<< (i + 1)<< ": ";
       cin >> pilihan;

       if (pilihan > 0 && pilihan <= MAX_MAKANAN) {
           cout<< "Jumlah pesanan untuk "
               <<" "<< makanan[pilihan - 1].nama 
               <<" : ";
           cin >> pesananMakanan[pilihan - 1];
       } else {
           cout<< "Pilihan tidak valid.\n";
           i--; 
       }
   }

   
   tampilkanMenuMinuman(minuman, MAX_MINUMAN);

   
   cout<< "\nMasukkan jumlah jenis minuman yang ingin dipesan (maksimal "
       << MAX_MINUMAN<< "): ";
   cin >> jumlahPesananMinuman;

   for (int i = 0; i < jumlahPesananMinuman; i++) {
       int pilihan;
       cout<< "Pilih menu minuman ke-" 
           <<" "<< (i + 1)
           <<" : ";
       cin >> pilihan;

       if (pilihan > 0 && pilihan <= MAX_MINUMAN) {
           cout<< "Jumlah pesanan untuk "
               <<" "<< minuman[pilihan - 1].nama 
               <<" : ";
           cin >> pesananMinuman[pilihan - 1];
       } else {
           cout<< "Pilihan tidak valid.\n";
           i--; 
       }
   }

   
   int totalBayar = hitungTotal(pesananMakanan, makanan, MAX_MAKANAN)
                     + hitungTotal(pesananMinuman, minuman, MAX_MINUMAN);
    
  
   tampilkanStruk(makanan, pesananMakanan, MAX_MAKANAN,
                   minuman, pesananMinuman, MAX_MINUMAN,
                   totalBayar);

  
   simpanStrukKeFile(makanan, pesananMakanan, MAX_MAKANAN,
                      minuman, pesananMinuman, MAX_MINUMAN,
                      totalBayar, "dava1.txt");

   return 0;
} //Bima ghiramustika putra

