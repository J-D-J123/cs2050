/* ##############################################################################################
 * Author:     J-D-J123
 * Date:       2/19/2025
 * File:       tester4.c 
 * Desc:       this is the tester file to be used to test lab4.c will try to test all cases possible 
                 (only for prelab4)
 ################################################################################################ 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

int main(void) {
    FILE *fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        printf("Error opening employees.txt\n");
        return 1;
    }
    
    Employee *employees = readEmployeeArray(fp);
    fclose(fp);
    
    if (employees == NULL) {
        printf("Error reading employee data.\n");
        return 1;
    }

    printf("Employee Array by ID:\n");
    printf("size: [%d]: ", getSize(employees));
    for(int i = 0; i < getSize(employees); i++) {
        printf("[%d] ", employees[i].empID);
    }
    printf("\n");
    
    int size = getSize(employees);
    printf("Number of employees: %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("Employee %d: ID: %d, Job Type: %d, Salary: %.2f\n", 
               i + 1, employees[i].empID, employees[i].jobType, employees[i].salary);
    }
    
    int searchID = 102;
    Employee *emp = getEmployeeByID(employees, searchID);
    if (emp != NULL) {
        printf("\nFound employee with ID %d: Job Type: %d, Salary: %.2f\n", 
               emp->empID, emp->jobType, emp->salary);
    } else {
        printf("\nEmployee with ID %d not found.\n", searchID);
    }
    
    float newSalary = 65000.00;
    if (setEmpSalary(employees, searchID, newSalary) == 0) {
        float retrievedSalary = getEmpSalary(employees, searchID);
        printf("After update, employee %d salary: %.2f\n", searchID, retrievedSalary);
    } else {
        printf("Error setting salary for employee %d.\n", searchID);
    }
    
    int newJobType = 3;
    if (setEmpJobType(employees, searchID, newJobType) == 0) {
        int retrievedJob = getEmpJobType(employees, searchID);
        printf("After update, employee %d job type: %d\n", searchID, retrievedJob);
    } else {
        printf("Error setting job type for employee %d.\n", searchID);
    }
    
    int nonExistID = 999;
    if (getEmpSalary(employees, nonExistID) == 1)
        printf("Employee with ID %d not found for salary retrieval.\n", nonExistID);
    if (getEmpJobType(employees, nonExistID) == 1)
        printf("Employee with ID %d not found for job type retrieval.\n", nonExistID);
    
    freeArray(employees);
    return 0;
}

