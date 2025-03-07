#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Transaction {
    char date[11];
    double amount; 
    char category[50]; 
    char description[100]; 
    int type; // takes 1 for credit and -1 for debit.
} Transaction;

typedef struct Node {
    Transaction transaction; 
    struct Node* next; 
    struct Node* prev; 
} Node;

typedef struct DoublyLinkedList {
    Node* head;
    Node* tail; 
} DoublyLinkedList;

Node* createNode(Transaction transaction) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed for new node.\n");
        exit(EXIT_FAILURE);
    }
    newNode->transaction = transaction;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

DoublyLinkedList* createList() {
    DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList));
    if (!list) {
        fprintf(stderr, "Memory allocation failed for list.\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insert_Transaction(DoublyLinkedList* list, Transaction transaction) {
    Node* newNode = createNode(transaction);
    if (!list->head) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}

void sort_Transactions(DoublyLinkedList* list) {
    if (!list->head) return;

    Node* current;
    Node* index;
    Transaction temp;

    for (current = list->head; current != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (strcmp(current->transaction.date, index->transaction.date) > 0) {
                temp = current->transaction;
                current->transaction = index->transaction;
                index->transaction = temp;
            }
        }
    }
}

void display_Transactions(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current) {
        printf("%s: %.2f [%s] - %s\n",
               current->transaction.date,
               current->transaction.amount,
               current->transaction.category,
               current->transaction.description);
        current = current->next;
    }
}

double Calculate_Total_Transaction(DoublyLinkedList* list) {
    double total = 0.0;
    Node* current = list->head;
    while (current) {
        total += current->transaction.amount;
        current = current->next;
    }
    return total;
}

void Update_BankBalance(double* balance, double amount) {
    *balance += amount; // Adds credit to bank balance and subtracts debits from bank balance.
}

void Calculate_Credits_Debits(DoublyLinkedList* list, double* totalCredits, double* totalDebits) {
    Node* current = list->head;
    while (current) {
        if (current->transaction.type == 1) {
            *totalCredits += current->transaction.amount; // Calculating total credits.
        } else if (current->transaction.type == -1) {
            *totalDebits += current->transaction.amount; // Calculating total debits.
        }
        current = current->next;
    }
}

double Calculate_Balance_Change(double initialBalance, double finalBalance) {
    return initialBalance - finalBalance; 
}

void Free_List(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    DoublyLinkedList* financeList = createList();
    char continueInput;
    double bankBalance = 0.0;

    printf("Enter your bank balance from the prefered date of calculation: ");
    scanf("%lf", &bankBalance);

    do {
        Transaction transaction;

        printf("\nEnter transaction details:\n");
        printf("Date (DD-MM-YYYY): ");
        scanf("%s", transaction.date);

        printf("Amount: ");
        scanf("%lf", &transaction.amount);

        printf("Is this amount credited or debited? (c/d): ");
        char typeInput;
        scanf(" %c", &typeInput);
        transaction.type = (typeInput == 'c' || typeInput == 'C') ? 1 : -1;

        printf("Category: ");
        scanf("%s", transaction.category);

        printf("Description: ");
        getchar();
        fgets(transaction.description, sizeof(transaction.description), stdin);
        transaction.description[strcspn(transaction.description, "\n")] = 0;

        Update_BankBalance(&bankBalance, transaction.type * transaction.amount);
        insert_Transaction(financeList, transaction);
        Display_BankBalance(bankBalance);

        printf("Do you want to add another transaction? (y/n): ");
        scanf(" %c", &continueInput); 

    } while (continueInput == 'y' || continueInput == 'Y');

    sort_Transactions(financeList);
    printf("\nTransactions in order:\n");
    display_Transactions(financeList);//Displaying the Transaction History.

    double totalAmount = Calculate_Total_Transaction(financeList);//Calling function to Calculate the Total Transactions  made by the user.
    printf("\nTotal Transactions Made: %.2f\n", totalAmount);

    double totalCredits = 0.0;
    double totalDebits = 0.0;
    Calculate_Credits_Debits(financeList, &totalCredits, &totalDebits);;//Calling the function to calculate the total credit amount and tota debit amount made.

    printf("Current bank balance: %.2f\n", balance);//Function to Display the Bank Balance after all the transactions.
    printf("Total credited: %.2f\n", totalCredits);
    printf("Total debited: %.2f\n", totalDebits);

    double CurrentBalance = bankBalance-totalDebits+totalCredits;
    double balanceChange = Calculate_Balance_Change(CurrentBalance, bankBalance);
    printf("Change in bank balance: %.2f\n", balanceChange);//Displaying the difference from the inital bankbalnce and current BankBalance

    Free_List(financeList);

    return 0;
}
