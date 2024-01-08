#include <iostream>
#include "tubes-header.h"
using namespace std;

int main()
{
    doctorList DL;
    createListDoctor(DL);

    int n;
    string find_str, find_nik;

    cout << "Masukkan jumlah dokter yang akan diinput: "; cin >> n;

    for (int i = 0; i < n; i++)
    {
        // ini ntar hapus
        doctor d = doctor();
        d.str = "str-0" + to_string(i + 1);
        d.name = "D" + to_string(i + 1);
        d.speciality = "A";
        d.experiences_year = 10 + i;
        insertDoctor(DL, createDoctor(d));
        // ntar un-comment
//        doctor d = doctor();
//        cout << "STR: "; cin >> d.str;
//        cout << "Nama: "; cin >> d.name;
//        cout << "Spesialisasi: "; cin >> d.speciality;
//        cout << "Pengalaman (tahun): "; cin >> d.experiences_year;
//        cout << endl;
//        insertDoctor(DL, createDoctor(d));
    }

    cout << "List dokter yang tersedia: " << endl;
    showDoctorList(DL);
    cout << endl;

    cout << "Cari dokter berdasarkan STR: "; cin >> find_str;
    doctorAddress da = findDoctor(DL, find_str);

    if (da == NULL)
    {
        cout << find_str << " tidak ditemukan." << endl;
    }
    else
    {
        cout << find_str << " ditemukan." << endl;
    }
    cout << endl;

    cout << "Cari dokter yang akan dihapus berdasarkan STR: "; cin >> find_str;
    da = findDoctor(DL, find_str);

    if (da == NULL)
    {
        cout << find_str << " tidak ditemukan." << endl;
    }
    else
    {
        deleteDoctor(DL, da);
        cout << find_str << " berhasil dihapus." << endl;
    }
    cout << endl;

    cout << "List dokter yang tersedia: " << endl;
    showDoctorList(DL);
    cout << endl;

    patientList PL;
    createListPatient(PL);

    cout << "Masukkan jumlah pasien yang akan diinput: "; cin >> n;

    for (int i = 0; i < n; i++)
    {
        // ini juga ntar hapus
        patient p = patient();
        p.nik = "nik-0" + to_string(i + 1);
        p.name = "M" + to_string(i + 1);
        p.gender = 'L';
        p.age = 20 + i;
        insertPatient(PL, createPatient(p));
//        patient p = patient();
//        cout << "NIK: "; cin >> p.nik;
//        cout << "Name: "; cin >> p.name;
//        cout << "Gender: "; cin >> p.gender;
//        cout << "Umur: "; cin >> p.age;
//        cout << endl;
//        insertPatient(PL, createPatient(p));
    }

    cout << "List pasien yang terdaftar: " << endl;
    showPatientList(PL);
    cout << endl;

    cout << "Cari pasien berdasarkan NIK: "; cin >> find_nik;
    patientAddress pa = findPatient(PL, find_nik);

    if (pa == NULL)
    {
        cout << find_nik << " tidak ditemukan." << endl;
    }
    else
    {
        cout << find_nik << " ditemukan." << endl;
    }
    cout << endl;

    cout << "Cari pasien yang akan dihapus berdasarkan NIK: "; cin >> find_nik;
    pa = findPatient(PL, find_nik);

    if (pa == NULL)
    {
        cout << find_nik << " tidak ditemukan." << endl;
    }
    else
    {
        deletePatient(PL, pa);
        cout << find_nik << " berhasil dihapus." << endl;
    }
    cout << endl;

    cout << "List pasien yang terdaftar: " << endl;
    showPatientList(PL);
    cout << endl;

    da = first(DL);
    int m = 0;
    int ascii = 65;
    while (da != NULL)
    {
        cout << "Masukkan jumlah relasi untuk dokter " << info(da).name << ": ";
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            insertRelation(DL, info(da).str, createRelation(ascii));
            ascii++;
        }

        da = next(da);
    }
    cout << endl;

    da = first(DL);
    while (da != NULL)
    {
        cout << "relasi dari dokter dengan nama " << info(da).name << ": " << endl;
        showRelationFromParent(da);
        cout << endl;
        da = next(da);
    }

    da = first(DL);
    int relation_count = 0;
    while (da != NULL)
    {
        relation_count = countRelationByParent(DL, info(da).str);
        int i = 0;
        while (i < relation_count)
        {
            cout << "masukkan " << countRelationByParent(DL, info(da).str) << " NIK pasien untuk dokter " << info(da).name << " : ";
            cin >> find_nik;

            pa = findPatient(PL, find_nik);

            if (pa == NULL)
            {
                cout << find_nik << " tidak ditemukan. Silakan coba lagi" << endl;
            }
            else
            {
                connectToPatient(DL, info(da).str, PL, info(pa).nik);
                i++;
            }
        }
        cout << endl;

        da = next(da);
    }

    da = first(DL);
    while (da != NULL)
    {
        cout << "dokter " << info(da).name << " memiliki pasien: " << endl;
        showPatientFromDoctor(DL, info(da).str);
        cout << endl;
        da = next(da);
    }

    showDoctorByPatient(DL, PL);

    cout << endl;

    cout << "Mencari relasi pasien dan dokter" << endl;
    cout << "Masukkan STR: "; cin >> find_str;
    cout << "Masukkan NIK: "; cin >> find_nik;

    relationAddress relation_dp = findRelation(DL, find_str, PL, find_nik);

    if (relation_dp == NULL)
    {
        cout << "Tidak ada relasi antara STR " << find_str << " dengan NIK " << find_nik << endl;
    }
    else
    {
        patientAddress pa = nextPatient(relation_dp);
        showDoctorByPatient(DL, PL, info(pa).nik);
    }

    cout << endl;
    showCountRelationAllParent(DL);

    pa = first(PL);
    while (pa != NULL)
    {
        cout << "Jumlah relasi pasien dengan NIK " << info(pa).nik << " adalah " << countRelationByChild(DL, PL, info(pa).nik) << endl;
        pa = next(pa);
    }
    cout << endl;

    cout << "Jumlah pasien tanpa relasi: " << countChildHaveNotRelationship(PL, DL) << endl;


////    cout << "jumlah relasi child nik-01: " << countRelationByChild(DL, PL, "nik-01") << endl;
//
//
//
//    showDoctorByPatient(DL, PL);
//
//    cout << "divider" << endl;
//
//    showDoctorByPatient(DL, PL, "nik-02");
//
//    relationAddress rara = findRelation(DL, "str-01", PL, "nik-02");
//
//    cout << info(rara) << endl;
//
//    deleteRelation(DL, "str-01", PL, "nik-02");
//
//    doctor parent_11 = info(cd1);
//    cout << "relasi dari dokter dengan nama " << parent_11.name << ": " << endl;
//
//    cout << "before: " << endl;
//    showDoctorByPatient(DL, PL);
//    cout << endl;
//
//    changeRelationToPatient(DL, "str-04", PL, "nik-04", "nik-02");
//
//    cout << "after: " << endl;
//    showDoctorByPatient(DL, PL);
}

