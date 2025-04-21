#ifndef AUTHENTICATION_HPP
#define AUTHENTICATION_HPP

#include <string>
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <cctype>

bool verifRegister(std::string nama, std::string password, std::string jenis);
std::string verifLogin(std::string accountName, std::string password);

std::string inputPassword();
// void addUser(std::string newName, std::string newPass, std::string newType);
// void getAccData(std::string fileName);
// void saveNewAcc(std::string filename, std::string nama, std::string pass, std::string jenis);
// void nameInData(std::string Name);
// void isInType(std::string type);
// bool validPassword(std::string type, std::string password);
// std::string jenisAdmin(std::string username, std::string password);
// void verifPaslon();

#endif