public class Account {
    private int accountNumber;
    private double balance;

    public Account(int num) {
        this(num, 0.0);
    }

    // overloaded constructor
    public Account(int num, double balance) {
        this.accountNumber = num;
        this.balance = balance;
    }

    // methods
    public void deposit(int num) {
        if (num > 0) {
            balance += num;
            System.out.println("deposited " + num + " euro succesfully");
        } else {
            System.out.println("amount not valid");
        }
    }

    public void withdraw(int num) {
        if (num > 0) {
            if (num < balance) {
                balance -= num;
                System.out.println("withdrew " + num + " euro succesfully");
            } else {
                System.out.println("not enough balance to withdraw");
            }
        } else {
            System.out.println("amount not valid");
        }
    }

    // getters and setters
    public int getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }
}