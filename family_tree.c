#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person *create_person(const char *name, int age)
{
    Person *s = malloc(sizeof(Person));
    if ( s == NULL )
    {
        return NULL ;
    }
    strcpy(s->name, name);                                   
    s->age = age;
    s->father = NULL;
    s->mother = NULL;
    return s ;
}

int main(void)
{
    Person *people[7];
    char name[50];
    int age;

    printf("Enter name for Paternal Grandfather: ");
    scanf("%49s", name);

    printf("Enter age for Paternal Grandfather: ");
    scanf("%d", &age);

    people[0] = create_person(name, age);

    printf("Enter name for Paternal Grandmother: ");
    scanf("%49s", name);

    printf("Enter age for Paternal Grandmother: ");
    scanf("%d", &age);

    people[1] = create_person(name, age);

    printf("Enter name for Maternal Grandfather: ");
    scanf("%49s", name);

    printf("Enter age for Maternal Grandfather: ");
    scanf("%d", &age);

    people[2] = create_person(name, age);

    printf("Enter name for Maternal Grandmother: ");
    scanf("%49s", name);

    printf("Enter age for Maternal Grandmother: ");
    scanf("%d", &age);

    people[3] = create_person(name, age);

    printf("Enter name for Father: ");
    scanf("%49s", name);

    printf("Enter age for Father: ");
    scanf("%d", &age);

    people[4] = create_person(name, age);

    printf("Enter name for Mother: ");
    scanf("%49s", name);

    printf("Enter age for Mother: ");
    scanf("%d", &age);

    people[5] = create_person(name, age);

    printf("Enter name for Yourself: ");
    scanf("%49s", name);

    printf("Enter age for Yourself: ");
    scanf("%d", &age);

    people[6] = create_person(name, age);

    printf("All the information of your family has been taken.\n");
    

    return 0;
}