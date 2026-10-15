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

void link_parents(Person *child, Person *father, Person *mother)
{
    child->father = father;
    child->mother = mother;
}

void print_family_relationships(const Person *me)
{
    printf("\n=== FAMILY TREE RELATIONSHIPS ===\n\n");

    printf("1. YOURSELF:\n");
    printf("   - Name: %s | Age: %d\n\n", me->name, me->age);

    printf("2. PARENTS:\n");
    printf("   - Father: %s | Age: %d\n", me->father->name, me->father->age);
    printf("   - Mother: %s | Age: %d\n\n", me->mother->name, me->mother->age);

    printf("3. PATERNAL GRANDPARENTS:\n");
    printf("   - Grandfather: %s | Age: %d\n",
           me->father->father->name, me->father->father->age);
    printf("   - Grandmother: %s | Age: %d\n\n",
           me->father->mother->name, me->father->mother->age);

    printf("4. MATERNAL GRANDPARENTS:\n");
    printf("   - Grandfather: %s | Age: %d\n",
           me->mother->father->name, me->mother->father->age);
    printf("   - Grandmother: %s | Age: %d\n",
           me->mother->mother->name, me->mother->mother->age);
}
void free_family_tree(Person *people[], int count)
{
    
    for (int i = count - 1; i >= 0; i--)
    {
        free(people[i]);
        people[i] = NULL;
    }
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


    link_parents(people[4], people[0], people[1]);  
    link_parents(people[5], people[2], people[3]); 
    link_parents(people[6], people[4], people[5]);  
    print_family_relationships(people[6]);
    printf("\n");
    free_family_tree(people,7);

    return 0;
}