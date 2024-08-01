#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

struct NodeName
{
    char *name;
    struct NodeName *next;
};

struct NodeNames *createNames(char *name)
{
    struct NodeName *new = (struct NodeName *)malloc(sizeof(struct NodeName));
    new->name = name;
    new->next = NULL;
    return new;
}

struct Node
{
    int dataInt;
    char *dataChar;
    float dataFloat;
    char *datadate;
    struct Node *next;
    struct Node *prev;
};

struct Node *createInt(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->dataInt = data;
    new->dataChar = NULL;
    new->dataFloat = -1;
    new->datadate = NULL;
    new->next = new;
    new->prev = new;
    return new;
}

struct Node *createChar(const char *data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->dataChar = strdup(data);
    new->dataInt = NULL;
    new->dataFloat = -1;
    new->datadate = NULL;
    new->next = new;
    new->prev = new;
    return new;
}

struct Node *createFloat(float data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->dataFloat = data;
    new->dataInt = NULL;
    new->dataChar = NULL;
    new->datadate = NULL;
    new->next = new;
    new->prev = new;
    return new;
}

struct Node *createDate(const char *data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->datadate = strdup(data);
    new->dataInt = NULL;
    new->dataChar = NULL;
    new->dataFloat = -1;
    new->next = new;
    new->prev = new;
    return new;
}

struct Node *addLastInt(struct Node *head, int data)
{
    struct Node *temp = head;
    struct Node *new = createInt(data);
    if (head == NULL)
    {
        head = new;
        head->next = head;
        head->prev = head;
        return head;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    new->prev = temp;
    head->prev = new;
    return head;
}

struct Node *addLastChar(struct Node *head, const char *data)
{
    struct Node *temp = head;
    struct Node *new = createChar(data);
    if (head == NULL)
    {
        head = new;
        head->next = head;
        head->prev = head;
        return head;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    new->prev = temp;
    head->prev = new;
    return head;
}

struct Node *addLastFloat(struct Node *head, float data)
{
    struct Node *temp = head;
    struct Node *new = createFloat(data);
    if (head == NULL)
    {
        head = new;
        head->next = head;
        head->prev = head;
        return head;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    new->prev = temp;
    head->prev = new;
    return head;
}

struct Node *addLastDate(struct Node *head, const char *data)
{
    struct Node *temp = head;
    struct Node *new = createDate(data);
    if (head == NULL)
    {
        head = new;
        head->next = head;
        head->prev = head;
        return head;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    new->prev = temp;
    head->prev = new;
    return head;
}

struct Node *removeEle(struct Node *head, int row)
{
    struct Node *temp = head;
    struct Node *temp1 = head->next;
    int i = 0;

    if (head == NULL)
    {
        printf("No data exist\n");
        return head;
    }
    if (row == 1)
    {
        struct Node *temp2 = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        head->prev = temp;
        free(temp2);
        return head;
    }

    while (temp1->next != head && i < row - 2)
    {
        temp1 = temp1->next;
        temp = temp->next;
        i++;
    }
    temp->next = temp1->next;
    temp1->next->prev = temp;
    free(temp1);
    return head;
}

void deleterow(struct Node *heads[], int columns, int rows, int row)
{

    for (int i = 0; i < columns; i++)
    {
        heads[i] = removeEle(heads[i], row);
    }
}

struct Node *updateEleInt(struct Node *head, int row, int element)
{
    struct Node *temp = head->next;
    int i = 0;

    if (head == NULL)
    {
        printf("No data exist\n");
        return head;
    }
    if (row == 1)
    {
        head->dataInt = element;
        return head;
    }

    while (temp->next != head && i < row - 2)
    {
        temp = temp->next;
        i++;
    }
    temp->dataInt = element;
    return head;
}

struct Node *updateEleChar(struct Node *head, int row, const char *element)
{
    struct Node *temp = head->next;
    int i = 0;

    if (head == NULL)
    {
        printf("No data exist\n");
        return head;
    }
    if (row == 1)
    {
        head->dataChar = element;
        return head;
    }

    while (temp->next != head && i < row - 2)
    {
        temp = temp->next;
        i++;
    }
    temp->dataChar = element;
    return head;
}

struct Node *updateEleFloat(struct Node *head, int row, float element)
{
    struct Node *temp = head->next;
    int i = 0;

    if (head == NULL)
    {
        printf("No data exist\n");
        return head;
    }
    if (row == 1)
    {
        head->dataFloat = element;
        return head;
    }

    while (temp->next != head && i < row - 2)
    {
        temp = temp->next;
        i++;
    }
    temp->dataFloat = element;
    return head;
}

struct Node *updateEleDate(struct Node *head, int row, const char *element)
{
    struct Node *temp = head->next;
    int i = 0;

    if (head == NULL)
    {
        printf("No data exist\n");
        return head;
    }
    if (row == 1)
    {
        head->datadate = element;
        return head;
    }

    while (temp->next != head && i < row - 2)
    {
        temp = temp->next;
        i++;
    }
    temp->datadate = element;
    return head;
}

void updateRow(struct Node *heads[], int column, int row)
{
    struct Node *temp = heads[column - 1];

    if (temp->dataInt != NULL)
    {
        int n;
        printf("Enter the element to be updated :");
        scanf("%d", &n);
        getchar();
        heads[column - 1] = updateEleInt(temp, row, n);
    }
    else if (temp->dataChar != NULL)
    {
        char *c = (char *)malloc(sizeof(char) * MAX_SIZE);
        printf("Enter the element to be updated :");
        gets(c);
        heads[column - 1] = updateEleChar(temp, row, c);
    }
    else if (temp->dataFloat != -1)
    {
        float f;
        printf("Enter the element to be updated :");
        scanf("%f", &f);
        getchar();
        heads[column - 1] = updateEleFloat(temp, row, f);
    }
    else if (temp->datadate != NULL)
    {
        char *c1 = (char *)malloc(sizeof(char) * MAX_SIZE);
        printf("Enter the element to be update :");
        gets(c1);
        heads[column - 1] = updateEleDate(temp, row, c1);
    }
}

void updateRowDetail(struct Node *heads[], int columns, int rows)
{
    int column;
    printf("Enter the column no.of of the element to be updated :");
    scanf("%d", &column);
    int row;
    printf("Enter the row no.of of the element to be updated :");
    scanf("%d", &row);
    getchar();
    if (column <= columns && row <= rows)
    {
        updateRow(heads, column, row);
    }
    else
    {
        printf("\nCOLUMN OR ROW DOES NOT EXIST\n");
    }
}

void InitiateDB(struct Node *heads[], int columns)
{
    for (int i = 0; i < columns; i++)
    {
        printf("Select the data type of the column %d\n", i + 1);
        printf("1.Integer\n");
        printf("2.Varying Character\n");
        printf("3.Floating point\n");
        printf("4.Date\n");

        int choice;
        printf("Enter the choice for the data type:");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
        {
            int data1;
            printf("Enter the First Integer data of the column %d:", i + 1);
            scanf("%d", &data1);
            getchar();
            heads[i] = createInt(data1);
            break;
        }
        case 2:
        {
            char *data2 = (char *)malloc(MAX_SIZE * sizeof(char));
            printf("Enter the First Varchar data of the column %d:", i + 1);
            gets(data2);
            heads[i] = createChar(data2);
            break;
        }
        case 3:
        {
            float data3;
            printf("Enter the First Floating point data of the column %d:", i + 1);
            scanf("%f", &data3);
            getchar();
            heads[i] = createFloat(data3);
            break;
        }
        case 4:
        {
            char *date = (char *)malloc(MAX_SIZE * sizeof(char));
            printf("Enter the First date data of the column %d:", i + 1);
            gets(date);
            heads[i] = createDate(date);
            break;
        }
        }
    }
}

struct NodeName *getColumnNames(int columns)
{
    struct NodeName *current = NULL;
    struct NodeName *head = NULL;
    for (int i = 0; i < columns; i++)
    {
        printf("Enter the name of the column %d:", i + 1);
        char *name = (char *)malloc(sizeof(char) * MAX_SIZE);
        gets(name);

        struct NodeName *new = createNames(name);

        if (head == NULL)
        {
            head = new;
            current = head;
        }
        else
        {
            current->next = new;
            current = new;
        }
    }
    current->next = head;
    return head;
}

void addRow(struct Node *heads[], int columns)
{
    for (int i = 0; i < columns; i++)
    {
        if (heads[i]->dataInt != NULL)
        {
            int n;
            printf("Enter the data for the %d column :", i + 1);
            scanf(" %d", &n);
            getchar();
            heads[i] = addLastInt(heads[i], n);
        }
        else if (heads[i]->dataChar != NULL)
        {
            char *new = (char *)malloc(sizeof(char) * MAX_SIZE);
            printf("Enter the data for the %d column :", i + 1);
            getchar();
            gets(new);
            heads[i] = addLastChar(heads[i], new);
        }
        else if (heads[i]->dataFloat != -1)
        {
            float num;
            printf("Enter the data for the %d column :", i + 1);
            scanf(" %f", &num);
            getchar();
            heads[i] = addLastFloat(heads[i], num);
        }
        else if (heads[i]->datadate != NULL)
        {
            char new1 = (char *)malloc(sizeof(char) * MAX_SIZE);
            printf("Enter the data for the %d column :", i + 1);
            gets(new1);
            heads[i] = addLastDate(heads[i], new1);
        }
    }
    return heads;
}

int getCountStringLength(struct NodeName *columnNames)
{
    struct NodeName *temp = columnNames;
    int count = 0;

    do
    {
        count += strlen(temp->name);
        temp = temp->next;

    } while (temp != columnNames);

    return count;
}

void printdata(struct Node *heads[], int columns, int rows, struct NodeName *columnNames)
{
    display(columnNames, columns);

    for (int i = 0; i < (columns * 32); i++)
    {
        printf("-");
    }

    printf("\n");

    for (int row = 0; row < rows; row++)
    {
        printf("\t");
        for (int i = 0; i < columns; i++)
        {
            struct Node *temp = heads[i];

            for (int j = 0; j < row; j++)
            {
                temp = temp->next;
            }

            if (temp->dataInt != NULL)
            {
                printf("%d", temp->dataInt);
                printf("\t\t");
            }
            else if (temp->dataChar != NULL)
            {
                printf("%s", temp->dataChar);
                printf("\t\t");
            }
            else if (temp->dataFloat != -1)
            {
                printf("%f", temp->dataFloat);
                printf("\t\t");
            }
            else if (temp->datadate != NULL)
            {
                printf("%s", temp->datadate);
                printf("\t\t");
            }
            else
            {
                printf("Null");
            }
            if (i < columns - 1)
            {
                printf("|\t\t");
            }
        }
        printf("\n");
    }
}

void aggregate(struct Node *heads[], int columns)
{
    int t = 1;
    while (t != -1)
    {
        int n;
        printf("\nRefer The Below References:\n");
        printf("1.SUM\n");
        printf("2.AVERAGE\n");
        printf("3.COUNT\n");
        printf("4.MIN\n");
        printf("5.MAX\n");
        printf("6.Back\n");
        printf("Enter the operation number:");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
        {
            int column;
            printf("Enter the column number to find the Sum of the datas:");
            scanf("%d", &column);
            if (column <= columns)
            {
                struct Node *head = heads[column - 1];
                struct Node *temp = heads[column - 1];
                if (temp->dataInt != NULL)
                {
                    int sum = 0;

                    do
                    {
                        sum += temp->dataInt;
                        temp = temp->next;
                    } while (temp != head);

                    printf("The sum of the included column is %d\n", sum);
                }
                else if (temp->dataFloat != -1)
                {
                    float sum = 0;

                    do
                    {
                        sum += temp->dataFloat;
                        temp = temp->next;
                    } while (temp != head);

                    printf("The sum of the included column is %f\n", sum);
                }
                else
                {
                    printf("The table is not in the type of integer or float\n");
                }
            }
            else
            {
                printf("\nCOLUMN DOES NOT EXIST\n");
            }
            break;
        }
        case 2:
        {
            int column;
            printf("Enter the column number to find the Average of the datas:");
            scanf("%d", &column);
            if (column <= columns)
            {
                struct Node *head = heads[column - 1];
                struct Node *temp = heads[column - 1];
                if (temp->dataInt != NULL)
                {
                    float sum = 0;
                    int count = 0;

                    do
                    {
                        sum += temp->dataInt;
                        temp = temp->next;
                        count++;
                    } while (temp != head);

                    float average = sum / (float)count;
                    printf("The average of the included column is %f\n", average);
                }
                else if (temp->dataFloat != -1)
                {
                    float sum = 0;
                    int count = 0;

                    do
                    {
                        sum += temp->dataFloat;
                        temp = temp->next;
                        count++;
                    } while (temp != head);

                    float average = sum / count;
                    printf("The average of the included column is %f\n", average);
                }
                else
                {
                    printf("The table is not in the type of integer or float\n");
                }
            }
            else
            {
                printf("\nCOLUMN DOES NOT EXIST\n");
            }
            break;
        }
        case 3:
        {
            int column;
            printf("Enter the column number to find the Count of the datas:");
            scanf("%d", &column);
            if (column <= columns)
            {
                struct Node *head = heads[column - 1];
                struct Node *temp = heads[column - 1];
                int count = 0;

                do
                {
                    count++;
                    temp = temp->next;
                } while (temp != head);

                printf("The count of the included column is%d\n", count);
            }
            else
            {
                printf("\nCOLUMN DOES NOT EXIST\n");
            }
            break;
        }
        case 4:
        {
            int column;
            printf("Enter the column number to find the minimum element from the datas:");
            scanf("%d", &column);
            if (column <= columns)
            {
                struct Node *head = heads[column - 1];
                struct Node *temp = heads[column - 1];
                if (temp->dataInt != NULL)
                {
                    int min = temp->dataInt;
                    temp=temp->next;

                    while (temp != head)
                    {
                        if (temp->dataInt <= min)
                        {
                            min = temp->dataInt;
                        }
                        temp = temp->next;
                    } 

                    printf("The minimum element of the included column is %d\n", min);
                }
                else if (temp->dataFloat != -1)
                {
                    float min = temp->dataFloat;
                    temp=temp->next;

                    while (temp != head)
                    {
                        if (temp->dataFloat <= min)
                        {
                            min = temp->dataFloat;
                        }
                        temp = temp->next;
                    } 

                    printf("The minimum element of the included column is %f\n", min);
                }
                else
                {
                    printf("The table is not in the type of integer or float\n");
                }
            }
            else
            {
                printf("\nCOLUMN DOES NOT EXIST\n");
            }
            break;
        }
        case 5:
        {
            int column;
            printf("Enter the column number to find the minimum element from the datas:");
            scanf("%d", &column);
            if (column <= columns)
            {
                struct Node *head = heads[column - 1];
                struct Node *temp = heads[column - 1];
                if (temp->dataInt != NULL)
                {
                    int max = temp->dataInt;
                    temp=temp->next;

                    while (temp != head)
                    {
                        if (temp->dataInt >= max)
                        {
                            max = temp->dataInt;
                        }
                        temp = temp->next;
                    } 

                    printf("The maximum element of the included column is %d\n", max);
                }
                else if (temp->dataFloat != -1)
                {
                    float max = temp->dataFloat;

                    while (temp != head)
                    {
                        if (temp->dataFloat >= max)
                        {
                            max = temp->dataFloat;
                        }
                        temp = temp->next;
                    } 

                    printf("The maximum element of the included column is %f\n", max);
                }
                else
                {
                    printf("The table is not in the type of integer or float\n");
                }
            }
            else
            {
                printf("\nCOLUMN DOES NOT EXIST\n");
            }
            break;
        }
        case 6:
        {
            t = -1;
            break;
        }
        }
    }
}

void display(struct NodeName *head, int columns)
{
    struct NodeName *temp = head;
    int i = 0;
    printf("\t");
    do
    {
        printf("%s", temp->name);
        printf("\t\t");
        if (i < columns - 1)
        {
            printf("|\t\t");
        }
        i++;
        temp = temp->next;
    } while (temp != head && i <= columns);
    printf("\n");
}

void main()
{
    printf("                                    DATABASE MANAGEMENT SYSTEM\n");
    printf("                                                            --CREATED BY\n");
    printf("                                                                  MADHAN D\n");
    printf("                                                                  SATHEESHKUMAR S\n");
    printf("                                                                  NEELAKANDAN S\n");
    int t = 1;
    int columns;
    int rows = 0;
    struct Node *heads[MAX_SIZE];
    struct NodeName *columnNames;
    int i;
    for (i = 0; t != -1; i++)
    {
        int n;
        printf("\nRefer The Below References:\n");
        printf("1.CREATE TABLE\n");
        printf("2.INSERT INTO TABLE\n");
        printf("3.UPDATE IN TABLE\n");
        printf("4.DELETE ROW IN TABLE\n");
        printf("5.SELECT ALL FROM TABLE\n");
        printf("6.AGGREGATE FUNCTIONS\n");
        printf("7.DROP TABLE\n");
        printf("8.Exit\n");
        printf("Enter the operation number:");
        scanf(" %d", &n);

        switch (n)
        {
        case 1:
        {
            printf("Enter the no_of columns:");
            scanf("%d", &columns);
            getchar();

            heads[columns];
            int doop1 = columns;

            columnNames = getColumnNames(doop1);
            int doop = columns;

            InitiateDB(heads, doop);
            rows++;
            break;
        }
        case 2:
        {
            if (heads[0] != NULL)
            {
                addRow(heads, columns);
            }
            else
            {
                printf("\nTABLE IS ALREADY DROPPED SO CAN'T ADD VALUES INTO THE TABLE\n");
            }
            rows++;
            break;
        }
        case 3:
        {
            if (heads[0] != NULL)
            {
                updateRowDetail(heads, columns, rows);
            }
            else
            {
                printf("\nTABLE IS ALREADY DROPPED SO THERE IS NO VALUES TO UPDATE IN THE TABLE\n");
            }
            break;
        }
        case 4:
        {
            int row;
            printf("Enter the row to be deleted:");
            scanf("%d", &row);
            getchar();
            if (heads[0] != NULL)
            {
                if (row <= rows)
                {
                    deleterow(heads, columns, rows, row);
                    rows--;
                }
                else
                {
                    printf("\nROW NUMBER IS OUT OF RANGE\n");
                }
            }
            else
            {
                printf("\nTABLE IS ALREADY DROPPED SO THERE IS NOTHING TO DELETE IN THE TABLE\n");
            }
            break;
        }
        case 5:
        {
            if (heads[0] != NULL)
            {
                printdata(heads, columns, rows, columnNames);
            }
            else
            {
                printf("\nNOTHING TO SELECT IN THE TABLE. THE TABLE IS EMPTY\n");
            }
            break;
        }
        case 6:
        {
            if (heads[0] != NULL)
            {
                aggregate(heads, columns);
            }
            else
            {
                printf("\nTABLE IS DROPPED. SO THERE IS NO VALUES TO CALCULATE AGGREGATE FUNCTIONS\n");
            }
            break;
        }
        case 7:
        {
            columnNames = NULL;
            for (int i = 0; i < columns; i++)
            {
                heads[i] = NULL;
            }
            rows = 0;
            columns = 0;
            printf("\nTABLE DROPPED SUCCESSFULLY\n");
            break;
        }
        case 8:
        {
            t = -1;
            printf("Thank You For Using Our DB\n");
            break;
        }
        }
    }
}