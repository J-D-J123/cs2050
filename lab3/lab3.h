#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_GRADES 5
typedef struct {
  char name[50];
  char lastname[50];
  float gpa;
} Student;
int grade_to_index(char grade);
char index_to_grade(int index);
Student** read_students_from_file(const char* filename);
float calculate_average_gpa(Student** jaggedArray, char grade);
int list_students_by_grade(Student** jaggedArray, char grade);
int list_students_above_gpa(Student** jaggedArray, float threshold);
void free_jagged_array(Student*** jaggedArray);
