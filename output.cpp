//
//  output.cpp
//  Softwarelab4
//
//  Created by wuyou on 2022/11/15.
//

#include "Header.h"


void Item::Compare()
{
    if (file1->getoutput()==file2->getoutput())
    {
        compare=true;
    }
   else
   {
       compare=false;
   }
}

void Direntpart::makepairs()
{
    for(int i=0;i<cppnum;i++)
    {
        for(int j=i;j<cppnum;j++)
        {
            Item *ioo=new Item(cppfiles[i],cppfiles[j]);
            pairs.push_back(ioo);
        }
    }
}

void Direntpart::write_in()
{
    ofstream f1;
    f1.open("equal.csv",ios::out);
    f1<<"file1"<<','<<"file2"<<endl;
    ofstream f2;
    f2.open("inequal.csv",ios::out);
    for(int i=0;i<pairs.size();i++)
    {
        if (pairs[i]->getcompare()==true)
        {
            f1<<pairs[i]->getfile1name()<<','<<pairs[i]->getfile2name()<<endl;
        }
        else
        {
            f2<<pairs[i]->getfile1name()<<','<<pairs[i]->getfile2name()<<endl;
        }
    }
}

