Content Table (To be built...)

# File Input/Output (Simple)

* Objectives
  * Learn to use basic File I/O functions

## Fundamental syntax

### 1. File Output

  * Put data from the console to the file
  * Listing _outfile.cpp_
    
    **Required Headers:**
    ```
    #include <iostream> // For general use
    #include <fstream> // For file input/output
    #include <cstdlib> // For 'exit(EXIT_FAILURE)'
    ```
    
    **Variables Declaration:**
    ```
    char automobile[50];
    int year;
    double a_price;
    double b_price;
    ```
    
    **File Output Initialisation:**
    ```
    ofstream outFile; // Declare the stream
    outFile.open("carinfo.txt"); // Open the certain file
    ```

    **Check if the file is opened correctly:**
    ```
    ...
    getline(filename, 50);
    ...
    if (!outFile.is_open()) // File opened unsuccessfully
    {
      cout << "Could not open the file " << filename << endl;
      cout << "Programme terminating...\n"; 
      exit(EXIT_FAILURE);
    }
    ```
    
    **Output to the file**
    ```
    outFile << fixed; // Demonstrate the double value with fixed amount of digits
    outFile.precision(2); // How many digits shown in total
    outFile.setf(ios_base::showpoint); // Show the decimal point (Xiao Shu Dian)
    outFile << "Model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was $: " << a_price << endl;
    outFile << "Now $: " << b_price << endl;
    ```
    
    **Close File**
    ```
    outFile.close(); // Done with this file
    return 0;
    ```
  * The whole output process is done!

* 📝 _Listing: Output practice_

```
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream fileout;
    string filename = "test.txt";
    fileout.open(filename);
    char carName[50];
    char carOwner[50];
    int i = 1;
    cin.getline(carName, 50);
    cin.getline(carOwner, 50);
    fileout << "Car's Name: " << carName << endl;
    fileout << "Car's Owner: " << carOwner << endl;
    fileout << "Car's number: " << i << endl;

    fileout.close();
 return 0;
}
```

* Input
  * Read data from the file to the console
  * Similar to file output process

### 2.File Input

   **File Input Initialisation:**
   ```
   ifstream filein; // Declare the stream
   filein.open("testIn.txt"); // Open the certain file
   ```
    
   **Variables Declaration:**
   ```
   double value;
   double sum = 0.0;
   int count = 0;
   ```
   
   **Read data from the file**
   ```
   inFile >> value;
   while (filein.good())
   {
      ++count;
      sum += value;
      filein >> value;
   }
   ```
   
   **File input ending flag**
   ```
   if (file.eof())
   {
      cout << "End of file reached.\n";
   }
   else if (file.fail())
   {
      cout << "Input terminated by data mismatch.\n";
   }
   else
   {
      cout << "Input terminated for unkown reason.\n";
   }
   ```
   
   **Close the file**
   ```
   filein.close();
   ```
* 📝 _Listing: Input Practice_

```
#include <iostream> // For normal use
#include <fstream> // For File I/O
#include <string> // For string class
#include <iomanip> // For setw()
#include <cstdlib> // For exit(EXIT_FAILURE)

using namespace std;

int main()
{
    int d1, counter = 1;

    ifstream filein;
    string filename = "testIn.txt";
    filein.open(filename);

    if (!filein.is_open()) // Test the flag if the file is opened correctly
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Programme terminating...\n";
        exit(EXIT_FAILURE);
    }

    while(filein.good()) // Use good() as loop flag
    {
        filein >> d1; // Read in data from the file to variable 'd1'
        cout << "The '" << counter << "' value is: "; /*<< setw(3)*/
        cout.setf(ios::right);
        cout.width(2);
        cout << d1 << endl;
        counter++; // Count one value
        //  File input pointer points to the next value
    }

    if (filein.eof()) // Reached to the end of the file successfully
        cout << "\nThe end of the file reached.\n" << endl;

    cout << "These are all the data inside file testIn.txt." << endl;

    return 0;
}
```

### File I/O subfunctions

* eof( )
  * Return true when pointer reaches the end of file

* bad( )
  * Return true when write/read processes go wrong

* good( )
  * Return false when any preceding functions return true

* is_open( )
  * Return true when file opens correctly

* clear( )

### Additional Input/Output functions

 * ⭐ ``` cin.getline(char/string, MAX_NAME_LEN); ```
 
 * ``` cin.get(); ```

 * ``` cout.precision(the number of digits shown); ```

 * ``` cout.setf(ios_base::showpoint); ```

### Useful small functions

* count( first iterator, last iterator, value)

* Alignment 1

``` 
#include <iomanip>
 ...
cout << setw(n) // Align to right 
```

* Alignment 2
``` 
cout.setf(ios::left/rigth); 
cout.width(n) // Aligning output values 
```

### Issues

* ❓ cin.get() & cin.getline()
 * Make sure to add the MAX_LEN parameter
 * Q: Why can't I enter the name when I do it like this?
 
   Type:
    ```
    BMW[SPACE]Ferrari[ENTER]
    ```
    
    ```
    cin.get(carName, 50);
    cin.getline(carOwner, 50);
    fileout << "Car's Name: " << carName << endl;
    fileout << "Car's Owner: " << carOwner << endl;
    ```
  * Proceed: cin.get() detects the [ENTER] and ends. But why not continue to run cin.getline()??
    
## Assignment
 
  * Read data from file and output calculation result
