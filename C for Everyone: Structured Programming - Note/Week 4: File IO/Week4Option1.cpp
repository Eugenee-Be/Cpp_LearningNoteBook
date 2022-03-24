#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //1. Set up read-in stream and initialise variables to store data
    ifstream week4; // File input stream
    string filename = "Week4_hwk.txt"; // Pre-set working file under the same directory
    int SIZE = 0;

    //2. Read in the first value to determine the size of array
    week4.open(filename);

    if (!week4.is_open())
    {
        cout << "Could not open file " << filename << endl;
        cout << "Programme terminating..." << endl;
        exit(EXIT_FAILURE);
    }

    week4 >> SIZE;
    cout << "The size of the array should be " << SIZE << "!\n" << endl;
    system("pause");
    cout << "\nGenerating array a[" << SIZE << "]!\n" << endl;
    int a[SIZE];

    //3. Read the rest of the data into the array
    int i = 0;
    int MAX = 0;
    double sum = 0.0;
    while(i < SIZE)
    {
        week4 >> a[i];
        cout << "Caught the '"<< i << "' value: " << a[i] << endl;
        sum += a[i]; // Sum up all the values
        if(a[i] > MAX) // Find the maximal value within the array
        {
            MAX = a[i];
        }
        ++i;
    }
    cout << "\nArray a[" << SIZE <<"] is now filled up!\n";

    week4.close(); // Close file input stream 'week4'

    //4. Calculation
    double avg = 0.0;
    avg = sum / SIZE;
    cout << fixed;
    cout.precision(3);
    cout.setf(ios::showpoint);
    cout << "\nResults:\nThe average is: " << avg << endl;
    cout << "The Maximum is: " << MAX << endl;

    //5. Output the result to a file
    ofstream week4Output;
    filename = "answer-hw3.txt";
    week4Output.open(filename);

    if(!week4Output.is_open())
    {
        cout << "Could not open file " << filename << endl;
        cout << "Programme terminating..." << endl;
        exit(EXIT_FAILURE);
    }

    cout << "\n\nUpdating result to file '" << filename << "'!\n"<< endl;
    system("pause");
    week4Output << fixed;
    week4Output.precision(3);
    week4Output.setf(ios::showpoint);
    week4Output << "Average = " << avg << endl;
    week4Output << "MAX = " << MAX << endl;

    week4Output.close();

    cout << "\n\nData stored in the file '" << filename << "' successfully!" << endl;

    return 0;
}