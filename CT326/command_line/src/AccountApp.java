public class AccountApp {
    public static void main(String[] args) {
        Account myAccount = new Account(5);
        System.out.println("acc no: " + myAccount.getAccountNumber() + "\nbalance: " + myAccount.getBalance());

        myAccount.deposit(100);
        myAccount.withdraw(2000);
        myAccount.withdraw(80);
        myAccount.deposit(-30);
    }
}