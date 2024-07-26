//Name: Alieu Barrow
//Class: Structured Programming In C++
//Date: 1/11/2021
//Assignment 6: Task 2;  Read from a text file
//IDE: Visual Studio 2022

//Header files
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main() {

        //Variables
        int digits;
        double sum = 0;
        double mean;
        int largest = 0;
        double counter = 0;
        int previous = 0;
        int temp;

        ifstream inputfile("integers.txt"); //Open text file

        if (!inputfile.is_open()) { // error control important
                cout << "Failed to open the file integers.txt!" << endl;
                return 1;
        }

        //Sum digits and find max integer
        while (inputfile >> digits) {
                sum += digits; //Add to sum up
                counter++;
                temp = max(previous, digits); //Check if number is bigger than the previous entry. Swap and make next max if it is
                if (temp > largest) {
                        largest = temp;
                }
                previous = digits;
        }

        mean = sum / counter; //Find mean

        //Print output 
        cout << "Sum: " << sum << endl;
        cout << "Mean Value : " << mean << endl;
        cout << "Max: " << largest << endl;

        inputfile.close(); //Close file

        return 0;
}
