// Handles the server interaction with a connected client
// Server creates an Accoutn object that is sent to the Client
// The Client runs some transactions on the account and sends it back to the server

import java.io.*;
import java.net.*;

class TCPAccountClientHandler extends Thread {
  private Socket sock;

  public TCPAccountClientHandler(Socket sock) {
    this.sock = sock;
  }

  // This is what the thread runs when started...
  public void run() {
    try {

      // Create an account object with an opening balance of €200
      Account acc1 = new Account(12345678, (float) 200.00);
      System.out.println("Account: " + acc1.getaccNum() + " has balance of " + acc1.getBalance());

      // Get I/O streams from the socket
      ObjectOutputStream oos = new ObjectOutputStream(sock.getOutputStream());
      ObjectInputStream ois = new ObjectInputStream(sock.getInputStream());

      // Send the account object to the client
      oos.writeObject(acc1);
      oos.flush();
      System.out.println("Account object sent to client...");

      // Get the account object back from the client
      acc1 = (Account) ois.readObject();
      System.out.println("Got account object back from client...");
      System.out.println("Account: " + acc1.getaccNum() + " has balance of " + acc1.getBalance());
      System.out.println("Transactions: " + acc1.getTransactions());
      sock.close();
    }
    catch (Exception ex)
    {
      System.out.println("Some error occured!");
      ex.printStackTrace();
    }
  }
}
