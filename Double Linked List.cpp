// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program Daftar Mahasiswa With Double Linked List

#include <iostream>
using namespace std;

struct TanggalLahir
{
  int tanggal, bulan, tahun;
};

struct Mahasiswa
{
  string nim, nama, tempatlhr;
  TanggalLahir tgl_lahir;

  Mahasiswa *prev;
  Mahasiswa *next;
};

Mahasiswa *head, *tail, *cur, *newNode, *del, *afterNode;

// Buat Data Awal Double Linked List
void createDoubleLinkedList(Mahasiswa mhs)
{
  head = new Mahasiswa();
  head->nim = mhs.nim;
  head->nama = mhs.nama;
  head->tempatlhr = mhs.tempatlhr;
  head->tgl_lahir.tanggal = mhs.tgl_lahir.tanggal;
  head->tgl_lahir.bulan = mhs.tgl_lahir.bulan;
  head->tgl_lahir.tahun = mhs.tgl_lahir.tahun;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

// Jumlah Double Linked List
int countDoubleLinkedList()
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {
    cur = head;
    int jumlah = 0;
    while (cur != NULL)
    {
      jumlah++;
      // step
      cur = cur->next;
    }
    return jumlah;
  }
}

// Tambah Depan
void addFirst(Mahasiswa mhs)
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {
    newNode = new Mahasiswa();
    newNode->nim = mhs.nim;
    newNode->nama = mhs.nama;
    newNode->tempatlhr = mhs.tempatlhr;
    newNode->tgl_lahir.tanggal = mhs.tgl_lahir.tanggal;
    newNode->tgl_lahir.bulan = mhs.tgl_lahir.bulan;
    newNode->tgl_lahir.tahun = mhs.tgl_lahir.tahun;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

// Tambah Tengah
void addMiddle(Mahasiswa mhs, int posisi)
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {

    if (posisi == 1)
    {
      cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
    }
    else if (posisi < 1 || posisi > countDoubleLinkedList())
    {
      cout << "Posisi diluar jangkauan!!!" << endl;
    }
    else
    {
      newNode = new Mahasiswa();
      newNode->nim = mhs.nim;
      newNode->nama = mhs.nama;
      newNode->tempatlhr = mhs.tempatlhr;
      newNode->tgl_lahir.tanggal = mhs.tgl_lahir.tanggal;
      newNode->tgl_lahir.bulan = mhs.tgl_lahir.bulan;
      newNode->tgl_lahir.tahun = mhs.tgl_lahir.tahun;

      // traversing
      cur = head;
      int nomor = 1;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }

      afterNode = cur->next;
      newNode->prev = cur;
      newNode->next = afterNode;
      cur->next = newNode;
      afterNode->prev = newNode;
    }
  }
}

// Tambah Belakang
void addLast(Mahasiswa mhs)
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {
    newNode = new Mahasiswa();
    newNode->nim = mhs.nim;
    newNode->nama = mhs.nama;
    newNode->tempatlhr = mhs.tempatlhr;
    newNode->tgl_lahir.tanggal = mhs.tgl_lahir.tanggal;
    newNode->tgl_lahir.bulan = mhs.tgl_lahir.bulan;
    newNode->tgl_lahir.tahun = mhs.tgl_lahir.tahun;
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
}

// Hapus Data Depan
void removeFirst()
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {
    del = head;
    head = head->next;
    if (head != NULL)
    {
      head->prev = NULL;
    }
    delete del;
  }
}

// Hapus Data Tengah
void removeMiddle(int posisi)
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {
    if (posisi == 1 || posisi == countDoubleLinkedList())
    {
      cout << "Posisi bukan posisi tengah!!" << endl;
    }
    else if (posisi < 1 || posisi > countDoubleLinkedList())
    {
      cout << "Posisi diluar jangkauan!!" << endl;
    }
    else
    {
      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      del = cur->next;
      afterNode = del->next;
      cur->next = afterNode;
      afterNode->prev = cur;
      delete del;
    }
  }
}

// Hapus Data Belakang
void removeLast()
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {
    del = tail;
    tail = tail->prev;
    if (tail != NULL)
    {
      tail->next = NULL;
    }
    else
    {
      head = NULL;
    }
    delete del;
  }
}

// Print Double Linked List
void printDoubleLinkedList()
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {
    int count = 1;
    cur = head;
    while (cur != NULL)
    {
      // print
      cout << "Data Mahasiswa Ke-" << count << endl;
      cout << "Nim\t\t\t\t: " << cur->nim << endl;
      cout << "Nama\t\t\t: " << cur->nama << endl;
      cout << "Tempat Lahir\t: " << cur->tempatlhr << endl;
      cout << "Tanggal Lahir\t: " << cur->tgl_lahir.tanggal << "/" << cur->tgl_lahir.bulan << "/" << cur->tgl_lahir.tahun << endl;

      // step
      cur = cur->next;
      count++;
    }
  }
}

int main()
{

  Mahasiswa mhs;
  int pilih, pilih2, pilih3;

  do
  {
    cout << "===================================" << endl;
    cout << "\t\tMenu Data Mahasiswa" << endl;
    cout << "===================================" << endl;
    cout << "1. Buat Data Mahasiswa" << endl;
    cout << "2. Tambah Data Mahasiswa" << endl;
    cout << "3. Hapus Data Mahasiswa" << endl;
    cout << "4. Tampilkan Data Mahasiswa" << endl;
    cout << "5. Keluar dari Menu" << endl;
    cout << "===================================" << endl;
    cout << "Pilih Menu: ";
    cin >> pilih;

    if (pilih == 1)
    {
      cout << "===================================" << endl;
      cout << "Masukkan Nim Anda: ";
      cin.ignore();
      getline(cin, mhs.nim);
      cout << "Masukkan Nama Anda: ";
      getline(cin, mhs.nama);
      cout << "Tempat Lahir: ";
      getline(cin, mhs.tempatlhr);
      cout << "Tanggal Lahir: (DD/MM/YYYY)" << endl;
      cout << "Tanggal: ";
      cin >> mhs.tgl_lahir.tanggal;
      cout << "Bulan: ";
      cin >> mhs.tgl_lahir.bulan;
      cout << "Tahun: ";
      cin >> mhs.tgl_lahir.tahun;

      createDoubleLinkedList(mhs);
    }
    else if (pilih == 2)
    {
      cout << "1. Tambah Data Depan" << endl;
      cout << "2. Tambah Data Tengah" << endl;
      cout << "3. Tambah Data Belakang" << endl;
      cout << "===================================" << endl;
      cout << "Pilih Menu Tambah: ";
      cin >> pilih2;

      if (pilih2 == 1)
      {
        cout << "===================================" << endl;
        cout << "Masukkan Nim Anda: ";
        cin.ignore();
        getline(cin, mhs.nim);
        cout << "Masukkan Nama Anda: ";
        getline(cin, mhs.nama);
        cout << "Tempat Lahir: ";
        getline(cin, mhs.tempatlhr);
        cout << "Tanggal Lahir: (DD/MM/YYYY)" << endl;
        cout << "Tanggal: ";
        cin >> mhs.tgl_lahir.tanggal;
        cout << "Bulan: ";
        cin >> mhs.tgl_lahir.bulan;
        cout << "Tahun: ";
        cin >> mhs.tgl_lahir.tahun;

        addFirst(mhs);
      }
      else if (pilih2 == 2)
      {
        int posisi;

        cout << "===================================" << endl;
        cout << "Masukkan Nim Anda: ";
        cin.ignore();
        getline(cin, mhs.nim);
        cout << "Masukkan Nama Anda: ";
        getline(cin, mhs.nama);
        cout << "Tempat Lahir: ";
        getline(cin, mhs.tempatlhr);
        cout << "Tanggal Lahir: (DD/MM/YYYY)" << endl;
        cout << "Tanggal: ";
        cin >> mhs.tgl_lahir.tanggal;
        cout << "Bulan: ";
        cin >> mhs.tgl_lahir.bulan;
        cout << "Tahun: ";
        cin >> mhs.tgl_lahir.tahun;
        cout << "===================================" << endl;
        cout << "Attention: " << endl
             << "Disaranakan tidak input posisi data yang kurang/sama dari posisi 1 atau lebih dari jumlah data yang ada!!!" << endl;
        cout << "===================================" << endl;
        cout << "Masukkan Data Posisi Tengah Yang Ingin Ditambahkan: ";
        cin >> posisi;

        addMiddle(mhs, posisi);
      }
      else if (pilih2 == 3)
      {
        cout << "===================================" << endl;
        cout << "Masukkan Nim Anda: ";
        cin.ignore();
        getline(cin, mhs.nim);
        cout << "Masukkan Nama Anda: ";
        getline(cin, mhs.nama);
        cout << "Tempat Lahir: ";
        getline(cin, mhs.tempatlhr);
        cout << "Tanggal Lahir: (DD/MM/YYYY)" << endl;
        cout << "Tanggal: ";
        cin >> mhs.tgl_lahir.tanggal;
        cout << "Bulan: ";
        cin >> mhs.tgl_lahir.bulan;
        cout << "Tahun: ";
        cin >> mhs.tgl_lahir.tahun;

        addLast(mhs);
      }
    }
    else if (pilih == 3)
    {
      cout << "1. Hapus Data Depan" << endl;
      cout << "2. Hapus Data Tengah" << endl;
      cout << "3. Hapus Data Belakang" << endl;
      cout << "===================================" << endl;
      cout << "Pilih Menu Hapus: ";
      cin >> pilih3;

      if (pilih3 == 1)
      {
        removeFirst();
      }
      else if (pilih3 == 2)
      {
        int posisi;

        cout << "Attention: " << endl
             << "Disaranakan tidak input posisi data yang kurang/sama dari posisi 1 atau lebih/sama dari jumlah data yang ada!!! " << endl;
        cout << "===================================" << endl;
        cout << " Masukkan Data Posisi Tengah Yang Ingin Dihapus: ";
        cin >> posisi;

        removeMiddle(posisi);
      }
      else if (pilih3 == 3)
      {
        removeLast();
      }
    }
    else if (pilih == 4)
    {
      printDoubleLinkedList();
    }
    else if (pilih == 5)
    {
      cout << "Keluar Dari Menu...";
    }
    else
    {
      cout << "Maaf Pilihan Anda Belum Tersedia";
    }
    cout << endl
         << endl;
  } while (pilih != 5);

  return 0;
}