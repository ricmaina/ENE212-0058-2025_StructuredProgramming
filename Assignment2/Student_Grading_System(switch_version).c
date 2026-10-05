#include <stdio.h>

/*
 * PSEUDOCODE:
 *
 * FUNCTION clear_buffer():
 *   Read and discard characters from input stream until '\n' or EOF.
 *
 * MAIN:
 *   Prompt and read student_count. Exit if invalid.
 *
 *   FOR count = 0 TO student_count - 1:
 *     Prompt and read name, reg_no, marks.
 *     IF any read fails: print error message, CALL clear_buffer(), EXIT with error.
 *
 *     // Determine Grade using SWITCH on integer marks
 *     SWITCH (int)marks:
 *       CASE 70 TO 100: grade = 'A'
 *       CASE 60 TO 69:  grade = 'B'
 *       CASE 50 TO 59:  grade = 'C'
 *       CASE 40 TO 49:  grade = 'D'
 *       DEFAULT:        grade = 'F'
 *
 *     // Determine Pass/Fail Status using SWITCH on integer marks
 *     SWITCH (int)marks:
 *       CASE 40 TO 100: pass_fail = "PASS"
 *       DEFAULT:        pass_fail = "FAIL"
 *
 *     // Display Details
 *     PRINT reg_no, name, grade, and pass_fail status.
 *   END FOR
 *
 *   END PROGRAM
 */

void clear_buffer(void) {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
int main(void)
{
    char name[50];
    char reg_no[20];
    double marks;
    char grade;
    const char *pass_fail;

    unsigned int student_count;

    printf("Enter number of students: ");
    if(scanf("%u", &student_count) != 1){
        printf("Invalid count!\n");
        return 1;
    }
    for(unsigned int count = 0; count < student_count; count++){
        printf("Enter student's name: ");
        if(scanf(" %s", name) != 1) {
           printf("Invalid name!\n");
           clear_buffer();
           return 1;
        }
        printf("Enter student's registration number: ");
        if(scanf(" %s", reg_no) != 1) {
            printf("Invalid reg no.\n");
            clear_buffer();
            return 1;
        }
        printf("Enter student's marks: ");
        if(scanf("%lf", &marks) != 1){
            printf("Invalid marks!\n");
            clear_buffer();
            return 1;
        }
        switch((int)marks){
            case 70 ... 100:
                grade = 'A';
                break;
            case 60 ... 69:
                grade = 'B';
                break;
            case 50 ... 59:
                grade = 'C';
                break;
            case 40 ... 49:
                grade = 'D';
                break;
            default :
                grade = 'F';
                break;
        }
        switch ((int)marks){
            case 40 ... 100:
                pass_fail = "PASS";
                break;
            default :
                pass_fail = "FAIL";
                break;
        }
        printf("\n-----------------------------------------\n");
        printf("\n\t Student Information \t\n");
        printf("\n-----------------------------------------\n");
        printf("\nRegistration number: \t%s\n", reg_no);
        printf("\nName: \t%s\n", name);
        printf("\nGrade: \t%c\n", grade);
        printf("\n %s\n", pass_fail);
        printf("\n-----------------------------------------\n");
    }

    return 0;
}
