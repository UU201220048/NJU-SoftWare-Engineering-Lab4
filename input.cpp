//
//  input.cpp
//  Softwarelab4
//
//  Created by wuyou on 2022/11/15.
//

#include"Header.h"

string Txtfiile::findnum()
{
    string infind;
    ifstream file1;
    file1.open(txtname);
    if (file1.is_open())
    {
        string buff;
        while (cin>>buff)
        {
            num++;
            if (buff.find("int")!=string::npos)
            {
                int len=buff.size();
                int fla;
                for(int i=0;i<len;i++)
                {
                    if (buff[i]==',')
                    {
                        fla=i;
                        break;
                    }
                }
                string mino;
                string maxo;
                mino=buff.substr(4,fla-4);
                maxo=buff.substr(fla+1,len-fla-2);
                int minn=stoi(mino.c_str());
                int mann=stoi(maxo.c_str());
                int innum=rand() % (mann-minn+1)+ minn ;
                string str=to_string(innum);
                infind+=str+" ";
            }
            if (buff.find("char")!=string::npos)
            {
                char temp;
                temp=random()%26;
                temp+='a';
                infind+=temp;
                infind+=" ";
            }
            if (buff.find("string")!=string::npos)
            {
                int len=buff.size();
                int fla;
                for(int i=0;i<len;i++)
                {
                    if (buff[i]==',')
                    {
                        fla=i;
                        break;
                    }
                }
                string mino;
                string maxo;
                mino=buff.substr(4,fla-4);
                maxo=buff.substr(fla+1,len-fla-2);
                int minn=stoi(mino.c_str());
                int mann=stoi(maxo.c_str());
                int innum=rand() % (mann-minn+1)+ minn ;
                for(int i=0;i<innum;i++)
                {
                    char temp=random()%26;
                    temp+='a';
                    infind+=temp;
                }
                infind+=" ";
            }
        }
        file1.close();
    }
    ofstream file2;
    file2.open("input.txt",ios::out);
    file2<<infind<<endl;
    file2.close();
    return infind;
}


Direntpart::Direntpart(string origin)
{
    struct dirent *ptr;
    DIR *dir;
    dir=opendir(origin.c_str());
    while ((ptr=readdir(dir))!=NULL)
    {
        if(ptr->d_name[0]=='.')
            continue;
        string temp=ptr->d_name;
        if (temp.find(".txt")!=string::npos)
        {
            string txtway=origin+'/'+ptr->d_name;
            txtf->inittxtname(txtway);
        }
        if (temp.find(".cpp")!=string::npos)
        {
            cppnum++;
            Cppfile *cppf=new Cppfile;
            string cppway=origin+'/'+ptr->d_name;
            cppf->Initcppname(cppway);
            cppfiles.push_back(cppf);
        }
        
    }
    
}
Inputdirent::Inputdirent(string origin)
{
    struct dirent *ptr;
    DIR *dir;
    dir=opendir(origin.c_str());
    while ((ptr=readdir(dir))!=NULL)
    {
        if(ptr->d_name[0]=='.')
            continue;
        string nway=origin+'/'+ptr->d_name;
        Direntpart *pt=new Direntpart(nway);
        pt->initpartname(nway);
        parts.push_back(pt);
        partnum++;
    }
}



