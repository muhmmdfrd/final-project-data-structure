#ifndef TUBES-HEADER_H_INCLUDED
#define TUBES-HEADER_H_INCLUDED
#include "string"
#define first(L) L.first
#define info(L) L->info
#define next(L) L->next

using namespace std;

// DOCTOR
struct doctor
{
    string str, name, speciality;
    int experiences_year;
};

typedef struct doctorElement* doctorAddress;

struct doctorElement
{
    doctor info;
    doctorAddress next;
};

struct doctorList
{
    doctorAddress first;
};

void createListDoctor(doctorList &DL);
doctorAddress createDoctor(doctor d);
void insertDoctor(doctorList &DL, doctorAddress P);
doctorAddress findDoctor(doctorList DL, string str);
void deleteDoctor(doctorList &DL, doctorAddress P);
void showDoctorList(doctorList DL);
void doctorDeleteFirst(doctorList &L, doctorAddress P);
void doctorDeleteLast(doctorList &L, doctorAddress P);
void doctorDeleteAfter(doctorList &L, doctorAddress prec, doctorAddress P);

// PATIENT
struct patient
{
    string nik, name;
    char gender;
    int age;
};

typedef struct patientElement* patientAddress;

struct patientElement
{
    patient info;
    patientAddress next;
};

struct patientList
{
    patientAddress first;
};

void createListPatient(patientList &PL);
patientAddress createPatient(patient p);
void insertPatient(patientList &PL, patientAddress P);
patientAddress findPatient(patientList PL, string nik);
void deletePatient(patientList &PL, patientAddress P);
void showPatientList(patientList PL);
void patientDeleteFirst(patientList &L, patientAddress P);
void patientDeleteLast(patientList &L, patientAddress P);
void patientDeleteAfter(patientList &L, patientAddress prec, patientAddress P);

// RELATION
struct relation
{
    doctorAddress nextDoctor;
    patientAddress nextPatient;
};

#endif // TUBES-HEADER_H_INCLUDED
