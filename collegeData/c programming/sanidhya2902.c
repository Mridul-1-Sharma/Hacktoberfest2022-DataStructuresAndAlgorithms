#include <stdio.h>
#include <string.h>

struct student
{
    int rollNo;
    char name[15];
    char branch[20];
    int marks;
    float cgpa;
};

struct faculty
{
    int id;
    char name[15];
    char dept[20];
};

int main()
{

    struct student stu[5];
    struct faculty fact[5];

    // for student 1
    printf("\nEnter roll no. of student 1: ");
    scanf("%d", &stu[0].rollNo);
    printf("Enter name of student 1: ");
    scanf("%s", &stu[0].name);
    printf("Enter branch of student 1: ");
    scanf("%s", &stu[0].branch);
    printf("Enter marks for student 1: ");
    scanf("%d", &stu[0].marks);

    // for student 2
    printf("\nEnter roll no. of student 2: ");
    scanf("%d", &stu[1].rollNo);
    printf("Enter name of student 2: ");
    scanf("%s", &stu[1].name);
    printf("Enter branch of student 2: ");
    scanf("%s", &stu[1].branch);
    printf("Enter marks for student 2: ");
    scanf("%d", &stu[1].marks);

    // for student 3
    printf("\nEnter roll no. of student 3: ");
    scanf("%d", &stu[2].rollNo);
    printf("Enter name of student 3: ");
    scanf("%s", &stu[2].name);
    printf("Enter branch of student 3: ");
    scanf("%s", &stu[2].branch);
    printf("Enter marks for student 3: ");
    scanf("%d", &stu[2].marks);

    // for student 4
    printf("\nEnter roll no. of student 4: ");
    scanf("%d", &stu[3].rollNo);
    printf("Enter name of student 4: ");
    scanf("%s", &stu[3].name);
    printf("Enter branch of student 4: ");
    scanf("%s", &stu[3].branch);
    printf("Enter marks for student 4: ");
    scanf("%d", &stu[3].marks);

    // for student 5
    printf("\nEnter roll no. of student 5: ");
    scanf("%d", &stu[4].rollNo);
    printf("Enter name of student 5: ");
    scanf("%s", &stu[4].name);
    printf("Enter branch of student 5: ");
    scanf("%s", &stu[4].branch);
    printf("Enter marks for student 5: ");
    scanf("%d", &stu[4].marks);

    // printing data for students
    printf("\nRoll no. of student 1 is %d\n", stu[0].rollNo);
    printf("Name of student 1 is %s\n", stu[0].name);
    printf("Branch of student 1 is %s\n", stu[0].branch);
    printf("Marks of student 1 is %d\n", stu[0].marks);

    printf("\nRoll no. of student 2 is %d\n", stu[1].rollNo);
    printf("Name of student 2 is %s\n", stu[1].name);
    printf("Branch of student 2 is %s\n", stu[1].branch);
    printf("Marks of student 2 is %d\n", stu[1].marks);

    printf("\nRoll no. of student 3 is %d\n", stu[2].rollNo);
    printf("Name of student 3 is %s\n", stu[2].name);
    printf("Branch of student 3 is %s\n", stu[2].branch);
    printf("Marks of student 3 is %d\n", stu[2].marks);

    printf("\nRoll no. of student 4 is %d\n", stu[3].rollNo);
    printf("Name of student 4 is %s\n", stu[3].name);
    printf("Branch of student 4 is %s\n", stu[3].branch);
    printf("Marks of student 4 is %d\n", stu[3].marks);

    printf("\nRoll no. of student 5 is %d\n", stu[4].rollNo);
    printf("Name of student 5 is %s\n", stu[4].name);
    printf("Branch of student 5 is %s\n", stu[4].branch);
    printf("Marks of student 5 is %d\n", stu[4].marks);

    // for faculty 1
    printf("\nEnter id of faculty 1: ");
    scanf("%d", &fact[0].id);
    printf("Enter name of faculty 1: ");
    scanf("%s", &fact[0].name);
    printf("Enter department of faculty 1: ");
    scanf("%s", &fact[0].dept);

    // for faculty 2
    printf("\nEnter id of faculty 2: ");
    scanf("%d", &fact[1].id);
    printf("Enter name of faculty 2: ");
    scanf("%s", &fact[1].name);
    printf("Enter department of faculty 2: ");
    scanf("%s", &fact[1].dept);

    // for faculty 3
    printf("\nEnter id of faculty 3: ");
    scanf("%d", &fact[2].id);
    printf("Enter name of faculty 3: ");
    scanf("%s", &fact[2].name);
    printf("Enter department of faculty 3: ");
    scanf("%s", &fact[2].dept);

    // for faculty 4
    printf("\nEnter id of faculty 4: ");
    scanf("%d", &fact[3].id);
    printf("Enter name of faculty 4: ");
    scanf("%s", &fact[3].name);
    printf("Enter department of faculty 4: ");
    scanf("%s", &fact[3].dept);

    // for faculty 5
    printf("\nEnter id of faculty 5: ");
    scanf("%d", &fact[4].id);
    printf("Enter name of faculty 5: ");
    scanf("%s", &fact[4].name);
    printf("Enter department of faculty 5: ");
    scanf("%s", &fact[4].dept);

    // printing data for faculty
    printf("\nId of faculty 1 is %d\n", fact[0].id);
    printf("Name of facylty 1 is %s\n", fact[0].name);
    printf("Department of faculty 1 is %s\n", fact[0].dept);

    printf("\nId of faculty 2 is %d\n", fact[1].id);
    printf("Name of facylty 2 is %s\n", fact[1].name);
    printf("Department of faculty 2 is %s\n", fact[1].dept);

    printf("\nId of faculty 3 is %d\n", fact[02].id);
    printf("Name of facylty 3 is %s\n", fact[2].name);
    printf("Department of faculty 3 is %s\n", fact[2].dept);

    printf("\nId of faculty 4 is %d\n", fact[3].id);
    printf("Name of facylty 4 is %s\n", fact[3].name);
    printf("Department of faculty 4 is %s\n", fact[3].dept);

    printf("\nId of faculty 5 is %d\n", fact[4].id);
    printf("Name of facylty 5 is %s\n", fact[4].name);
    printf("Department of faculty 5 is %s\n", fact[4].dept);

    return 0;
} 
