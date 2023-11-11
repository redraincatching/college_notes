
import java.io.Serializable;
import java.util.List;
import java.util.ArrayList;
import java.time.LocalDateTime;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.IOException;

public class Account implements Serializable {

  // Define serialVersionUID which is used during object deserialization to verify that the sender and receiver of a serialized
  // object have loaded classes for that object that are compatible - will throw InvalidClassException if not compatible
  // IDEs will often auto generate this value for you when creating new Java classes

  private static final long serialVersionUID = 202010191519L;

  private int accnum;
  private float balance;
  private List<Transaction> transactions;  // List of Transaction objects

  // Date and Time account object was first created or loaded from storage
  private LocalDateTime activated;

  public Account (int accnum, float balance) {

    this.balance = balance;
    this.accnum = accnum;
    transactions = new ArrayList<Transaction>();
    activated = LocalDateTime.now();
  }

  public void makeDeposit(float amount) {
    // Only the code inside the synchronized code block is thread safe
    synchronized(this) {
      balance += (amount > 0) ? amount : 0;
      transactions.add(new Transaction(amount, "Deposit"));
    }
  }

  public synchronized void makeWithdrawal(float amount) throws LessThanZero {
    setBalance(balance - amount);
    transactions.add(new Transaction(amount, "Withdrawal"));
  }

  private void setBalance(float balance) throws LessThanZero {
    if (balance < 0) throw new LessThanZero("Negative Balance Not Allowed!");
    this.balance = balance;
  }

  public float getBalance() {
    return balance;
  }

  public int getaccNum() {
    return accnum;
  }

  public List<Transaction> getTransactions() {
    return transactions;
  }

  public LocalDateTime getActivated() {
    return activated;
  }

  // This method is called when we are deserializing an instance of an Account object
  private void readObject(ObjectInputStream aInputStream) throws ClassNotFoundException,IOException {
    balance = aInputStream.readFloat();
    accnum = aInputStream.readInt();
    transactions = (List<Transaction>) aInputStream.readObject();
    // Reinitialise value for the LocalDateTime activated variable
    activated = LocalDateTime.now();
  }

  // This method is called when we serialize an instance of an Account object
  private void writeObject(ObjectOutputStream aOutputStream) throws IOException {
    aOutputStream.writeFloat(balance);
    aOutputStream.writeInt(accnum);
    aOutputStream.writeObject(transactions);
    // We don't write value for the LocalDateTime activated variable as we will reinitialise this when reloading the object
  }

}
