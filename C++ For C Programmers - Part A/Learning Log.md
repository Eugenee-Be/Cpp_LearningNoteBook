# Learning Log


## 📘 Week 1 Module 1 [11-04-2022]

### 🚅 Outlines

* 1️⃣ Object-oriented programming
* 2️⃣ Converting a C Programme to C++
  * C Libraries
    play craps
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #define SIDES 6
    #define R_SIDE (rand() % SIDES + 1) // Preprocessors
    // we want to use Preprocessors less
    int main()
    {
      srand(clock()); // seeding function calls system's clock
      printf("\nEnter number of trials:")
      scanf("%d", &trials);
      for (j = 0; j < trials; ++j)
        outcomes[(d1 = R_SIDE) + (d2 = R_SIDE)]++;
      printf("probability\n");
      for (j = 2; j < n_dice * SIDES + 1; ++j)
        printf("j = %d p =%lf\n", j, (double)(outcomes[j]) / trials);
    }
    ```
  * #define macros
  * main()
* 3️⃣ Using C++ code
  * Comments: 
     
     multiple-line comments ``` /* ... */ ``` 
     
     rest-of-line comments ``` // ``` ; flexible, safter generally
     
  * Libraries

      ```
      #include <iostream> // drops '.h' still available
      #include <cstdlib> 
      #include <ctime>
      using namespace std; // context encapsulation
      const int sides = 6; // replaces many sharp defines
      inline int r_side(){ return (rand() % sides + 1); }
      ```
      inline - compiler directive: when declaring functions to speed them up
      function - cost me money, runtime...
* 4️⃣ C++ Improvements
  * namespace/context
    
    ```
    std::cout << "\nEnte...";
    cout << "\nEnte...";
    ```
    '<<': bit shift
* 5️⃣ C++ Advantages [12-04-2022]
  * Type safe ```cin >> ``` ```cout << ```
  * Declaration can be intermixed after executable
  * Use of new - heap ```malloc() = new, free = delete```
  * Localisation of initialiser drives down complexity in _for_ declaration
  * Type casting, safe cast ```static_cast<double>```

* 6️⃣ C++ is Better Than C
  * More type safe

    types - critical underpins of programming language

    machine-level: 2-byte, 8 bytes

  * More libraries
  * Less reliance on preprocessor, avoid ``` #define ``` in C++ programming
  * OO vs imperative
  * So far used keywords:

    inline, const - correctness

    static_cast<type>

    namespaces - encapsulation

    iostream

    for-statement initialisation

* 7️⃣ C ```Swap``` Funciton
 
  * C : call-by-value language - parameters passed into a function, handled locally, altered, come out pass back and the parameters unchanged
  * Indirection
 
   Use pointers
 
 ```
 void swap(int* i, int* j)
 {
    int temp = *i;
    *i = *j;
    *j = temp;
 }
 ```
 
   \* - de-reference
 
   int\* - "pointer to int"
 
 ```
 void swap_double(double* i, double* j)
 {
    double temp = *i;
    *i = *j;
    *j = temp;
 }
 ```
 
 ```
 int main()
 {
   int m = 6, n =10;
   double x = 5.3, y = 10.6;
   ...
   swap(&m, &n);
   ...
   swap_double(&x, &y);
   ...
   return 0;
 }
 ```
 Called with addresses of variables
 
 Call-by-reference simulated with pointers
    
* 8️⃣ ```Swap``` Funciton in C++
  
  * C++ Conversion of Swap: Overloading and Call-by-reference
  
        #include <iostream>
        using namespace std;

        inline void swap( int& i, int& j)
        {
          int temp = i;
          i = j;
          j = temp;
        }
        inline void swap(double& i, double& j)
        {
          double temp = i;
          i = j;
          j = temp;
        }
     
     - Overloading: allow two functions to have same name 💡 (See ❔ Question section)
     - Call-by-reference
     - i o: type safe, intuitive and convenient
     - namespace std: ```std::cout```
     - inline: efficient
     - ```int& i```: referecne to i
 
           int main()
           {
             int m = 5, n = 10;
             double x = 5.3, y = 10.6;
             cout << "inputs:" << m << "," << n << endl;
             swap(m, n);
             cout << "outputs:" << m << "," << n << endl;
             cout << "double inputs:" << x << "," << y << endl;
             swap(x, y);
             cout << "double outputs:" << x << "," 
                  << y << endl;
             ...
             return 0;
           }
* 9️⃣ Generics in C++
  * Programming using templates
  * C++ template
       ```
       template<class T>
       inline void swap(T& d, T& s)
       {
         T temp = d;
         d = s;
         s = temp;
       }
       ```
    - Keyword:
           
        template
 
        < >
        
        class
        
        Identifier T (Capity is convention) - a **meta** variable with an actual type going to be substituted for
  * Prescription
    - Add template\<class T\> // T is id
    - Now for int or double or whatever use T when called as in swap(a, b)
    - The compiler uses a signature matching routine to infer what the code should use for type
  * C++ use of template
    
    ```#include <complex>``` Library for complex numbers
 
    ```
    int main()
    {
      int m = 5, n = 10;
      double x = 5.3, y = 10.6;
      complex<double> r(2.4, 3.5), s(3.4, 6.7);
      cout << "inputs:" << m << "," << n << endl;
      swap(m, n);
      cout << "outputs: " << m << "," << n << endl;
    ```
* Summing 'n' numbers Template
 
  * 'summable' is the generic type, providing documentation, that the type that we replace summable with has to allow '+=' operation; not workable for string type, when string occurs will get syntax error
 ```
 template <class summable> 
 summable sum(const summbale data[], int size, summable s = 0)
 {
   for( int i = 0; i < size; ++i)
      s += data[i];
   //+= must work for summable
   return s;
 }
 ```
 ### ❔ Questions

* Quiz - Object
  * Object-oriented: Data and operations are bound together, type expansivity
    
    Shoule be comfortable with recursion
    
    Type safety is a property of a good OO language
    
* Quiz - const double PI = 3.14159
  * creates a non-mutable variable PI
    
    - True, initialised variable PI can have its value changed _in the scope of this declaration_
 
  * equivalent to ```#define PI 3.14159
    
    - Flase, PI here is a **macro** - is textually substituted for within the scope of the #define which is normally file scope. This should be avoided.
  
* 💡 Why **overloading** - two functions having the same name is allowed in C++? Why won't that be ambiguous?
  * Signature matching
    
    Compiler provides an automatic means of differentiating between the two swaps
  
    - "Signature matching algorithm": Discriminating by signatures
    - Two routines require diferent types and number of arguments
    - Signatures: types, number of arguments the function uses
    - Promotes more readable code: Having the same name for conceptually the same activity
 
 
 
    

### ❗ Quiz summary

N/A

### ⛵ Further Exploration

* Reuse mechanism: the use of **Generics** (Template) is more powerful


 
 
## 📘 Week 2 Module 2 [ ]


### 🚅 Outlines

* tbc

### ❔ Questions

* tbc

### ❗ Quiz summary

N/A

### ⛵ Further Exploration

N/A

## 📘 Week 3 Module 3 [ ]


### 🚅 Outlines

* tbc

### ❔ Questions

* tbc

### ❗ Quiz summary

N/A

### ⛵ Further Exploration

N/A


## 📘 Week 4 Module 4 [ ]


### 🚅 Outlines

* tbc

### ❔ Questions

* tbc

### ❗ Quiz summary

N/A

### ⛵ Further Exploration

N/A

## 📘 Week 5 Exam [ ]


### 🚅 Outlines

* tbc

### ❔ Questions

* tbc

### ❗ Quiz summary

N/A

### ⛵ Further Exploration

N/A
