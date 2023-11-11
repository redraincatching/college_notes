import java.time.LocalDate;
import java.io.Serializable;

public class Transaction implements Serializable {

  private float amount;
  private String type;
  private LocalDate date;

  public Transaction(float amount, String type) {

    this.amount = amount;
    this.type = type;
    date = LocalDate.now();
  }

  // Accessor methods get / set methods

  public String toString() {

    return "Transaction: amount = " + amount + " type = " + type + " date = " + date + "\n";

  }

}
