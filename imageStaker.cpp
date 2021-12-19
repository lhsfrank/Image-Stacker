//CS201
//Hansong Li
//Assignment #2

//#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    //define the filenames
    ifstream infile;
    ofstream outfile;
    string imageSet;
    string ddd;
    string fileName;
    int width = 0;
    int height = 0;
    string magicNumber;
    int maxValue = 0;
    string temp;
    
    
    //ask the user to input an input an image set
    cout << "Please enter an image set name: " << endl;
    cin >> imageSet;
    string outfileName = "/Users/hansongli/Desktop/ppms/" + imageSet + "/" + imageSet + "_good.ppm";
    //cout << outfileName;
    
    //read the header
    infile.open("/Users/hansongli/Desktop/ppms/" + imageSet + "/" + imageSet + "_001.ppm");
    
    
    //read the magicNumber from the file
    getline(infile, magicNumber);
    //cout << "magNum: " <<magicNumber << endl;
    
    //read the width and the height from the file
    infile >> width >> height;
    //cout << "Width: " << width << " Height: " << height << endl;
    
    //exit if contains more than 1000 pixels for either dimension
    if (width > 1000 || height > 1000)
    {
        cout << "This image contains more than 1000 pixels." << endl;
        
        infile.close();
        return 0;
    }
    
    
    //read the max color value
    infile >> maxValue;
    //cout << "maxV: " << maxValue << endl;
    
    
    infile.close();
    
    
    
    //create array
    int arraySize = width * 3 * height;
    int* sumArr = new int[arraySize];
    
    //open files
    for (int i = 0; i < 10; i++)
    {
        if (i < 9)
            ddd = "00" + to_string(i+1);
        else
            ddd = "0" + to_string(i+1);
        fileName = "/Users/hansongli/Desktop/ppms/" + imageSet + "/" + imageSet + "_" + ddd + ".ppm";
        //cout << fileName << endl;
        
        infile.open(fileName);
        while (!infile)
        {
            cout << "File cannot be opened." << endl;
            
            return 0;
        }
        
        for (int line = 0; line < 3; line++)
            getline(infile, temp);
        
        //cout << arraySize << endl;
        
        int* arr = new int[arraySize];
        
        
        //copy all the data from the file
        for (int j = 0; j < arraySize; j++)
        {
            infile >> arr[j];
            sumArr[j] = sumArr[j] + arr[j];
        }
        
        //delete the array
        delete [] arr;
        
         
        infile.close();
    }
    
    //output the data to the file
    outfile.open(outfileName);
    outfile << magicNumber << endl;
    outfile << width << " " << height << endl;
    outfile << maxValue << endl;
    for (int k = 0; k < arraySize; k++)
    {
        sumArr[k] = sumArr[k]/10;
        outfile << sumArr[k] << " ";
    }
    
    
    //close the output file
    outfile.close();
    
    //delete [] sumArr;
    cout << "complete" << endl;

    return 0;
}

