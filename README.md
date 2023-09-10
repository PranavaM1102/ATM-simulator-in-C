# ABC BANK ATM Simulation

This C program simulates an ATM (Automated Teller Machine) service provided by ABC BANK. It allows users to perform various banking operations, such as checking their balance, withdrawing cash, depositing cash, changing their PIN, and quitting the service. The program also maintains a transaction history in a file named "receipt.txt" and stores the user's PIN in a file named "pin.txt."

## Features

- **Check Balance**: Users can check their account balance.

- **Withdraw Cash**: Users can withdraw cash, provided they have a sufficient balance and the withdrawal amount is in multiples of 100.

- **Deposit Cash**: Users can deposit cash into their account.

- **Change PIN**: Users can change their ATM PIN.

- **Quit**: Users can exit the ATM service.

## Getting Started

1. Clone or download the code from this repository to your local machine.

2. Compile the code using a C compiler. For example:

   ```bash
   gcc atm.c -o atm
Run the compiled executable:

    ./atm
Follow the on-screen instructions to use the ATM service.

## File Structure
atm.c: The main C program containing the ATM simulation logic.

pin.txt: A text file that stores the user's PIN.

balance.txt: A text file that stores the account balance.

receipt.txt: A text file where transaction details and receipts are recorded.

## Usage
When you run the program, it will prompt you to enter your ATM PIN. Make sure you have the correct PIN.

Once authenticated, you can choose from the available options using the menu:

1: Check Balance
2: Withdraw Cash
3: Deposit Cash
4: Change The Pin
5: Quit
Follow the on-screen prompts to perform the desired operation.

After each transaction, you will be asked if you want to perform another transaction (y/n).

When you decide to quit, the program will display a thank-you message, and your transaction history will be saved in "receipt.txt."

## Notes
The code does not include advanced security practices for PIN handling and is intended for educational purposes. In a real banking system, secure PIN storage and transmission are crucial.

Ensure that the input and output file paths in the code match your file locations on your system.

## License
LICENSE file for details.
