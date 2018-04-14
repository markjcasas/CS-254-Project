#include <iostream>
#include <fstream>
#include "Patient.h"
#include "Date.h"
using namespace std;
void Menu1();
void Remove1(Patient1 checkIn1[], int& count1, int index1);
int main(int argc, const char * argv[])
{
	Patient1 checkIn1[10];
	Patient1 patient1[20];
	char choice1;
	int i1 = 0;
	int id1 = 0,
		doctor1 = 0,
		countAll1 = 0,
		count1 = 0;
	int day1, month1, year1;
	char first1[15], last1[15];
	Date1 birthdate1, current1;
	bool found1 = false;

	ifstream inFile1;
	inFile1.open("CurrentPatients1.txt", ios::in | ios::binary);
	if (inFile1.is_open())
	{
		inFile1.read((char*)&countAll1, sizeof(int));
		for (int i1 = 0; i1 < countAll1; i1++)
		{
			inFile1.read((char*)&patient1[i1], sizeof(Patient1));
		}
		inFile1.close();
	}

	cout << "Enter present date" << endl;
	cout << "Day: ";
	cin >> day1;
	cout << "Month: ";
	cin >> month1;
	cout << "Year: ";
	cin >> year1;
	current1.setDate1(month1, day1, year1);
	do
	{
		Menu1();
		cin >> choice1;
		switch (choice1)
		{
		case 'A':
			cout << "---------------------------" << endl;
			cout << "Check-In a new patient" << endl << endl;
			cout << "Patient-ID: ";
			cout << countAll1 + 1 << endl;
			checkIn1[count1].setID1(countAll1 + 1);
			cout << "First name: ";
			cin >> first1;
			checkIn1[count1].setFirstName1(first1);
			cout << "Last name: ";
			cin >> last1;
			checkIn1[count1].setLastName1(last1);
			cout << "Doctor-ID: ";
			cin >> doctor1;
			checkIn1[count1].setPrimaryDoctorID1(doctor1);
			cout << "Birthdate " << endl;
			cout << "Day: ";
			cin >> day1;
			cout << "Month: ";
			cin >> month1;
			cout << "Year: ";
			cin >> year1;
			birthdate1.setDate1(month1, day1, year1);
			checkIn1[count1].setBirthDate1(birthdate1);
			patient1[countAll1] = checkIn1[count1];
			count1++;
			countAll1++;
			break;
		case 'B':
			cout << "---------------------------" << endl;
			cout << "Check-In a returning patient" << endl << endl;
			found1 = false;
			i1 = 0;
			do
			{
				cout << "Enter Patient-ID: ";
				cin >> id1;
				do
				{
					if (patient1[i1].getID1() == id1)
					{
						checkIn1[count1] = patient1[i1];
						count1++;
						found1 = true;
					}
					i1++;
				} while (!found1 && i1 < countAll1);
				if (!found1)
				{
					cout << "Not available" << endl;
					cout << "Check-In as a new patient? N or Y: ";
					cin >> choice1;
				}
			} while (!found1 && choice1 == 'N');
			break;
		case 'C':
			found1 = false;
			cout << "---------------------------" << endl;
			cout << "Check-Out a patient" << endl;
			i1 = 0;
			do
			{
				cout << "Enter Checked-Out patient-ID: ";
				cin >> id1;
				do
				{
					if (checkIn1[i1].getID1() == id1)
					{
						cout << "Provider-ID: ";
						cin >> doctor1;
						cout << "Procedure-ID: ";
						cin >> id1;
						cout << checkIn1[i1].enterProcedure1(current1, id1, doctor1);
						for (int j = 0; j < countAll1; j++)
							if (patient1[j].getID1() == checkIn1[i1].getID1())
							{
								patient1[j].enterProcedure1(current1, id1, doctor1);
								cout << j;
								cout << "Patient-ID: " << j + 1 << " Checked-Out" << endl << endl;
							}
						Remove1(checkIn1, count1, i1);
						found1 = true;
					}
					i1++;
				} while (!found1 && i1 < count1);
				if (!found1)
				{
					cout << "Not available" << endl;
					cout << "Checked-In as a new patient / Checked-In as a returning patient? N or Y: ";
					cin >> choice1;
				}
			} while (!found1 && choice1 == 'N');
			break;
		case 'D':
			found1 = false;
			cout << "---------------------------" << endl;
			cout << "Display all info of the patient" << endl << endl;
			cout << "Enter Patient-ID: ";
			cin >> id1;
			i1 = 0;
			do
			{
				if (patient1[i1].getID1() == id1)
				{
					cout << "Patient-ID " << patient1[i1].getID1() << endl;
					cout << "Name: " << patient1[i1].getFirstName1() << " " << patient1[i1].getLastName1() << endl;
					cout << "Birthdate: " << patient1[i1].getBirthDate1() << endl;
					cout << "Doctor-ID: " << patient1[i1].getPrimaryDoctorID1() << endl;
					patient1[i1].printAllProcedures1();
					found1 = true;
				}
				i1++;
			} while (!found1 && i1 < countAll1);
			if (!found1)
				cout << "Not available" << endl;
			break;
		case 'E':
			cout << "---------------------------" << endl;
			cout << "Patient checked-in yet not checked-out" << endl << endl;
			if (count1 > 0)
			{
				for (int i1 = 0; i1 < count1; i1++)
				{
					cout << "Patient-ID " << checkIn1[i1].getID1() << endl;
					cout << "Name: " << checkIn1[i1].getFirstName1() << " " << checkIn1[i1].getLastName1() << endl;
					cout << "Birthdate: " << checkIn1[i1].getBirthDate1() << endl;
					cout << "Doctor-ID: " << checkIn1[i1].getPrimaryDoctorID1() << endl << endl;
				}
			}
			else
				cout << "All patients checked-out" << endl << endl;
			break;
		case 'F':
			cout << "---------------------------" << endl;
			if (count1 == 0)
			{
				ofstream outFile;
				outFile.open("CurrentPatients1.txt", ios::out | ios::binary);
				if (outFile.is_open())
				{
					outFile.write((char*)&countAll1, sizeof(int));
					for (int i1 = 0; i1 < countAll1; i1++)
						outFile.write((char*)&patient1[i1], sizeof(Patient1));
					outFile.close();
					cout << "Finish" << endl;
				}
			}
			else
			{
				for (int i1 = 0; i1 < count1; i1++)
				{
					cout << checkIn1[i1].getID1() << endl;
					cout << checkIn1[i1].getFirstName1() << " " << checkIn1[i1].getLastName1() << endl;
					cout << checkIn1[i1].getBirthDate1() << endl;
					cout << checkIn1[i1].getPrimaryDoctorID1() << endl;
				}
				choice1 = 'A';
			}
			break;
		}
	} while (choice1 != 'F' && choice1 != 'f');
	return 0;
}
void Menu1()
{
	cout << "-------------------------------" << endl;
	cout << "Menu" << endl;
	cout << "A : Check-in new patient" << endl;
	cout << "B : Check-in returning patient" << endl;
	cout << "C : Check-out a patient" << endl;
	cout << "D : Display info of a patient" << endl;
	cout << "E : Display list of patients who checked-in yet not checked-out" << endl;
	cout << "F : Quit" << endl;
	cout << "Enter choice (A, B, C, D, E, F): ";
}

void Remove1(Patient1 checkIn1[], int& count1, int index1)
{
	for (int i1 = index1; i1 < count1; i1++)
		checkIn1[i1] = checkIn1[i1 + 1];
	count1--;
}
