// If both the client and server are Java based applications then it is possible
// to use Java Object Serialisation to send and receive objects using sockets
// Very convenient for defining serializable classes to represent application messages

import java.io.*;
import java.net.*;

class TCPAccountClient {

  public static void main(String args[]) {
    Socket sock;

    // Open our connection to dcham, at port 4444
    // If you try this on your system, insert your system
    // in place of "dcham" - "dcham.nuigalway.ie" is my
    // system name.

    String server = "localhost";
    if (args.length > 0)
    server = args[0];

    try
    {
      sock = new Socket(server,4444);
      // Get I/O streams from the socket
      ObjectInputStream ois = new ObjectInputStream(sock.getInputStream());
      ObjectOutputStream oos = new ObjectOutputStream(sock.getOutputStream());

      // Download accoutn object from server
      Account acc1 = (Account) ois.readObject();
      System.out.println("Account object downloaded from server...");
      // Do some transactions...

      acc1.makeDeposit(1000);
      acc1.makeWithdrawal(200);
      acc1.makeWithdrawal(300);
      // Send account object back to the server
      oos.writeObject(acc1);
      System.out.println("Account object sent to server...");
      oos.close();
      sock.close();
    }
    catch (Exception ex)
    {
      System.out.println("Something went wrong!");
      ex.printStackTrace();
    }
  }
}
