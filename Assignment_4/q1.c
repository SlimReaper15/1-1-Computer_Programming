#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum AccType
{
    savings,
    current
} AccType;

char entype[2][8] = {"savings", "current"};

typedef struct AccountInfo
{
    int accno;
    AccType acctype;
    char name[50];
    float balance;
} AccountInfo;

typedef struct Node
{
    AccountInfo accinfo;
    struct Node *next;
} Node;

Node *head = NULL;

Node *findPerson(char *check, AccType accountType)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp -> accinfo.name, check) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void display()
{
    Node *temp = head;

    if (temp == NULL)
    {
        printf("No accounts to display\n");
        return;
    }

    printf("%-15s%-15s%-25s%-10s\n", "Account No.", "Account Type", "Name", "Balance");
    printf("----------------------------------------------------------------\n");

    while (temp != NULL)
    {
        printf("%-15d%-15s%-25s%-10.2f\n", temp -> accinfo.accno, entype[temp -> accinfo.acctype], temp -> accinfo.name, temp -> accinfo.balance);
        temp = temp -> next;
    }
}

void createAccount(char *acctype, char Name[], float Amount)
{
    AccType accountType;
    if (strcmp(acctype, "savings") == 0)
        accountType = 0;
    else if (strcmp(acctype, "current") == 0)
        accountType = 1;

    Node* check = findPerson(Name, accountType);

    if (check != NULL)
    {
        printf("Invalid: User already exists!\n");
        return;
    }

    Node *newacc = (Node *)malloc(sizeof(Node));
    newacc -> accinfo.acctype = accountType;
    strcpy(newacc -> accinfo.name, Name);
    newacc -> accinfo.balance = Amount;

    if (head != NULL && head -> accinfo.accno != 100)
    {
        newacc -> accinfo.accno = 100;
        newacc -> next = head;
        head = newacc;

        printf("Account Number: %d\n", newacc -> accinfo.accno);
        printf("Account Holder: %s\n", newacc -> accinfo.name);
        printf("Account Type: %s\n", entype[newacc -> accinfo.acctype]);
        printf("Balance: %.2f\n", newacc -> accinfo.balance);
        
        printf("Account created successfully.\n");
        return;
    }

    // Find the account immediately before the first deleted account
    Node *temp = head;
    Node *prevDeleted = NULL;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp -> next -> accinfo.accno - temp -> accinfo.accno > 1)
        {
            prevDeleted = temp;
            break;
        }
        temp = temp -> next;
    }

    if (prevDeleted != NULL)
    {
        newacc -> accinfo.accno = prevDeleted -> accinfo.accno + 1;
        newacc -> next = prevDeleted -> next;
        prevDeleted -> next = newacc;
    }
    else
    {
        if (head == NULL)
        {
            newacc -> accinfo.accno = 100;
            newacc -> next = NULL;
            head = newacc;
        }
        else
        {
            Node *last = head;
            while (last -> next != NULL)
                last = last -> next;
            newacc -> accinfo.accno = last -> accinfo.accno + 1;
            newacc -> next = NULL;
            last -> next = newacc;
        }
    }

    printf("Account Number: %d\n", newacc -> accinfo.accno);
    printf("Account Holder: %s\n", newacc -> accinfo.name);
    printf("Account Type: %s\n", entype[newacc -> accinfo.acctype]);
    printf("Balance: %.2f\n", newacc -> accinfo.balance);

    printf("Account created successfully.\n");
}


void deleteAccount(char *acctype, char Name[])
{
    AccType accountType;
    if (strcmp(acctype, "savings") == 0)
        accountType = 0;
    else if (strcmp(acctype, "current") == 0)
        accountType = 1;

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->accinfo.name, Name) == 0 && current->accinfo.acctype == accountType)
        {
            if (prev == NULL)
                head = current->next;
            else 
                prev->next = current->next;

            free(current);

            printf("Account deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Invalid: User does not exist!\n");
}

void lowBalanceAccounts()
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp -> accinfo.balance < 100)
            printf("Account Number: %d, Name: %s, Balance: %.2f\n", temp -> accinfo.accno, temp -> accinfo.name, temp -> accinfo.balance);
        temp = temp -> next;
    }
}

void transaction(int accountNumber, float amount, int code)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp -> accinfo.accno == accountNumber)
            break;
        temp = temp -> next;
    }

    if (temp == NULL)
    {
        printf("Invalid: User does not exist\n");
        return;
    }

    if (code == 0 && temp->accinfo.balance - amount < 100)
        printf("The balance is insufficient for the specified withdrawal.\n");
    else
    {
        if (code == 0)
            temp->accinfo.balance -= amount;
        else
            temp->accinfo.balance += amount;
        printf("Updated balance is Rs %.2f\n", temp->accinfo.balance);
    }
}


int main(void)
{
    // Sample:
    // createAccount("savings", "LeBron", 20);
    // createAccount("current", "Curry", 20);
    // createAccount("savings", "Messi", 23);
    // createAccount("savings", "Penaldo", 23400);
    // createAccount("current", "JorBald", 21300);
    // deleteAccount("savings", "LeBron");
    // display();
    // createAccount("current", "Add1", 200);
    // createAccount("savings", "Add2", 23400);
    // display();
    // transaction(100, 23400, 1);
    // lowBalanceAccounts();

    int AccountNumber;
    char AccountType[10];
    char Name[50];
    float Amount;
    int Code;

    while (1)
    {
        char s[15];
        scanf("%s", s);
        if (strcmp(s, "CREATE") == 0)
        {
            scanf("%s %s %f", &AccountType, &Name, &Amount);
            createAccount(AccountType, Name, Amount);
        }
        
        else if (strcmp(s, "DELETE") == 0)
        {
            scanf("%s %s", &AccountType, &Name);
            deleteAccount(AccountType, Name);
        }

        else if (strcmp(s, "TRANSACTION") == 0)
        {
            scanf("%d %f %d", &AccountNumber, &Amount, &Code);
            transaction(AccountNumber, Amount, Code);
        }

        else if (strcmp(s, "LOWBALANCE") == 0)
            lowBalanceAccounts();

        else if (strcmp(s, "DISPLAY") == 0)
            display();

        else if (strcmp(s, "EXIT") == 0)
            break;
        else
        {
            printf("Invalid input\n");
            continue;
        }
    }
}