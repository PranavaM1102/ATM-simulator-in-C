#include <stdio.h>

void displayMenu() {
    printf("---------------------Welcome to ABC BANK ATM Service-------------------\n");
    printf("1. Check Balance\n");
    printf("2. Withdraw Cash\n");
    printf("3. Deposit Cash\n");
    printf("4. Change The Pin\n");
    printf("5. Quit\n");
    printf("_______________________________________________________________\n\n");
    printf("Enter your choice: ");
}

int main() {
    FILE *fp0, *fp;
    int balance, deposit, withdraw;
    int choice, pin, pin1, k = 0;
    char transaction;
    
    fp = fopen("pin.txt", "r");
    if (fp == NULL) {
        printf("Error opening pin.txt\n");
        return 1;
    }
    fscanf(fp, "%d", &pin);
    fclose(fp);

    do {
        printf("ENTER YOUR ATM PIN: ");
        scanf("%d", &pin1);
        if (pin1 != pin) {
            printf("PLEASE ENTER VALID PIN\n");
        }
    } while (pin1 != pin);

    fp = fopen("balance.txt", "r");
    if (fp == NULL) {
        printf("Error opening balance.txt\n");
        return 1;
    }
    fscanf(fp, "%d", &balance);
    fclose(fp);

    fp0 = fopen("receipt.txt", "w");
    if (fp0 == NULL) {
        printf("Error opening receipt.txt\n");
        return 1;
    }

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYOUR BALANCE IN Rs : %d\n", balance);
                break;
            case 2:
                printf("\nENTER THE AMOUNT TO WITHDRAW: ");
                scanf("%d", &withdraw);
                if (withdraw % 100 != 0) {
                    printf("\nPLEASE ENTER THE AMOUNT IN MULTIPLES OF 100\n");
                } else if (withdraw > (balance - 500)) {
                    printf("\nINSUFFICIENT BALANCE\n");
                } else {
                    balance -= withdraw;
                    printf("\nPLEASE COLLECT CASH\n");
                    printf("YOUR CURRENT BALANCE IS %d\n", balance);
                    fprintf(fp0, "\nYOUR CURRENT BALANCE IS %d", balance);
                }
                break;
            case 3:
                printf("\nENTER THE AMOUNT TO DEPOSIT: ");
                scanf("%d", &deposit);
                balance += deposit;
                printf("YOUR BALANCE IS %d\n", balance);
                fprintf(fp0, "\nYOUR CURRENT BALANCE IS %d", balance);
                break;
            case 4:
                fp = fopen("pin.txt", "w");
                printf("ENTER THE NEW PIN: ");
                scanf("%d", &pin);
                fprintf(fp, "%d", pin);
                fclose(fp);
                break;
            case 5:
                printf("\nTHANK YOU FOR USING ABC BANK ATM\n");
                break;
            default:
                printf("\nINVALID CHOICE\n");
                break;
        }

        printf("\nDO YOU WISH TO HAVE ANOTHER TRANSACTION? (y/n): ");
        fflush(stdin);
        scanf(" %c", &transaction);

        if (transaction == 'n' || transaction == 'N') {
            k = 1;
        }
    } while (!k);

    fprintf(fp0, "\n\nTHANK YOU FOR USING ABC BANK SERVICE\nWEAR MASK AND SANITIZE YOUR HANDS\nDO VISIT AGAIN\nTHANK YOU FOR USING ABC BANK SERVICE\n");
    fclose(fp0);

    printf("\nTHANK YOU FOR USING ABC BANK SERVICE\nWEAR MASK AND SANITIZE YOUR HANDS\nDO VISIT AGAIN\nTHANK YOU FOR USING ABC BANK SERVICE\n");

    return 0;
}
