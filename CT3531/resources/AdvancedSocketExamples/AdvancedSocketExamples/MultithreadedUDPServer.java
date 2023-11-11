// Multithreaded server thats uses a thread per client

import java.io.*;
import java.net.*;

class MultithreadedUDPServer {
  public static void main(String a[]) throws IOException {
    // Create a DatagramSocket bound to UDP port 4000 to receive hello messages from clients
    DatagramSocket sock = new DatagramSocket(4000);

    while (true) {
      // Create a byte[] large enough to hold short hello message
      byte[] b = new byte[10];
      // Then create a DatagramPacket to receive hello message
      DatagramPacket rxpacket = new DatagramPacket(b, b.length);
      // Then wait to receive the next hello from a client
      sock.receive(rxpacket);
      System.out.println("Got hello message " +
        "\nFrom host: " + rxpacket.getAddress() +
        "\nHost port: " + rxpacket.getPort() +
        "\nLength: " + rxpacket.getLength() +
        "\nContaining: " + new String(rxpacket.getData(), 0, rxpacket.getLength()));
      // Create and start handler for client that has just connected
      UDPAccountClientHandler handler = new UDPAccountClientHandler(rxpacket);
      handler.start();
      // Loop back up and wait for another client hello message (runs in parallel with handler)
    }
  }
}
