# Question 1

## Global Variables

## `Node *head `
Note that the head to the linked list is made global. I have done this in order to avoid passing the head as an argument to every function in which it is required. Even though it usually is considered bad practice to use global variables as they can be mistakenly modified, I have taken care to avoid this. `head` is used in many functions and is therefore better off as a global variable.

### `char entype[2][8]`
This is an array of strings representing account types (savings and current). This ensures easy conversion from the enum to the strings while displaying data. Instead of checking if the AccType is 0 or 1 and then printing 'savings' or current, we can now directly say `entype[AccType]`

## Functions

### `Node *findPerson(char *check, AccType accountType)`
This function searches for a person with a given name and account type in the linked list and returns their account information. This function is used in the function `findPerson` in order to check whether an account with the same username and account type has already been created in order to prevent repetitions.

### `void display()`
This function displays the account information, including account number, account type, name, and balance, for all accounts in the linked list with proper formatting.

### `void createAccount(AccType accountType, char Name[], float Amount)`
This function creates a new bank account with the specified account type, name, and initial balance. It displays an error message if the same account type already exists with the same username.

It also makes sure that newly created accounts are given the account numbers of deleted accounts, if any, by checking if any adjacent account numbers have a difference of more than 1.

### `void deleteAccount(AccType accountType, char Name[])`
This function deletes a bank account with the specified account type and name by freeing the node after adjusting the links in the linked list. It displays an error message if the account does not exist.

### `void lowBalanceAccounts()`
This function displays the account numbers, names, and balances of accounts with a balance less than 100.

### `void transaction(int accountNumber, float amount, int code)`
This function performs a transaction on the specified account, either withdrawing or depositing an amount depending on the input code. It makes sure that the balance does not drop below 100 after a transaction by returning an error message if it occurs

## Assumptions
A person having both savings and current accounts can have the same username for both, but all usernames for a particular account type should be different.

# Question 2

## Structs

### `struct Node`
Stores the complex number of dimension n in the form of a linked list

### `struct Complex`
Stores the dimension of the two complex numbers, and the head of linked lists representing each of the complex numbers

The head of the linked lists containing the two complex numbers are:
`Complex.c1`
`Complex.c2`

## Functions

### `Node *add()`
Adds each dimension of the two complex numbers and stores it in a new linked list (created in main) called res.
It returns res

### `Node *subtract`
Subtracts each dimension of the two complex numbers and stores it in a new linked list (created in main) called res.
It returns res

Could have implemented add and subtract in the same function using an if/else condition, but wasn't sure whether we had to create separate functions or not

### `float dot()`
Multiplies corresponding dimensions of the two complex numbers, and adds them up to store them in sum (which is the dot product)
It returns sum

### `float mod(Node *comp)`
This function is implemented and made use of in the cosine function. It returns the square root of sums of squares of each dimension of a complex numbers (the mod of the complex number)

### `float cosine()`
Makes use of the dot and mod functions to calculate the cosine similarity

The above functions do not need any parameters since all the complex numbers are available globally

### `void print(Node *res)`
This takes in the head node of a linked list as input and prints the linked list. It is called in the main() function to print the results

## Assumptions
The user always enters the correct command like ADD, SUB, etc or -1 to exit

# Question 3

## Structs

### `struct Node`
As we take the input colours from the user, they are simultaneously entered into the above linked list

## Functions

### `Node *removeDuplicates(Node *head)`
This function traverses the linked list. After fixing iself at a particular element, it goes through the subsequent elements and removes the duplicates
2 2 2 2 3
It fixes itself at 2, removes all the duplicate 2s and then goes to 3