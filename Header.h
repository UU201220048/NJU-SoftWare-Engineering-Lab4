//
//  Header.h
//  Softwarelab4
//
//  Created by wuyou on 2022/11/15.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <queue>
#include <ctime>
#include <algorithm>
#include "dirent.h"
#include <vector>
#include <random>

using namespace std;


class Txtfiile
{
private:
    string txtname;
    int num;
    vector<string *> testnum;
public :
    void inittxtname(string name){txtname=name;}
    string gettxtname(){return txtname;}
    string findnum();
};

class Cppfile
{
private:
    string cppname;
    string output;
public:
    void Initcppname(string name){cppname=name;}
    string getcppname(){return cppname;}
    void run_for_output();
    string getoutput(){return output;}
    Cppfile(){run_for_output();}
};

class Item
{
private:
    Cppfile *file1;
    Cppfile *file2;
    bool compare;//0:equal;1:inequal
public:
    Item(Cppfile *f1,Cppfile *f2):file1(f1),file2(f2){Compare();}
    void Compare();
    bool getcompare(){return compare;}
    string getfile1name(){return file1->getcppname();}
    string getfile2name(){return file2->getcppname();}
};

class Direntpart:public Txtfiile,Cppfile
{
private:
    int cppnum;
    string partname;
    Txtfiile *txtf;
    vector<Cppfile *> cppfiles;
    vector<Item *>pairs;
public:
    Direntpart(string origin);
    void initpartname(string name){partname=name;}
    void addcpp(Cppfile *cp);
    void makepairs();
    void write_in();

};

class Inputdirent
{
 private:
 //string amountway;
    int partnum;
    vector<Direntpart*> parts;
public:
    Inputdirent(string origin);
    void addpart(Direntpart *pt);
    
};



