
#include <stdio.h>
int main()
{

	FILE *fp0;
	fp0=fopen("receipt.txt","w");
	fprintf(fp0,"---------------------Welcome to ABC BANK ATM Service-------------------\n");
	printf("---------------------Welcome to ABC BANK ATM Service-------------------\n");
	unsigned long 	balance, deposit, withdraw;
	int choice,pin,pin1,k=0;
	char transaction;
    FILE *fp;
    fp=fopen("pin.txt","r");
	fscanf(fp,"%d",&pin);
	fclose(fp);
	while (pin1!=pin)
	{
		printf("ENTER YOUR ATM PIN:");
		scanf("%d", &pin1);
		if (pin1 != pin)
		printf("PLEASE ENTER VALID PIN\n");
	}
	do
	{
		
		printf("---------------------Welcome to ABC BANK ATM Service-------------------\n");
		printf("1. Check Balance");
		printf("                                           2. Withdraw Cash\n");
		printf("3. Deposit Cash");
		printf("                                           4. Change The Pin\n");
		printf("                       5. Quit\n");
		printf("_______________________________________________________________\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			fp=fopen("balance.txt","r");
			fscanf(fp,"%d",&balance);
			fclose(fp);
			printf("\n YOUR BALANCE IN Rs : %lu ", balance);
			break;
		case 2:
			fp=fopen("balance.txt","r");
			fscanf(fp,"%d",&balance);
			fclose(fp);
			printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
			scanf("%lu", &withdraw);
			if (withdraw % 100 != 0)
			{
				printf("\n PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
			}
			else if (withdraw >(balance - 500))
			{
				printf("\n INSUFFICENT BALANCE");
			}
			else
			{
				fp=fopen("balance.txt","w");
				fprintf(fp0,"\n YOUR CURRENT BALANCE IS %lu", balance);
				balance = balance - withdraw;
				fprintf(fp0,"\n%lu WAS DEBITED FROM YOUR ACCOUNT", withdraw);
				fprintf(fp,"%d",balance);
				fclose(fp);
				printf("\n\n PLEASE COLLECT CASH");
				printf("\n YOUR CURRENT BALANCE IS %lu", balance);
				fprintf(fp0,"\n YOUR CURRENT BALANCE IS %lu", balance);
			}
			break;
		case 3:
			fp=fopen("balance.txt","r");
			fscanf(fp,"%d",&balance);
			fclose(fp);
			fprintf(fp0,"\n YOUR CURRENT BALANCE IS %lu", balance);
			printf("\n ENTER THE AMOUNT TO DEPOSIT");
			scanf("%lu", &deposit);
                        balance = balance + deposit;
			fp=fopen("balance.txt","w");
			fprintf(fp0,"\n%lu WAS CREDITED FROM YOUR ACCOUNT", deposit);
			fprintf(fp,"%d",balance);
			fprintf(fp0,"\n YOUR CURRENT BALANCE IS %lu", balance);
			fclose(fp);
			
			printf("YOUR BALANCE IS %lu", balance);
			break;
		case 5:
			printf("\n THANK U USING ATM");
			break;
		case 4:
			fp=fopen("pin.txt","w");
			printf("ENTER THE NEW PIN\n");
			scanf("%d",&pin);
			fprintf(fp,"%d",pin);
			fclose(fp);
			break;
		default:
			printf("\n INVALID CHOICE");
		}
	printf("\n\n\n DO U WISH TO HAVE ANOTHER TRANSCATION?(y/n): \n");
	fflush(stdin);
	scanf("%c", &transaction);
	if (transaction == 'n'|| transaction == 'N')
        k = 1;
	} while (!k);
	fprintf(fp0,"\n\n THANKS FOR USING ABC BANK SERVICE\nWEAR MASK AND SANITIZE UR HANDS\n DO VISIT AGAIN\n THANKS FOR USING ABC BANK SERVICE");
	fclose(fp0);
	printf("\n\n THANKS FOR USING ABC BANK SERVICE\nWEAR MASK AND SANITIZE UR HANDS\n DO VISIT AGAIN\n THANKS FOR USING ABC BANK SERVICE");
}