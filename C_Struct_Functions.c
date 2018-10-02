#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define limit 20

typedef struct
{
    char name[limit];
    char lastname[limit];
    int score;
} student;

void add (student array[], int n)
{
    int i;

    for(i=n; i<n+1; i++)
    {
        printf("\nname of the student: ");
        scanf("%s", &array[i].name);

        printf("\nlastname of the student: ");
        scanf("%s", &array[i].lastname);

        printf("\nscore of the student: ");
        scanf("%d", &array[i].score);
    }
}

void delete (student array[], int n, int search)

    int i, j=0;

    for(i=0; i<n; i++)
    {
        if(i==search-1)
        {
            for(j=i; j<n; j++)
            {
                array[i]=array[i+1];
            }
        }
    }
}

void modify(student array[], int n, int submenu, int list)
{
    int i;

    switch(submenu)
    {

    case 1:

        printf("\nType the name: ");
        scanf("%s", &array[list-1].name);

        break;

    case 2:

        printf("\nType the lastname: ");
        scanf("%s", &array[list-1].lastname);

        break;

    case 3:

        printf("\nType the score: ", 130);
        scanf("%d", &array[list-1].score);

        break;
    }
}

void print (student array[], int n)
{
    int i;
    char name[limit]= {"name"}, lastname[limit]= {"lastname"}, score[limit]= {"score"};

    printf("\n| %c | %-10s | %-10s | %-10s |\n", 35, name, lastname, score);

    for(i=0; i<n; i++)
    {
        printf("\n| %d | %-10s | %-10s | %-10d |\n", i+1, array[i].name, array[i].lastname, array[i].score);
    }
}

void searchGreater (student array[], int n, int greater)
{
    int i;
    char name[limit]= {"name"}, lastname[limit]= {"lastname"}, score[limit]= {"score"};

    printf("\nThe score is:\n");
    printf("\n| %c | %-10s | %-10s | %-10s |\n", 35, score, name, lastname);

    greater=array[0].score;

    for(i=0; i<n; i++)
    {
        if(array[i].score>greater)
        {
            greater=array[i].score;
            printf("\n| %d | %-10d | %-10s | %-10s |\n", i+1, greater, array[i].name, array[i].lastname);
        }
    }
}

void searchLesser (student array[], int n, int lesser)
{
    int i;
    char name[limit]= {"name"}, lastname[limit]= {"lastname"}, score[limit]= {"score"};

    printf("\nLa lesser score es:\n");
    printf("\n| %c | %-10s | %-10s | %-10s |\n", 35, score, name, lastname);

    lesser=array[0].score;

    for(i=0; i<n; i++)
    {
        if(array[i].score<lesser)
        {
            lesser=array[i].score;
            printf("\n| %d | %-10d | %-10s | %-10s |\n", i+1, lesser, array[i].name, array[i].lastname);
        }
    }
}

void searchAverage (student array[], int n, int average)
{
    int i;

    for(i=0; i<n; i++)
    {
        if (array[i].score>0)
        {
            average+=array[i].score;
        }
    }

    average/=n;

    printf("\nThe average score is: %d\n", average);
}

void compare (student array[], int n, int average)
{
    int i;
    char name[limit]= {"name"}, lastname[limit]= {"lastname"}, score[limit]= {"score"};

    for(i=0; i<n; i++)
    {
        if (array[i].score>0)
        {
            average+=array[i].score;
        }
    }

    average/=n;

    printf("\nThe scores greaters than the average are:\n");
    printf("\n| %c | %-10s | %-10s | %-10s |\n", 35, score, name, lastname);

    for(i=0; i<n; i++)
    {
        if(array[i].score>average)
        {
            printf("\n| %d | %-10d | %-10s | %-10s |\n", i+1, array[i].score, array[i].name, array[i].lastname);
        }
    }
}

void searchLesserAverage (student array[], int n, int average) //Funcion para search las scores lesseres del average de los students
{
    int i;
    char name[limit]= {"name"}, lastname[limit]= {"lastname"}, score[limit]= {"score"};

    for(i=0; i<n; i++)
    {
        if (array[i].score>0)
        {
            average+=array[i].score;
        }
    }

    average/=n;

    printf("\nThe scores lessers than the average are:\n");
    printf("\n| %c | %-10s | %-10s | %-10s |\n", 35, score, name, lastname);

    for(i=0; i<n; i++)
    {
        if(array[i].score<average)
        {
            printf("\n| %d | %-10d | %-10s | %-10s |\n", i+1, array[i].score, array[i].name, array[i].lastname);
        }
    }
}

int compare(char from[], char to[])
{
    int i = 0;

    while (from[i] != '\0' && to[i] != '\0')
    {
        if(from[i] > to[i])
        {
            return 1;
        }

        if(from[i] < to[i])
        {
            return 0;
        }

        i++;
    }
    return -1;
}

void oederNeme(student array[], int n)
{
    student aux;

    int i, j, r=0, k;
    char name[limit]= {"name"}, lastname[limit]= {"lastname"}, score[limit]= {"score"};

    for (i = 0; i <n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            r = compare(array[i].name, array[j].name);

            if (r == 1 )
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }

    printf("\n| %c | %-10s | %-10s | %-10s |\n", 35, name, lastname, score);

    for(k=0; k<n; k++)
    {
        printf("\n| %d | %-10s | %-10s | %-10d |\n", k+1, array[k].name, array[k].lastname, array[k].score);
    }
}

void orderLastname(student array[], int n)
{
    student aux;

    int i, j, r=0, k;
    char name[limit]= {"name"}, lastname[limit]= {"lastname"}, score[limit]= {"score"};

    for (i = 0; i <n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            r = compare(array[i].lastname, array[j].lastname);

            if (r == 1 )
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }

    printf("\n| %c | %-10s | %-10s | %-10s |\n", 35, name, lastname, score);

    for(k=0; k<n; k++)
    {
        printf("\n| %d | %-10s | %-10s | %-10d |\n", k+1, array[k].name, array[k].lastname, array[k].score);
    }
}

void orderScore(student array[], int n)
{
    student aux;

    int i, j, r=0, k;
    char name[limit]= {"name"}, lastname[limit]= {"lastname"}, score[limit]= {"score"};

    for (i = 0; i <n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            r = compare(array[i].score, array[j].score);

            if (r == 1 )
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }

    printf("\n| %c | %-10s | %-10s | %-10s |\n", 35, name, lastname, score);

    for(k=0; k<n; k++)
    {
        printf("\n| %d | %-10s | %-10s | %-10d |\n", k+1, array[k].name, array[k].lastname, array[k].score);
    }
}

int main()
{
    int menu, n=0, submenu, list, greater=0, lesser=0, average=0, search=0;

    student array[limit];
    do
    {
        printf("\n1. add.\n");
        printf("\n2. delete.\n");
        printf("\n3. modify.\n");
        printf("\n4. list.\n");
        printf("\n5. greater score.\n");
        printf("\n6. lesser score.\n");
        printf("\n7. average.\n")
        printf("\n8. average greater.\n");
        printf("\n9. average lesser.\n");
        printf("\n10. order by name.\n");
        printf("\n11. oder by lastname.\n");
        printf("\n12. oder by score.\n");
        printf("\n13. exit.\n");
        printf("\nchoose an option: : ");
        scanf("%d", &menu);

        switch(menu)
        {
        case 1:

            add(array, n);
            n++;
            print(array, n);

            printf("\n");
            system("pause");
            system("cls");

            break;


        case 2:

            print(array, n);
            printf("\n");
            printf("\nType the number of the student: ");
            scanf("%d", &search);

            delete(array, n, search);
            n--;
            print(array, n);

            printf("\n");
            system("pause");
            system("cls");

            break;


        case 3:

            print(array, n);
            printf("\n");
            printf("Type the number of the student: ");
            scanf("%d", &list);

            printf("\n1. modify name.\n");
            printf("\n2. modify lastname.\n");
            printf("\n3. modify score.\n");
            printf("\nchoose an option: : ");
            scanf("%d", &submenu);

            modify(array, n, submenu, list);
            print(array, n);

            printf("\n");
            system("pause");
            system("cls");

            break;

        case 4:

            print(array, n);

            printf("\n");
            system("pause");
            system("cls");

            break;
            char name[limit]= {"name"}, lastname[limit]= {"lastname"}, score[limit]= {"score"};
        case 5:

            searchGreater(array, n, greater);

            printf("\n");
            system("pause");
            system("cls");

            break;

        case 6:

            searchLesser(array, n, lesser);

            printf("\n");
            system("pause");
            system("cls");

            break;

        case 7:

            searchAverage(array, n, average);

            printf("\n");
            system("pause");
            system("cls");

            break;

        case 8:

            compare (array, n, average);

            printf("\n");
            system("pause");
            system("cls");

            break;

        case 9:

            searchLesserAverage (array, n, average);

            printf("\n");
            system("pause");
            system("cls");

            break;

        case 10:

            oederNeme(array, n);

            printf("\n");
            system("pause");
            system("cls");

            break;


        case 11:

            orderLastname(array, n);

            printf("\n");
            system("pause");
            system("cls");

            break;


        case 12:

            orderScore(array, n);

            printf("\n");
            system("pause");
            system("cls");

            break;

        case 13:
            return 0;
        }

    }
    while(menu!=11);

    return 0;
}
