/* ##############################################################################################
 * Author:     J-D-J123
 * Date:       2/19/2025
 * Desc:       this is the main lab file that will implement all methods as well be what is graded 
                 (only for prelab4)
 ################################################################################################ 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

// arraySize is the size of the array (static)
static int arraySize = 0; 

Employee *readEmployeeArray(FILE *fp) {

    if (fp == NULL) {
        return NULL; 
    }
    
    // if the number at the top of the file DNE return null 
    if (fscanf(fp, "%d", &arraySize) != 1) {
        return NULL; 
    }
    
    // make the storage of all employees as well as the size of all the employees so sizeof(Employee)*arraySize + sizeof(int) 
    Employee *employees = malloc(arraySize*sizeof(Employee) + sizeof(int));

    // store the size of the array in the first value aka 0 or -1
    *((int*)employees) = arraySize;

    // increase the pointer by 1 so then the size is hidden 
    // employees++; 
    employees = (Employee*)((int*)employees + 1);
    
    // for loop to save the employee info by reading the file using fp
    for (int i = 0; i < *((int*)employees - 1); i++) {

        fscanf(fp, "%d %d %f",  &employees[i].empID, 
                                &employees[i].jobType, 
                                &employees[i].salary);
    }

    return employees;

}

/* Returns a pointer to the Employee with the given empID, or NULL if not found. */
Employee *getEmployeeByID(Employee *employees, int empID) {

    int count = 0; 

    for(int i = 0; i < *((int*)employees - 1); i++) {

        if(empID == employees[i].empID) {
            return (employees + count); 
        }
        count++;
    }

    return NULL;  

}

/**
 * the getSize array returns the size of the employee array 
 */
int getSize(Employee * employees) {
    return *((int*)employees - 1); 
}

int setEmpSalary(Employee *employees, int empID, float salary) {

    int size = *((int*)employees-1);

    for(int i = 0; i < size; i++) {

        if(empID == employees[i].empID) {

            employees[i].salary = salary; 
            return 0; 
        }
    }
    return 1; 
}

/**
 * the function getEmpSalary gets the salary of the employee by using employee ID
 *  returns the salary and returns 1 if there is an error 
 */
int getEmpSalary(Employee *employees, int empID) {

    int size = *((int*)employees-1); 

    for(int i = 0; i < size; i++) {

        if(employees[i].empID == empID) {

            return employees[i].salary; 
        }
    }
    return 1; 
}

/**
 * the setEmpJobType sets the job type of the employee 
 */
int setEmpJobType(Employee *employees, int empID, int job) {

    int size = *((int*)employees-1); 

    for(int i = 0; i < size; i++) {

        if(employees[i].empID == empID) {
            
            employees[i].jobType = job; 
            return 0; 
        }
    }
    return 1; 
}

/**
 * the getEmpJobType returns the jobType integer of the employee 
 */
int getEmpJobType(Employee * employees, int empID) {

    int size = *((int*)employees-1); 

    for(int i = 0; i < size; i++) {

        if(employees[i].empID == empID) {
            
            return employees[i].jobType; 
            return 0; 
        }
    }
    return 1; 
}

void freeArray(Employee *employees) {

    if (employees != NULL) {
        free((int*)employees - 1); // Move back to the original allocated block and free
        employees = NULL; // Nullify the pointer after freeing
    }
}
