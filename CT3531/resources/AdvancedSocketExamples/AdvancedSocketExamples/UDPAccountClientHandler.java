// Handles the server interaction with a UDP client
// Assume that the client has already sent initial hello message to server
// Server creates an Account object that is sent to the Client
// The Client runs some transactions on the account and sends it back to the server

import java.io.*;
import java.net.*;

class UDPAccountClientHandler extends Thread {
  private DatagramPacket hellopacket;

  public UDPAccountClientHandler(DatagramPacket hellopacket) {
    this.hellopacket = hellopacket;
  }

  // This is what the thread runs when started...
  public void run() {
    try {

      // Create an account object with an opening balance of €200
      Account acc1 = new Account(12345678, (float) 200.00);
      System.out.println("Account: " + acc1.getaccNum() + " has balance of " + acc1.getBalance());

      // Use ByteArrayInputStream and ByteArrayOutputStream to read and write packet data
      // First send the account object to the client
      ByteArrayOutputStream bos = new ByteArrayOutputStream();
      ObjectOutputStream oos = new ObjectOutputStream(bos);
      oos.writeObject(acc1);
      byte[] txdata = bos.toByteArray();

      // Create the packet containing the account data
      DatagramPacket txpacket = new DatagramPacket(txdata, txdata.length,
        hellopacket.getAddress(), hellopacket.getPort());

      // Send the account data to the Client
      DatagramSocket sock = new DatagramSocket();
      sock.send(txpacket);
      System.out.println("Account object sent to client...");

      // Create a byte[] large enough to hold the largest possible UDP datagram
      byte[] b = new byte[65536];
      // Next create a ByteArrayInputStream associated with this array
      ByteArrayInputStream bis = new ByteArrayInputStream(b);
      // Then create a DatagramPacket that also uses the same byte[]
      DatagramPacket rxpacket = new DatagramPacket(b, b.length);
      // Then wait to receive the account object back from the client
      sock.receive(rxpacket);

      // Extract the account object from the byte[] using the ByteArrayInputStream
      ObjectInputStream ois = new ObjectInputStream(bis);
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
