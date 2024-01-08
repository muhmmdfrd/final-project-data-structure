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

void deleteDoctor(doctorList &DL, doctorAddress &P)
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
        P = NULL;
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

void deletePatient(patientList &PL, patientAddress &P)
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
        P = NULL;
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

void showDoctorByPatient(doctorList DL, patientList PL)
{
    bool patientOfThisDoctor = false;
    patientAddress p = first(PL);

    while (p != NULL)
    {
        doctorAddress d = first(DL);

        cout << "Pasien " << info(p).name << " dirawat oleh dokter:" << endl;
        while (d != NULL)
        {
            patientOfThisDoctor = false;
            relationAddress r = relation(d);

            while (r != NULL)
            {
                if (nextPatient(r) == p)
                {
                    patientOfThisDoctor = true;
                }
                r = next(r);
            }

            if (patientOfThisDoctor)
            {
                cout << info(d).str << " " << info(d).name << " " << info(d).speciality << " " << info(d).experiences_year << endl;
            }

            d = next(d);
        }

        cout << endl;

        p = next(p);
    }
}

void showDoctorByPatient(doctorList DL, patientList PL, string nik)
{
    bool patientOfThisDoctor = false;

    patientAddress p = findPatient(PL, nik);

    if (p == NULL)
    {
        return;
    }

    doctorAddress d = first(DL);
    cout << "Pasien " << info(p).name << " dirawat oleh: " << endl;
    while (d != NULL)
    {
        patientOfThisDoctor = false;
        relationAddress r = relation(d);

        while (r != NULL)
        {
            if (nextPatient(r) == p)
            {
                patientOfThisDoctor = true;
            }
            r = next(r);
        }

        if (patientOfThisDoctor)
        {
            cout << info(d).str << " " << info(d).name << " " << info(d).speciality << " " << info(d).experiences_year << endl;
        }

        d = next(d);
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
    if (parent != NULL)
    {
        relationAddress p = relation(parent);
        while (p != NULL)
        {
            cout << info(p) << endl;
            p = next(p);
        }
    }
}

void connectToPatient(doctorList parent, string str, patientList child, string nik)
{
    doctorAddress da = findDoctor(parent, str);
    patientAddress pa = findPatient(child, nik);

    if (da != NULL && pa != NULL)
    {
        relationAddress ra = relation(da);

        if (ra == NULL)
        {
            cout << "Relasi tidak ditemukan." << endl;
        }
        else
        {
            bool is_found = false;
            while (ra != NULL && !is_found)
            {
                if (nextPatient(ra) == NULL)
                {
                    nextPatient(ra) = pa;
                    is_found = true;
                }
                ra = next(ra);
            }
        }
    }
}

void showPatientFromDoctor(doctorList DL, string str)
{
    doctorAddress doc = findDoctor(DL, str);

    if (doc != NULL)
    {
        relationAddress p = relation(doc);
        while (p != NULL)
        {
            patientAddress temp = nextPatient(p);

            if (temp != NULL)
            {
                patient data = info(temp);
                cout << data.nik << " " << data.name << " " << data.gender << " " << data.age << endl;
            }
            p = next(p);
        }
    }
}

relationAddress findRelation(doctorList parent, string str, patientList child, string nik)
{
    doctorAddress da = findDoctor(parent, str);
    patientAddress pa = findPatient(child, nik);

    if (da != NULL && pa != NULL)
    {
        relationAddress p = relation(da);
        while (p != NULL)
        {
            if (nextPatient(p) != NULL && nextPatient(p) == pa)
            {
                return p;
            }
            p = next(p);
        }
    }
    else
    {
        return NULL;
    }

    return NULL;
}

void deleteRelation(doctorList parent, string str, patientList child, string nik)
{
    doctorAddress d = first(parent);
    relationAddress P = findRelation(parent, str, child, nik);

    if (P != NULL)
    {
        if (P == relation(d)) // delete first
        {
            relationDeleteFirst(parent, P);
        }
        else if (next(P) == NULL) // delete last
        {
            relationDeleteLast(parent, P);
        }
        else // delete after
        {
            relationAddress prec = P;
            relationDeleteAfter(parent, prec, P);
        }
        P = NULL;
    }
}

int countRelationByParent(doctorList DL, string str)
{
    int counter = 0;

    doctorAddress parent = findDoctor(DL, str);
    if (parent != NULL)
    {
        relationAddress p = relation(parent);
        while (p != NULL)
        {
            counter++;
            p = next(p);
        }
    }

    return counter;
}

void showCountRelationAllParent(doctorList DL)
{
    doctorAddress p = first(DL);
    while (p != NULL)
    {
        doctor d = info(p);
        int counter = countRelationByParent(DL, d.str);
        cout << d.str << " " << d.name << " " << d.speciality << " " << d.experiences_year << " mempunyai relasi sebanyak " << counter << endl;
        p = next(p);
    }
}

int countRelationByChild(doctorList DL, patientList PL, string nik)
{
    doctorAddress p = first(DL);
    patientAddress pa = findPatient(PL, nik);
    int counter = 0;

    if (pa != NULL)
    {
        while (p != NULL)
        {
            relationAddress ra = relation(p);

            while (ra != NULL)
            {
                if (nextPatient(ra) == pa)
                {
                    counter++;
                }

                ra = next(ra);
            }
            p = next(p);
        }
    }

    return counter;
}

int countChildHaveNotRelationship(patientList PL, doctorList DL)
{
    int counter = 0;
    bool childHasRelation = false;
    patientAddress p = first(PL);

    while (p != NULL)
    {
        childHasRelation = false;
        doctorAddress d = first(DL);

        while (d != NULL)
        {
            relationAddress r = relation(d);

            while (r != NULL)
            {
                if (nextPatient(r) == p)
                {
                    childHasRelation = true;
                }
                r = next(r);
            }
            d = next(d);
        }

        if (childHasRelation == false)
        {
            counter++;
        }

        p = next(p);
    }

    return counter;
}

void relationDeleteFirst(doctorList DL, relationAddress P)
{
    doctorAddress d = first(DL);

    if (d != NULL)
    {
        P = relation(d);
        relation(d) = next(P);
        next(P) = NULL;
    }
    else
    {
        P = NULL;
        relation(d) = NULL;
    }
}

void relationDeleteLast(doctorList DL, relationAddress P)
{
    doctorAddress d = first(DL);

    while (d != NULL)
    {
        if (relation(d) != NULL)
        {
            if (next(relation(d)) == NULL)
            {
                P = relation(d);
                relation(d) = NULL;
            }
            else
            {
                relationAddress temp = relation(d);
                while (next(next(temp)) != NULL)
                {
                    temp = next(temp);
                }
                P = next(temp);
                next(temp) = NULL;
            }
        }

        d = next(d);
    }
}

void relationDeleteAfter(doctorList DL, relationAddress prec, relationAddress P)
{
    relationAddress temp;

    P = relation(first(DL));
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

void changeRelationToPatient(doctorList parent, string str, patientList child, string nik, string new_nik)
{
    doctorAddress da = findDoctor(parent, str);
    patientAddress pa = findPatient(child, nik);
    patientAddress pa_new = findPatient(child, nik);

    if (da != NULL && pa != NULL && pa_new != NULL)
    {
        relationAddress ra = relation(da);

        if (ra == NULL)
        {
            cout << "Relasi tidak ditemukan." << endl;
        }
        else
        {
            bool is_found = false;
            while (ra != NULL && !is_found)
            {
                if (nextPatient(ra) == pa)
                {
                    nextPatient(ra) = pa_new;
                    is_found = true;
                }
                ra = next(ra);
            }
        }
    }
}
