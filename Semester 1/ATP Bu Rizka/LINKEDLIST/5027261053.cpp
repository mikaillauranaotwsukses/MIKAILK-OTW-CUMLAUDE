
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nrp;
    string nama;
    Node* next;
};

// Membuat node baru
Node* buatNode(string nrp, string nama) {
    Node* mahasiswaBaru = new Node;

    mahasiswaBaru->nrp = nrp;
    mahasiswaBaru->nama = nama;
    mahasiswaBaru->next = nullptr;

    return mahasiswaBaru;
}

// 1. Insert at the beginning
void insertAwal(Node*& head, string nrp, string nama) {
    Node* mahasiswaBaru = buatNode(nrp, nama);

    mahasiswaBaru->next = head;
    head = mahasiswaBaru;
}

// 2. Insert at the end
void insertAkhir(Node*& head, string nrp, string nama) {
    Node* mahasiswaBaru = buatNode(nrp, nama);

    if (head == nullptr) {
        head = mahasiswaBaru;
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = mahasiswaBaru;
}

// 3. Insert at certain index
void saazzinsertIndex(Node*& head, string nrp, string nama, int index) {
    if (index < 0) {
        cout << "Index tidak valid!\n";
        return;
    }

    if (index == 0) {
        insertAwal(head, nrp, nama);
        return;
    }

    Node* current = head;

    for (int i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Index tidak valid!\n";
        return;
    }

    Node* mahasiswaBaru = buatNode(nrp, nama);

    mahasiswaBaru->next = current->next;
    current->next = mahasiswaBaru;
}

// 4. Delete at the beginning
void deleteAwal(Node*& head) {
    if (head == nullptr) {
        cout << "Linked list kosong!\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}

// 5. Delete at the end
void deleteAkhir(Node*& head) {
    if (head == nullptr) {
        cout << "Linked list kosong!\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;

    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

// 6. Delete at certain index
void deleteIndex(Node*& head, int index) {
    if (head == nullptr || index < 0) {
        cout << "Index tidak valid!\n";
        return;
    }

    if (index == 0) {
        deleteAwal(head);
        return;
    }

    Node* current = head;

    for (int i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Index tidak valid!\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;

    delete temp;
}

// Menampilkan seluruh mahasiswa
void tampilkan(Node* head) {
    Node* current = head;

    if (current == nullptr) {
        cout << "Linked list kosong!\n";
        return;
    }

    while (current != nullptr) {
        cout << "NRP  : " << current->nrp << endl;
        cout << "Nama : " << current->nama << endl;
        cout << "------------------\n";

        current = current->next;
    }
}

// Menghapus seluruh node sebelum program selesai
void hapusSemua(Node*& head) {
    while (head != nullptr) {
        deleteAwal(head);
    }
}

int main() {
    Node* head = nullptr;

    insertAwal(head, "101", "Mikail");
    insertAkhir(head, "102", "Ali");
    insertAkhir(head, "103", "Budi");

    cout << "Data awal:\n";
    tampilkan(head);

    insertIndex(head, "104", "Citra", 1);

    cout << "\nSetelah insert index 1:\n";
    tampilkan(head);

    deleteAwal(head);

    cout << "\nSetelah delete awal:\n";
    tampilkan(head);

    deleteAkhir(head);

    cout << "\nSetelah delete akhir:\n";
    tampilkan(head);

    deleteIndex(head, 0);

    cout << "\nSetelah delete index 0:\n";
    tampilkan(head);

    hapusSemua(head);

    return 0;
}
