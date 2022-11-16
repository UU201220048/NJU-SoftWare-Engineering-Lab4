//
//  run.cpp
//  Softwarelab4
//
//  Created by wuyou on 2022/11/15.
//

#include "Header.h"

void Cppfile::run_for_output()
{
    string temp=cppname;
    string command="gcc ";
    command+=cppname;
    system(command.c_str());
    for(int i=0;i<cppname.size();i++)
    {
        if (cppname[i]=='.')
        {
            cppname.erase(i);
            break;
        }
    }
    string command2;
    command2=cppname+".out <input.txt >ouput.txt";
    system(command2.c_str());
    cppname=temp;
    ifstream file1;
    file1.open("ouput.txt");
    if (file1.is_open())
    {
        getline(file1,output);
    }
    
}
