#pragma once
#ifndef Patient_h
#define Patient_h
#include "Date.h"
#include <string>

struct procedure1
{
	Date1 dateOfProcedure1;
	int procedureID1;
	int procedureProviderID1;
};

class Patient1
{
private:
	int ID1;
	char firstName1[15];
	char lastName1[15];
	Date1 birthdate1;
	int primaryDoctorID1;
	procedure1 record1[500];
	int currentCountOfProcedures1;
public:
	Patient1(int, const char *, const char *, Date1, int);
	Patient1() : ID1(0), firstName1{}, lastName1{}, birthdate1(0, 0, 0), primaryDoctorID1(0) {};
	void setID1(int);
	void setFirstName1(const char *);
	void setLastName1(const char *);
	void setBirthDate1(Date1);
	void setPrimaryDoctorID1(int);
	int getID1();
	const char * getFirstName1();
	const char * getLastName1();
	Date1 getBirthDate1();
	int getPrimaryDoctorID1();
	Patient1& operator=(Patient1 other1);
	bool enterProcedure1(Date1 procedureDate1, int procedureID1, int procedureProviderID1);
	void printAllProcedures1();
};
#endif