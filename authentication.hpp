#ifndef AUTHENTICATION_HPP
#define AUTHENTICATION_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

struct node {
    string name;
    string password;
    string type;
    node *next;
};


void addUser(string newName, string newPass, string newType);
void getAccData(string fileName);
void saveNewAcc(string filename, string nama, string pass, string jenis);
void nameInData(string name);
void isInType(string type);
bool validPassword(string type, string password);
void verifRegister(string nama, string password, string jenis);
string jenisAdmin(string username, string password);
string verifLogin(string accountName, string password);
void verifPaslon();

#endif