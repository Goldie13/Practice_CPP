#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#include<bits/stdc++.h>

using namespace std;

int main() 
{

    //get current directory
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    }
    else {
        perror("getcwd() error");
        return 1;
    }

    //reading the file
    string path_in{"/root/Anosh/Practice_CPP/sample_in.txt"};
    ifstream ifile; //define ifile as a var to bound to sample.txt
    ifile.open(path_in);
    if(ifile.is_open()) {
        string text{""};
        while(ifile >> text) { //Read a word from the file
            cout << text << ", ";
        }
        cout<<endl;
        ifile.close(); // release the binding between ifile & sample.txt
    } else {
        cout << "Not opened"<<endl;
    }

    //writing the file
    vector<string> vec{"My", "hometown", "is", "in","Sambhajinagar"};
    string path_out{"/root/Anosh/Practice_CPP/sample_out.txt"};
    ofstream ofile;
    ofile.open(path_out);
    if(false == ofile.is_open()){
        cout<<"Not opened"<<endl;
        return 0;
    }

    for(auto i: vec)
    {
        ofile<<i<<",";
    }

    ofile.close();

    return 0;
}
