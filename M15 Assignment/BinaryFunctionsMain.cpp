/**********************************
* Title : Assignment 15
* Author : Esther Cheng
 Student ID : 1754368
* Date : 10/23/2021
* Version : Version 1.0
* Description : This is program creates
* a HospitalRecord struct that contains
* the patient id, the patient's name, their
* dob, their doctor, if they have medicare,
* and their total bill. The program also
* reads and writes the HospitalRecord
* array and individual records into a binary
* file.
***********************************/
#include "BinaryFunctions.h"
#include <string>
//#include <bits/stdc++.h>

int main() {
    HospitalRecord h;
    HospitalRecord patientRecords[4];
    cout << " Reading Patient Records from text file into Array " << endl;
    cout << "*******************************************************" << endl;
    cout << endl;
    readInfo(patientRecords);

    cout << " Displaying Patient Records from Array " << endl;
    cout << "*******************************************************" << endl;
    cout << endl;
    displayInfo(patientRecords);

    cout << endl;
    cout << " Writing Patient Records onto Binary file " << endl;
    cout << "*******************************************************" << endl;
    cout << endl;

    writeBinary(patientRecords, sizeof(patientRecords));

    cout << " Reading Patient Records from Binary file into Array " << endl;
    cout << "*******************************************************" << endl;
    cout << endl;

    readBinary(patientRecords,4);

    cout << " Displaying  Patient Records from  Array " << endl;
    cout << "*******************************************************" << endl;
    cout << endl;
    
    displayInfo(patientRecords);
    cout << endl;
    cout << " Reading a Random Patient Records (#1) from Binary File"<<endl;
    cout << "*******************************************************"<<endl;
    cout << endl;

    HospitalRecord record;
    readBinaryRandomByRecord(record, 0);

    cout << " Displaying the Patient Record" << endl;
    cout << "*******************************************************" << endl;
    cout << endl;
    displayRecord(record);


    cout << endl;
    cout << " Reading a Random Patient Records (#3) from Binary File" << endl;
    cout << "*******************************************************" << endl;
    cout << endl;
    readBinaryRandomByRecord(record, 2);

    cout << " Displaying the Patient Record" << endl;
    cout << "*******************************************************" << endl;
    cout << endl;


    displayRecord(record);

    //filling a patient record for writing
    record.patientId = 5;
    char temp[10];
    string s = "Harry";
    strcpy(temp, s.c_str());
    for (int i = 0; i < 10; i++) {
        record.fname[i] = temp[i];
    }
    
    s = "Potter";
    strcpy(temp, s.c_str());
    for (int i = 0;i < 10; i++) {
        record.lname[i] = temp[i];
    }

    s = "060666";
    strcpy(temp, s.c_str());
    for (int i = 0; i < 10; i++) {
        record.dob[i] = temp[i];
    }

    s = "Dobby";
    strcpy(temp, s.c_str());
    for (int i = 0; i < 10; i++) {
        record.doctor[i] = temp[i];
    }

    record.medicare = true;
    record.bill = 6541.33;

    cout << endl;

    cout << " Adding a new Patient Record to the end of the binary file" << endl;
    cout << "*******************************************************" << endl;
    cout << endl;


    writeRecord(patientRecords, 5,record);

    cout << " Displaying the Patient Record" << endl;
    cout << "*******************************************************" << endl;
    cout << endl;

    displayRecord(record);
}
