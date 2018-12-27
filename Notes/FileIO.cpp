#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main (int argc, char* args[]) //allows CL input
{
    char data[100];
    /* open a file in read mode. */
    ifstream infile;
    
    infile.open("input.txt");
    cout << "Reading from the file" << endl;
    infile.getline(data, 99, '\n');
    /* write the data at the screen */
    cout << data << endl;
    /* again read the data from the file and display it. */
    infile >> data;
    cout << data << endl;//
    /* close the opened file. */
    infile.close();
    return 0;
}

