/*
21347021
eidhne kennedy
2022/02/14
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int day, month, year;
} date;

typedef struct {
	char name[50];
	int accountNumber;
	double balance;
	date lastTrans;
} customer;

void getCustomerName(customer* cptr);
void getAccountNumber(customer* cptr);
void getLastTransDate(customer* cptr);
void getBalance(customer* cptr);
void printCustomer(customer* cptr);


void main() {
	int i;
	char temp[100];
	customer customers[3];
	for (i = 0; i < 3; i++) {
		getCustomerName(&customers[i]);
		getAccountNumber(&customers[i]);
		getLastTransDate(&customers[i]);
		getBalance(&customers[i]);
		gets_s(temp, 100);
		printf("\n");
	}
	printf("\n\n%25s\t%13s\t%12s\t%s\n\n", "Name", "Account Number",
		"Balance", "Date of Last Transaction");
	for (i = 0; i < 3; i++) {
		printCustomer(&customers[i]);
	}
}

void getCustomerName(customer* cptr) {
	puts("enter the name of the customer:");		// these first two functions are pretty self-explanatory
	scanf_s("%s", &cptr->name, 50);					// just scanf'ing the values into the struct
}

void getAccountNumber(customer* cptr) {
	puts("enter the account number:");
	scanf_s("%d", &cptr->accountNumber);
}

void getLastTransDate(customer* cptr) {
	char date[25];		// reads in the date
	char day[25], month[25], year[25];		// for storing the number itself
	int i = 0, j = 0;			// for stepping through the string

	puts("enter the date of the last transaction, in the format dd/mm/yyyy:");
	scanf_s("%s", &date, 25);
	while (date[i] != '/') {   // slash-delimited, it's a date
		day[j] = date[i];     // numbers into the new string
		i++;
		j++;
	}
	day[j] = '\0';
	cptr->lastTrans.day = atoi(day);	// and atoi it into the struct
	i++;
	j = 0;

	while (date[i] != '/') {   // now for the month
		month[j] = date[i];
		i++;
		j++;
	}
	month[j] = '\0';
	cptr->lastTrans.month = atoi(month);
	i++;
	j = 0;

	while (date[i] != '\0') {   // and the year
		year[j] = date[i];
		i++;
		j++;
	}
	year[j] = '\0';
	cptr->lastTrans.year = atoi(year);
	printf("\n");
}

void getBalance(customer* cptr) {		// same as the first two functions
	puts("enter the current balance:");
	scanf_s("%lf", &cptr->balance);
}

void printCustomer(customer* cptr) {
	printf("\n\n%25s\t%13d\t%12lf\t%2d/%2d/%4d\n\n", cptr->name, cptr->accountNumber, cptr->balance, cptr->lastTrans.day, cptr->lastTrans.month, cptr->lastTrans.year);
}
