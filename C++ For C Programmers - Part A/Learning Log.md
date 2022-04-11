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
      using namespace std; // context capsulation
      const int sides = 6; // replaces many sharp defines
      inline int r_side(){ return (rand() % sides + 1); }
      ```
      inline - compiler directive
      function - cost me money, runtime...
* 4️⃣ C++ Improvements
  * namespace/context
    
    ```
    std::cout << "\nEnte...";
    cout << "\nEnte...";
    ```
    '<<': bit shift
* 5️⃣ C++ Advantages [12-04-2022]
* 
### ❔ Questions

* Quiz - Object
  * Object-oriented: Data and operations are bound together, type expansivity
    
    Shoule be comfortable with recursion
    
    Type safety is a property of a good OO language
    
    

### ❗ Quiz summary

N/A

### ⛵ Further Exploration

N/A

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
