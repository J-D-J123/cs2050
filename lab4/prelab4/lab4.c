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

/* Static variable to store the size of the employee array */ // -- will edit this out later trust 🙏
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
