#include <iostream>
#include "tubes-header.h"

// DOCTOR
void createListDoctor(doctorList &DL)
{
    first(DL) = NULL;
}

doctorAddress createDoctor(doctor d)
{
    doctorElement* el = new doctorElement;
    info(el) = d;
    next(el) = NULL;
    relation(el) = NULL;
    return el;
}

void insertDoctor(doctorList &DL, doctorAddress P)
{
    if (first(DL) == NULL)
    {
        first(DL) = P;
    }
    else
    {
        doctorAddress p = first(DL);
        while (next(p) != NULL)
        {
            p = next(p);
        }
        next(p) = P;
    }

}

doctorAddress findDoctor(doctorList DL, string str)
{
    doctorAddress p = first(DL);
    while (p != NULL)
    {
        doctor d = info(p);

        if (d.str == str)
        {
            return p;
        }
        p = next(p);
    }

    return NULL;
}

void deleteDoctor(doctorList &DL, doctorAddress P)
{
    if (first(DL) != NULL)
    {
        if (P == first(DL)) // delete first
        {
            doctorDeleteFirst(DL, P);
        }
        else if (next(P) == NULL) // delete last
        {
            doctorDeleteLast(DL, P);
        }
        else // delete after
        {
            doctorAddress prec = P;
            doctorDeleteAfter(DL, prec, P);
        }
    }

}

void doctorDeleteFirst(doctorList &L, doctorAddress P)
{
    if (first(L) != NULL)
    {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
    else
    {
        P = NULL;
    }
}

void doctorDeleteLast(doctorList &L, doctorAddress P)
{
    if (first(L) != NULL)
    {
        if (next(first(L)) == NULL)
        {
            P = first(L);
            first(L) = NULL;
        }
        else
        {
            doctorAddress temp = first(L);
            while (next(next(temp)) != NULL)
            {
                temp = next(temp);
            }
            P = next(temp);
            next(temp) = NULL;
        }
    }
}

void doctorDeleteAfter(doctorList &L, doctorAddress prec, doctorAddress P)
{
    doctorAddress temp;

    P = first(L);
    while (P != NULL)
    {
        if (next(P) == prec)
        {
            temp = P;
            break;
        }
        P = next(P);
    }

    next(temp) = next(prec);
    prec = NULL;
}

void showDoctorList(doctorList DL)
{
    doctorAddress p = first(DL);
    while (p != NULL)
    {
        doctor d = info(p);
        cout << d.str << " " << d.name << " " << d.speciality << " " << d.experiences_year << endl;
        p = next(p);
    }
}

// PATIENT
void createListPatient(patientList &PL)
{
    first(PL) = NULL;
}

patientAddress createPatient(patient p)
{
    patientElement* el = new patientElement;
    info(el) = p;
    next(el) = NULL;
    return el;
}

void insertPatient(patientList &PL, patientAddress P)
{
    if (first(PL) == NULL)
    {
        first(PL) = P;
    }
    else
    {
        patientAddress pa = first(PL);
        while (next(pa) != NULL)
        {
            pa = next(pa);
        }
        next(pa) = P;
    }
}

patientAddress findPatient(patientList PL, string nik)
{
    patientAddress p = first(PL);
    while (p != NULL)
    {
        patient pp = info(p);

        if (pp.nik == nik)
        {
            return p;
        }
        p = next(p);
    }

    return NULL;
}

void deletePatient(patientList &PL, patientAddress P)
{
    if (first(PL) != NULL)
    {
        if (P == first(PL)) // delete first
        {
            patientDeleteFirst(PL, P);
        }
        else if (next(P) == NULL) // delete last
        {
            patientDeleteLast(PL, P);
        }
        else // delete after
        {
            patientAddress prec = P;
            patientDeleteAfter(PL, prec, P);
        }
    }
}

void patientDeleteFirst(patientList &L, patientAddress P)
{
    if (first(L) != NULL)
    {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
    else
    {
        P = NULL;
    }
}

void patientDeleteLast(patientList &L, patientAddress P)
{
    if (first(L) != NULL)
    {
        if (next(first(L)) == NULL)
        {
            P = first(L);
            first(L) = NULL;
        }
        else
        {
            patientAddress temp = first(L);
            while (next(next(temp)) != NULL)
            {
                temp = next(temp);
            }
            P = next(temp);
            next(temp) = NULL;
        }
    }
}

void patientDeleteAfter(patientList &L, patientAddress prec, patientAddress P)
{
    patientAddress temp;

    P = first(L);
    while (P != NULL)
    {
        if (next(P) == prec)
        {
            temp = P;
            break;
        }
        P = next(P);
    }

    next(temp) = next(prec);
    prec = NULL;
}

void showPatientList(patientList PL)
{
    patientAddress p = first(PL);
    while (p != NULL)
    {
        patient pp = info(p);
        cout << pp.nik << " " << pp.name << " " << pp.age << " " << pp.gender << endl;
        p = next(p);
    }
}

// RELATION
relationAddress createRelation(char info)
{
    relationAddress r = new relation;
    info(r) = info;
    next(r) = NULL;
    nextPatient(r) = NULL;

    return r;
}

void insertRelation(doctorList parent, string str, relationAddress P)
{
    doctorAddress da = findDoctor(parent, str);

    if (da != NULL)
    {
        relationAddress ra = relation(da);

        if (ra == NULL)
        {
            relation(da) = P;
        }
        else
        {
            while (next(ra) != NULL)
            {
                ra = next(ra);
            }
            next(ra) = P;
            nextPatient(ra) = NULL;
        }
    }
}

void showRelationFromParent(doctorAddress parent)
{
    relationAddress p = relation(parent);
    while (p != NULL)
    {
        cout << info(p) << endl;
        p = next(p);
    }
}
