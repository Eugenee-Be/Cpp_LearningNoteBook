Content Table (To be built...)

# File Input/Output (Simple)

* Objectives
  * Learn to use basic File I/O functions

## Fundamental syntax

* Output
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

* Input
  * Read data from the file to the console
  * Similar to file output process

### Additional Input/Output functions

 * ``` cin.getline(char/string, MAX_NAME_LEN); ```
 
 * ``` cin.get(); ```

 * ``` cout.precision(the number of digits shown); ```

 * ``` cout.setf(ios_base::showpoint); ```

## Assignment
 
  * Read data from file and output calculation result
