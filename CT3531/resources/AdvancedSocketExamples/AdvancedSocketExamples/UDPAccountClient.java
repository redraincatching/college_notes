// Can also send and receive objects using DatagramPackets but this takes a bit more work
// as you have to manually read and write the associated data from a DatagramPacket objects
// We can use ByteArrayInputStream and ByteArrayOutoutStream to make this process easier

import java.io.*;
import java.net.*;

class UDPAccountClient {

  public static void main(String args[]) {
    try {
      // First create a byte[] large enough to hold the largest possible UDP datagram
      byte[] b = new byte[65536];
      // Next create a ByteArrayInputStream associated with this array
      ByteArrayInputStream bis = new ByteArrayInputStream(b);
      // Then create a DatagramPacket that also uses the same byte[]
      DatagramPacket rxpacket = new DatagramPacket(b, b.length);
      // Create a DatagramSocket to communicate with the ServerSocket
      DatagramSocket socket = new DatagramSocket();

      // Create another DatagramPacket to sent data to the Server at UDP port 4000
      // We need to initially send a short message to the server so that it can respond
      String hello = "Hi";
      byte hellodata[] = hello.getBytes();
      DatagramPacket hellopacket = new DatagramPacket(hellodata, hellodata.length,
      InetAddress.getLocalHost(), 4000);

      // Send the initial hello message
      socket.send(hellopacket);

      // Now receive the account object from the Server - blocks until we get something
      socket.receive(rxpacket);
      // Extract the account object from the byte[] using the ByteArrayInputStream
      ObjectInputStream ois = new ObjectInputStream(bis);
      Account acc1 = (Account) ois.readObject();
      System.out.println("Account object downloaded from server...");

      // Do some transactions...
      acc1.makeDeposit(1000);
      acc1.makeWithdrawal(200);
      acc1.makeWithdrawal(300);

      // Send account object back to the server
      // Use a ByteArrayOutputStream to write the data to a byte[]
      ByteArrayOutputStream bos = new ByteArrayOutputStream();
      ObjectOutputStream oos = new ObjectOutputStream(bos);
      oos.writeObject(acc1);
      byte[] txdata = bos.toByteArray();

      // Create the packet containing the account data
      DatagramPacket txpacket = new DatagramPacket(txdata, txdata.length,
        rxpacket.getAddress(), rxpacket.getPort());

      // Send the account data to the Server
      socket.send(txpacket);

      System.out.println("Account object sent to server...");
      oos.close();
    }
    catch (Exception ex)
    {
      System.out.println("Something went wrong!");
      ex.printStackTrace();
    }
  }
}
