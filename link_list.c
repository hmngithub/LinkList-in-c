#include "get_input.c"
#include <stdio.h>
#include <string.h>
typedef struct Person
{
    string name;
    struct Person *next;

} Person;

void de_allocat(Person *p);

int main()
{

    Person *persons = NULL;
    printf("for_add_: 1 __ for_delete_: 2 __ for_update_: 3 _item_count_ 4  __ for_show_value_: 5 __ for_exit_: 0 __\n");
    while (1)
    {
        int input = get_int("enter_the_code: ");
        if (input == 0)
        {
            break;
        }
        else if (input == 1)
        {
            string name = get_string("name: ");
            Person *n = malloc(sizeof(Person));
            n->name = name;
            n->next = persons;
            persons = n;
            printf("Person_added\n");
        }
        else if (input == 2)
        {
            string name = get_string("name: ");
            Person *p = persons;
            Person *pb = NULL;
            Person *pa = persons->next;
            while (1)
            {
                if (p->next == NULL && strcmp(p->name, name) == 0)
                {

                    free(p->name);
                    free(p->next);
                    free(p);
                    printf("deleted...\n");
                    free(name);
                    persons = NULL;
                    break;
                }
                else if (pb == NULL && strcmp(p->name, name) == 0)
                {
                    persons = p->next;
                    free(p->name);
                    free(p);
                    printf("deleted...\n");
                    break;
                }
                else if (p->next == NULL && strcmp(p->name, name) != 0)
                {
                    free(name);
                    printf("not_exist...\n");
                    break;
                }
                else if (strcmp(name, p->name) == 0)
                {

                    pb->next = pa;
                    free(p->name);
                    free(p);
                    printf("deleted...\n");
                    free(name);
                    break;
                }
                else
                {

                    pb = p;
                    p = p->next;
                    pa = p->next;
                }
            }
        }

        else if (input == 3)
        {
            string name = get_string("name: ");
            Person *p = persons;
            while (1)
            {
                if (p->next == NULL && strcmp(p->name, name) != 0)
                {
                    printf("person_not_exist_for_update...\n");
                    break;
                }
                else if (strcmp(p->name, name) == 0)
                {
                    string new_name = get_string("new_name: ");
                    strcpy(p->name, new_name);
                    free(new_name);
                    printf("updated...\n");
                    break;
                }
                else
                {
                    p = p->next;
                }
            }
        }
        else if (input == 4)
        {
            Person *pi = persons;
            int counter = 0;
            if (pi == NULL)
            {
                printf("item_count: %i\n", counter);
            }
            else
            {

                while (1)
                {
                    if (pi->next == NULL)
                    {
                        counter++;
                        break;
                    }
                    else
                    {
                        counter++;
                        Person *pf = pi;
                        pi = pf->next;
                    }
                }
                printf("item_count: %i\n", counter);
            }
        }
        else if (input == 5)
        {
            if (persons == NULL)
            {
                printf("o_item...\n");
            }
            else
            {
                Person *p = persons;
                int count = 1;
                while (1)
                {
                    if (p->next == NULL)
                    {
                        printf("item_%i : %s\n", count, p->name);
                        break;
                    }
                    else
                    {
                        printf("item_%i : %s\n", count, p->name);
                        p = p->next;
                        count++;
                    }
                }
            }
        }
        else
        {
            int input = get_int("enter_the_code: ");
        }
    }
    de_allocat(persons);
}

void de_allocat(Person *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        Person *person = p;
        int counter = 0;
        while (1)
        {
            if (person->next == NULL)
            {
                counter++;
                free(person->name);
                free(person->next);
                free(person);
                break;
            }
            else
            {
                counter++;
                Person *pf = person;
                person = pf->next;
                free(pf->name);
                free(pf);
            }
        }
    }
}
