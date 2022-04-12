# Week 1 Learning Log

This note contains takeaways in week 1's videos and homework.

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
 
 
 
    

### ❗ Homework summary

* ⤴️ Vector
    * **Initialisation**  
     1. Pushing value one by one  
        ```
        // CPP program to create an empty vector
        // and push values one by one.
        #include <iostream>
        #include <vector>
        using namespace std;

        int main()
        {
            // Create an empty vector
            vector<int> vect;

            vect.push_back(10);
            vect.push_back(20);
            vect.push_back(30);

            for (int x : vect)
                cout << x << " ";

            return 0;
        }
        ```
     2. Specifying size and Initialising all values  
        ```   
        // CPP program to create an empty vector
        // and push values one by one.
        #include <iostream>
        #include <vector>
        using namespace std;

        int main()
        {
            int n = 3;

            // Create a vector of size n with
            // all values as 10.
            vector<int> vect(n, 10);

            for (int x : vect)
                cout << x << " ";

            return 0;
        }
        ```
     3. Initialising like arrays  
        ```
        // CPP program to initialize a vector like
        // an array.
        #include <iostream>
        #include <vector>
        using namespace std;

        int main()
        {
            vector<int> vect{ 10, 20, 30 };

            for (int x : vect)
                cout << x << " ";

            return 0;
        }
        ```
     4. Initialsing(Converting) from an Array  
        ```
        // CPP program to initialize a vector from
        // an array.
        #include <iostream>
        #include <vector>
        using namespace std;

        int main()
        {
            int arr[] = { 10, 20, 30 };
            int n = sizeof(arr) / sizeof(arr[0]);

            vector<int> vect(arr, arr + n);

            for (int x : vect)
                cout << x << " ";

            return 0;
        }
        ```
     5. Initialising all elements with a particular value
        ```
        #include <iostream>
        #include <vector>
        using namespace std;

        int main()
        {
            vector<int> vect1(10);
            int value = 5;
            fill(vect1.begin(), vect1.end(), value);
            for (int x : vect1)
                cout << x << " ";
        }
        ```

    * **Conversion**
     1. ```std::begin``` & ```std::end``` functions that return an iterator pointing to the beginning and the end of a sequence  
        ```
        #include <iostream>
        #include <vector>

        int main()
        {
            // input array
            int src[] = { 1, 2, 3, 4, 5 };

            std::vector<int> dest(std::begin(src), std::end(src));
            for (int i: dest) {
                std::cout << i << " ";
            }

            return 0;
        }
        ```
     2. Naive solution: Using ```for```statement to add values to the vector one at a time  
        ```
        #include <iostream>
        #include <vector>

        int main()
        {
            // input array
            int src[] = { 1, 2, 3, 4, 5 };

            // create an empty vector and push all elements
            std::vector<int> dest;
            for (int i: src) {
                dest.push_back(i);
            }

            for (int i: dest) {
                std::cout << i << " ";
            }

            return 0;
        }
        ``` 
     3. Using std::insert function  
        ```
        #include <iostream>
        #include <vector>

        int main()
        {
            // input array
            int src[] = { 1, 2, 3, 4, 5 };

            std::vector<int> dest;
            dest.insert(dest.begin(), std::begin(src), std::end(src));

            for (int i: dest) {
                std::cout << i << " ";
            }

            return 0;
        }
        ```
    
    * **Accumulation**
    ```
    using namespace std;
    int sum = 0;
    ```
     1. Classic ```for``` statement  
        ```
        for( vector<int>::iterator it = vector.begin(); it != vector.end(); ++it )
            sum += *it;
        ```
     2. a. Using a standard algorithm
        ```
        #include <numeric>
        sum = accumulate(vector.begin(), vector.end(), 0);
        ```  
        Note:  
        0 will accumulate for integers even if the vector has float  
        0.0 or 0.0f will do for floating-point numbers

     3. b. Automatically keeping track of the vector type even in case of future changes
        ```
        #include <numeric>
        sum = accumulate(vector.begin(), vector.end(), decltype(vector)::value_type(0));
        ```
     4. Using a range-based ```for``` statement
        ```
        for (auto& n: vector)
            sum += n;
        ```
    
    * **Passing vector to a function in C++**
     1. Pass-by-value: only the copy of vector is changed; the original stays the same
        ```
        using namespace std;

        // The vect here is a copy of vect in main()
        inline void func(vector<int> vect) { vect.push_back(30); }

        int main()
        {
            vector<int> vect;
            vect.push_back(10);
            vect.push_back(20);

            func(vect);

            // vect remains unchanged after function
            // call
            for (int i = 0; i < vect.size(); i++)
                cout << vect[i] << " ";

            return 0;
        }
        ```
        Output  
        ```
        10 20
        ```
     2. Pass-by-reference
        ```
        using namespace std;

        // The vect is passed by reference and changes
        // made here reflect in main()
        inline void func(vector<int>& vect) { vect.push_back(30); }

        int main()
        {
            vector<int> vect;
            vect.push_back(10);
            vect.push_back(20);

            func(vect);

            for (int i = 0; i < vect.size(); i++)
                cout << vect[i] << " ";

            return 0;
        }
        ```
        Output  
        ```
        10 20 30
        ```
     3. To ensure the vector is locked
        ```
        using namespace std; 

        // The vect is passed by constant reference 
        // and cannot be changed by this function. 
        void func(const vector<int> &vect) 
        { 
            // vect.push_back(30);   // Uncommenting this line would 
                                    // below error 
            // "prog.cpp: In function 'void func(const std::vector<int>&)': 
            // prog.cpp:9:18: error: passing 'const std::vector<int>' 
            // as 'this' argument discards qualifiers [-fpermissive]" 

            for (int i = 0; i < vect.size(); i++) 
            cout << vect[i] << " "; 
        } 

        int main() 
        { 
            vector<int> vect; 
            vect.push_back(10); 
            vect.push_back(20); 

            func(vect); 

            return 0; 
        }
        ```
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
