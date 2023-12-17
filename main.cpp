#include <iostream>
#include "tubes-header.h"
using namespace std;

int main()
{
    doctorList DL;
    createListDoctor(DL);

    doctor d1 = doctor();
    d1.name = "doctor 1";
    d1.str = "str-01";
    d1.speciality = "dentist";
    d1.experiences_year = 10;
    doctorAddress cd1 = createDoctor(d1);
    insertDoctor(DL, cd1);

    doctor d2 = doctor();
    d2.name = "doctor 2";
    d2.str = "str-02";
    d2.speciality = "fisio";
    d2.experiences_year = 5;
    insertDoctor(DL, createDoctor(d2));

    doctor d3 = doctor();
    d3.name = "doctor 3";
    d3.str = "str-03";
    d3.speciality = "bones";
    d3.experiences_year = 3;
    insertDoctor(DL, createDoctor(d3));

    doctor d4 = doctor();
    d4.name = "doctor 4";
    d4.str = "str-04";
    d4.speciality = "general";
    d4.experiences_year = 2;
    insertDoctor(DL, createDoctor(d4));

    showDoctorList(DL);

    doctorAddress da1 = findDoctor(DL, "str-02");

    if (da1 == NULL)
    {
        cout << "str-02 not found" << endl;
    }
    else
    {
        deleteDoctor(DL, da1);
    }

    cout << endl;
    cout << "after delete str-02:" << endl;
    showDoctorList(DL);

    cout << endl;

    patientList PL;
    createListPatient(PL);

    patient p1 = patient();
    p1.nik = "nik-01";
    p1.name = "patient 01";
    p1.gender = 'L';
    p1.age = 21;
    insertPatient(PL, createPatient(p1));

    patient p2 = patient();
    p2.nik = "nik-02";
    p2.name = "patient 02";
    p2.gender = 'P';
    p2.age = 31;
    insertPatient(PL, createPatient(p2));

    patient p3 = patient();
    p3.nik = "nik-03";
    p3.name = "patient 03";
    p3.gender = 'L';
    p3.age = 18;
    insertPatient(PL, createPatient(p3));

    showPatientList(PL);

    patientAddress pa1 = findPatient(PL, "nik-02");

    if (pa1 == NULL)
    {
        cout << "nik-02 not found" << endl;
    }
    else
    {
        deletePatient(PL, pa1);
    }

    cout << endl;
    cout << "after delete nik-02:" << endl;
    showPatientList(PL);

    // insert relation
    insertRelation(DL, "str-01", createRelation('A'));
    insertRelation(DL, "str-01", createRelation('B'));
    insertRelation(DL, "str-01", createRelation('C'));

    doctor parent_1 = info(cd1);
    cout << "relasi dari dokter dengan nama " << parent_1.name << ": " << endl;
    showRelationFromParent(cd1);
}
