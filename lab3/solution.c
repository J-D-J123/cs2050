#include "lab3.h"
int grade_to_index(char grade) {
switch (grade) {
case 'A': return 0;
case 'B': return 1;
case 'C': return 2;
case 'D': return 3;
case 'F': return 4;
default: return -1;
}
}
char index_to_grade(int index) {
char grades[] = {'A', 'B', 'C', 'D', 'F'};
return grades[index];
}
Student** read_students_from_file(const char* filename) {
int sizes[5] = {0};
Student** jaggedArray = NULL;
FILE* file = fopen(filename, "r");
if (!file) {
fprintf(stderr, "Unable to open file\n");
return NULL;
// perror("Unable to open file");
// exit(EXIT_FAILURE);
}
jaggedArray = (Student**)malloc(5 * sizeof(Student*));
// Read the number of students per grade from the first line
for (int i = 0; i < NUM_GRADES; i++) {
fscanf(file, "%d", &sizes[i]);
jaggedArray[i] = (Student*)malloc(sizeof(int) + sizes[i] *
sizeof(Student));
*((int*)jaggedArray[i]) = sizes[i];
jaggedArray[i] = (Student*)(((int*)jaggedArray[i]) + 1);
}
char name[50], lastname[50], gradeChar;
float gpa;
int gradeCounts[NUM_GRADES] = {0}; // To keep track of how many students have
been added per grade
// Read student data
while (fscanf(file, "%s %s %c %f", name, lastname, &gradeChar, &gpa) != EOF) {
int index = grade_to_index(gradeChar);
if (index != -1 && gradeCounts[index] < sizes[index]) {
strcpy(jaggedArray[index][gradeCounts[index]].name, name);
strcpy(jaggedArray[index][gradeCounts[index]].lastname, lastname);
jaggedArray[index][gradeCounts[index]].gpa = gpa;
gradeCounts[index]++;
}
}
fclose(file);
return jaggedArray;
}
float calculate_average_gpa(Student** jaggedArray, char grade) {
int index = grade_to_index(grade);
if(jaggedArray == NULL) {
return 0.0;
}
if (index == -1) {
printf("No students with grade %c.\n", grade);
return 0.0;
}
int size = *(((int*)jaggedArray[index]) - 1);
if(jaggedArray[index] == 0) {
printf("No students with grade %c.\n", grade);
return 0.0;
}
float totalGPA = 0.0;
for (int i = 0; i < size; i++) {
totalGPA += jaggedArray[index][i].gpa;
}
return size == 0.0 ? 0.0 : totalGPA/size;
}
int list_students_by_grade(Student** jaggedArray, char grade) {
if(jaggedArray == NULL) {
return 1; // FAILURE;
}
int index = grade_to_index(grade);
if (index == -1) {
printf("No students with grade %c.\n", grade);
return 1; // FAILURE
}
int size = *(((int*)jaggedArray[index]) - 1);
if (size == 0) {
printf("No students with grade %c.\n", grade);
return 1; // FAILURE
}
printf("Students with grade %c:\n", grade);
for (int i = 0; i < size; i++) {
printf("- %s %s, GPA: %.2f\n", jaggedArray[index][i].name,
jaggedArray[index][i].lastname, jaggedArray[index][i].gpa);
}
return 0; // SUCCESS
}
int list_students_above_gpa(Student** jaggedArray, float threshold) {
printf("Students with GPA above %.2f:\n", threshold);
int found = 0;
for (int i = 0; i < NUM_GRADES; i++) {
int size = *(((int*)jaggedArray[i]) - 1);
for (int j = 0; j < size; j++) {
if (jaggedArray[i][j].gpa > threshold) {
printf("- %s %s (%c), GPA: %.2f\n", jaggedArray[i][j].name,
jaggedArray[i][j].lastname, index_to_grade(i), jaggedArray[i][j].gpa);
found = 1;
}
}
}
if (!found) {
printf("No students found above GPA %.2f.\n", threshold);
return 1; // FAILURE
}
return 0; // SUCCESS
}
void free_jagged_array(Student*** jaggedArray) {
// Free allocated memory
if(jaggedArray == NULL) {
return;
}
for (int i = 0; i < NUM_GRADES; i++) {
if((*jaggedArray)[i] != NULL) {
(*jaggedArray)[i] = (Student*)(((int*)((*jaggedArray)[i])) - 1);
free((*jaggedArray)[i]);
// The following line commented out by JimR because it
// is unnecessary since the whole array will be freed below
//(*jaggedArray)[i] = NULL;
}
}
free(*jaggedArray);
*jaggedArray = NULL;
}
