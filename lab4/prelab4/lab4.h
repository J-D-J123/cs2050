/* ##############################################################################################
 * Author:     J-D-J123
 * Date:       2/19/2025
 * Desc:       this is the header file to be used in the lab4.c file as well as the tester file 
                 (only for prelab4)
 ################################################################################################ 
 */

#ifndef LAB4_H
#define LAB4_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int empID;
    int jobType;
    float salary;
} Employee;

/* Reads an array of Employee records from the given file.
   The first integer in the file indicates the number of records.
   Returns a pointer to the allocated Employee array or NULL on error. */
Employee *readEmployeeArray(FILE *fp);

/* Returns a pointer to the Employee with the given empID, or NULL if not found. */
Employee *getEmployeeByID(Employee *employees, int empID);

/* Setter and getter functions for salary and job type.
   They return 0 on success and 1 on error (e.g., if the employee isn’t found). */
int setEmpSalary(Employee *employees, int empID, float salary);
int getEmpSalary(Employee *employees, int empID, float *salary);
int setEmpJobType(Employee *employees, int empID, int job);
int getEmpJobType(Employee *employees, int empID, int *job);

/* Returns the number of Employee records read from the file. */
int getSize(void);

/* Frees the allocated Employee array. */
void freeArray(Employee *employees);

#endif
