/*  2. Define a structure of employee having data members name, address, 
    age and salary. Take data for n employee in an array and find the 
    average salary. */

#include<stdio.h>
#include<string.h>

struct employee{
    char name[50];
    char address[50];
    int age;
    float salary;
};

int main() {
    int n;
    float TotalSalery = 0;

    printf("Enter numbers of employee: ");
    scanf("%d", &n);
    getchar();

    struct employee Employee[n];

   
    for(int i = 0; i < n; i++){
        printf("\nPlease Enter details for employee %d\n", i + 1);

        printf("Name: ");
        fgets(Employee[i].name, sizeof(Employee[i].name), stdin);
        Employee[i].name[strcspn(Employee[i].name, "\n")] = '\0'; 

        printf("Address: ");
        fgets(Employee[i].address, sizeof(Employee[i].address), stdin);
        Employee[i].address[strcspn(Employee[i].address, "\n")] = '\0';

        printf("Age: ");
        scanf("%d", &Employee[i].age);
        getchar();

        printf("Salary: ");
        scanf("%f", &Employee[i].salary);
        getchar();

        TotalSalery += Employee[i].salary;
    }


    float AverageSalary = TotalSalery / n;

    printf("\nAvrage Salery = %.2f ", AverageSalary);
    return 0;
}