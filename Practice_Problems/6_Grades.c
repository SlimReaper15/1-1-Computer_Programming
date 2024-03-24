#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Grade {A,Am,B,Bm,C,Cm} Grade;

typedef struct Student {
  char email[100];
  int assigment1;
  int assigment2;
  int midsem;
  int endsem;
  Grade grade;
} Student;

typedef struct Database {
  Student students[300];
  int count_students;
} Database;

float compute_total_marks(Student s) {
/* Problem 2.1: write code here, for computing the 
total marks for a student and returning it. 
Assume that
assignment marks were out of 100, midsem marks 
were out of 50 and endsem marks were out of 80. 
The best 1 score amoung the 2 assignments will 
only be taken. The weightage for the total marks 
is 30% from assignment, 30% from midsem and 40% 
from endsem. (2 marks)
*/
    int assignment = (s.assigment1 > s.assigment2) ? s.assigment1 : s.assigment2;
    float a = (1.0 * assignment / 100);
    float m = (1.0 * s.midsem / 50);
    float e = (1.0 * s.endsem / 80);

    float total = (a * 30 + m * 30 + e * 40);

    return total;
}

void compute_grades(Database* db) {
/* Problem 2.2: Assume that grades are given as 
follows: >= 90: A, between 90 and 80: Am,
between 70 and 80: B, between 60 and 70: Bm,
between 50 and 60: C, between 40 and 50: Cm.
Write code here to assign grades to each 
student, and save it in the `grade` field of the
`Student`. (2 marks)
*/
    for (int i = 0; i < db -> count_students; i++) {
        float marks = compute_total_marks(db -> students[i]);
        if (marks >= 90)
            db -> students[i].grade = A;
        else if (marks >= 80)
            db -> students[i].grade = Am;
        else if (marks >= 70)
            db -> students[i].grade = B;
        else if (marks >= 60)
            db -> students[i].grade = Bm;
        else if (marks >= 50)
            db -> students[i].grade = C;
        else if (marks >= 40)
            db -> students[i].grade = Cm;
    }
}

int main(int argc, char* argv[]) {
  Database db;
  /* Problem 2.3: Suppose the a.out is run with the 
  first argument as the name of the `.csv` file. 
  For example `./a.out marks.csv`. Write code here, 
  that will read all the data from the `.csv` file 
  and populate the Database `db`.  (3 marks)
  */
 FILE *f = fopen(argv[1], "r");
 char c;
 int l = 1;
 while ((c = fgetc(f)) != EOF) {
    if (c == '\n')
        l++;
 }
 db.count_students = l;
 rewind(f);

 for (int i = 0; i < l; i++)
    fscanf(f, "%s %d %d %d %d", db.students[i].email, &db.students[i].assigment1, &db.students[i].assigment2, &db.students[i].midsem, &db.students[i].endsem);

  compute_grades(&db);

  /* Problem 2.4: Suppose the a.out is run with the 
  second argument as the name of the `.csv` file for 
  grades. 
  For example `./a.out marks.csv grades.csv`. 
  Write code here, open the file with name given by
  second argument, and write the grades.  (3 marks)
  */
  FILE *out = fopen(argv[2], "w");

  for (int i = 0; i < l; i++)
    fprintf(out, "%s %f %d\n", db.students[i].email, compute_total_marks(db.students[i]), db.students[i].grade);
}