#ifndef TUBES-HEADER_H_INCLUDED
#define TUBES-HEADER_H_INCLUDED
#include "string"
#define first(L) L.first
#define info(L) L->info
#define next(L) L->next
#define relation(L) L->relation
#define nextPatient(L) L->nextPatient
using namespace std;

// ADDRESS
typedef struct doctorElement* doctorAddress;
typedef struct relation* relationAddress;
typedef struct patientElement* patientAddress;

// DOCTOR
struct doctor
{
    string str, name, speciality;
    int experiences_year;
};

struct doctorElement
{
    doctor info;
    doctorAddress next;
    relationAddress relation;
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

struct patientElement
{
    patient info;
    patientAddress next;
    relationAddress relation;
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
    char info;
    patientAddress nextPatient;
    relationAddress next;
};

relationAddress createRelation(char info);
void insertRelation(doctorList parent, string str, relationAddress P);
void showRelationFromParent(doctorAddress parent);

#endif // TUBES-HEADER_H_INCLUDED
