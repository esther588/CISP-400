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
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

struct HospitalRecord {
    int patientId;
    char fname[10];
    char lname[10];
    char dob[10];
    char doctor[10];
    bool medicare;
    double bill;
};

void readInfo(HospitalRecord patients[]) {
    ifstream strdata("/Users/esthercheng/Downloads/data.txt");
    try {
        if (!strdata) {
            throw 505;
        }
    } catch(...) {
        cout << "File Open Error" << endl;
        exit(1); // terminate with error
    }
    // read 4 lines from data.txt, one at time
    // using getline
    // use istringstream to input this information
    // into the array of patient records.
    string str, fname, lname, dob, doctor;
    int index = 0, patientId = 0;
    bool medicare;
    double bill = 0.0;
    char fnameArr[10], lnameArr[10], dobArr[10], doctorArr[10];
    while(!strdata.eof()) {
        getline(strdata, str);
        std::istringstream stream(str);
        stream >> patientId >> fname >> lname >> dob >> doctor >> medicare >> bill;
        HospitalRecord newPatient;
        newPatient.patientId = patientId;
        strcpy(fnameArr, fname.c_str());
        strcpy(lnameArr, lname.c_str());
        strcpy(dobArr, dob.c_str());
        strcpy(doctorArr, doctor.c_str());
        for (int i = 0; i < 10; i++) {
            newPatient.fname[i] = fnameArr[i];
            newPatient.lname[i] = lnameArr[i];
            newPatient.dob[i] = dobArr[i];
            newPatient.doctor[i] = doctorArr[i];
        }
        newPatient.medicare = medicare;
        newPatient.bill = bill;
        patients[index] = newPatient;
        index++;
    }
    strdata.close();
}

void displayInfo(HospitalRecord patients[]) {
    for (int i = 0; i < 4; i++) {
        cout << setw(4) << patients[i].patientId << setw(10) << patients[i].fname << setw(10) << patients[i].lname << setw(10) << patients[i].dob << setw(10) << patients[i].doctor << setw(4) << patients[i].medicare << setw(10) << setprecision(2) << fixed << patients[i].bill << endl;
    }
}
void displayRecord(HospitalRecord record) {
   cout << setw(4) << record.patientId << setw(10) << record.fname << setw(10) << record.lname << setw(10) << record.dob << setw(10) << record.doctor << setw(4) << record.medicare << setw(10) << setprecision(2) << fixed << record.bill << endl;
}

void writeBinary(HospitalRecord patientRecords[],int size) {
    //open a binary file called "data.bin" in output mode
    // write the patientRecord array into the Binary file
    // close the file
    // size is the size of the array in terms of total bytes
    ofstream wf("/Users/esthercheng/Downloads/data.bin", ios::out | ios::binary);
    if(!wf) {
        cout << "Cannot open file!" << endl;
        exit(0);
    }
    
    for(int i = 0; i < 4; i++) {
          wf.write((char *) &patientRecords[i], size);
    }
    wf.close();
}

void readBinary(HospitalRecord patientRecords[], int size) {
    // open the binary file called "data.bin" in input mode
    // read the entire patient record array
    // the size of the array is the given size in terms of total bytes
    // close the file
    ifstream rf("/Users/esthercheng/Downloads/data.bin", ios::in | ios::binary);
    if(!rf) {
        cout << "Cannot open file!" << endl;
        exit(0);
    }

    for(int i = 0; i < 4; i++) {
        rf.read((char *) &patientRecords[i], size);
    }
    rf.close();

}
void readBinaryByRecord(HospitalRecord patientRecords[], int size) {
    // open the binary file called "data.bin" in input mode
    // read the  patient record array record by record from the file
    // into the array
    // the size of the array here is the number of records
    // close the file
    ifstream rf("/Users/esthercheng/Downloads/data.bin", ios::in | ios::binary);
    if(!rf) {
        cout << "Cannot open file!" << endl;
        exit(0);
    }
    HospitalRecord patient;
    for (int i = 0; i < size; i++) {
        rf.read((char*) (&patient), sizeof(HospitalRecord));
        patientRecords[i] = patient;
    }
    rf.close();

}

// this method is used to calculate offet as the number of bytes
// from the beginning of the file
// it multiplies the record size with the array index

long byteNum(int recNum) {
    return recNum * sizeof(HospitalRecord);
}


void readBinaryRandomByRecord(HospitalRecord &record, int index) {
    // open the binary file called "data.bin" in input mode
    // randomly access the record by using seekg to read the record
    // at the index position requested
    // the size of the array is the given size
    // use given byteNum method if needed
    // close the file
    ifstream rf("/Users/esthercheng/Downloads/data.bin", ios::in | ios::binary);
    if(!rf) {
        cout << "Cannot open file!" << endl;
        exit(0);
    }
     
    // using seekg(pos) method to place pointer at the record of given index
    rf.seekg(byteNum(index));
     
    // reading the record
    rf.read((char*) &record, sizeof(HospitalRecord));
    
    // using seekg()place pointer at end of file
    rf.seekg(0, ios::end);
    rf.close();

}

void writeRecord(HospitalRecord patientRecords[], int index, HospitalRecord &record) {
    // open data.bin file in input and output mode
    // write the input record as the fifth record of the array
    // use byteNum method if necessary
    // using the current file position, use seekg with negative parameter
    // to read back the record just written
    fstream bindata;
    bindata.open("/Users/esthercheng/Downloads/data.bin", ios::in | ios::out | ios::binary);
    if(!bindata) {
        cout << "Cannot open file!" << endl;
        exit(0);
    }
    
    bindata.seekp(byteNum(index));
    bindata.write((char*) &record, sizeof(HospitalRecord));
    bindata.seekg(ios::cur);
    bindata.read((char*) &record, sizeof(HospitalRecord));
    bindata.close();
    
}
