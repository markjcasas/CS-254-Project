#include "Patient.h"
#include <iostream>
using namespace std;
Patient1::Patient1(int id1, const char * first1, const char *last1, Date1 birth1, int doctor1)
{
	setID1(id1);
	setFirstName1(first1);
	setLastName1(last1);
	setBirthDate1(birth1);
	setPrimaryDoctorID1(doctor1);
};

void Patient1::setID1(int id1)
{
	ID1 = id1;
}

void Patient1::setFirstName1(const char * first1)
{
	if (strlen(first1) > 15)
		strncpy_s(firstName1, first1, 14);
	else
		strcpy_s(firstName1, first1);
}

void Patient1::setLastName1(const char * last1)
{
	if (strlen(last1) > 15)
		strncpy_s(lastName1, last1, 14);
	else
		strcpy_s(lastName1, last1);
}

void Patient1::setBirthDate1(Date1 birth1)
{
	birthdate1 = birth1;
}
void Patient1::setPrimaryDoctorID1(int doctor1)
{
	primaryDoctorID1 = doctor1;
}
int Patient1::getID1()
{
	return ID1;
}
const char * Patient1::getFirstName1()
{
	return firstName1;
}
const char * Patient1::getLastName1()
{
	return lastName1;
}
Date1 Patient1::getBirthDate1()
{
	return birthdate1;
}
int Patient1::getPrimaryDoctorID1()
{
	return primaryDoctorID1;
}

bool Patient1::enterProcedure1(Date1 procedureDate1, int procedureID1, int procedureProviderID1)
{
	if (currentCountOfProcedures1 > 500)
	{
		cout << "Can't add more procedures" << endl;
		return false;
	}
	else
	{
		record1[currentCountOfProcedures1].dateOfProcedure1 = procedureDate1;
		record1[currentCountOfProcedures1].procedureID1 = procedureID1;
		record1[currentCountOfProcedures1].procedureProviderID1 = procedureProviderID1;
		currentCountOfProcedures1++;
		return true;
	}
}
void Patient1::printAllProcedures1()
{
	cout << "Procedures of the patient" << endl;
	for (int i1 = 0; i1 < currentCountOfProcedures1; i1++)
	{
		cout << "Procedure-Date: " << record1[i1].dateOfProcedure1 << endl;
		cout << "Procedure-ID: " << record1[i1].procedureID1 << endl;
		cout << "Provider-ID: " << record1[i1].procedureProviderID1 << endl;
	}
}

Patient1& Patient1::operator=(Patient1 other1)
{
	ID1 = other1.ID1;
	strcpy_s(firstName1, other1.firstName1);
	strcpy_s(lastName1, other1.lastName1);
	birthdate1 = other1.birthdate1;
	primaryDoctorID1 = other1.primaryDoctorID1;
	for (int i1 = 0; i1 < other1.currentCountOfProcedures1; i1++)
	{
		record1[i1] = other1.record1[i1];
	}
	currentCountOfProcedures1 = other1.currentCountOfProcedures1;
	return *this;
}