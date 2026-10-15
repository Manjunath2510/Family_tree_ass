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
    printf("Family Tree Program\n");

    return 0;
}
