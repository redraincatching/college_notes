// Multithreaded server thats uses a thread per client

import java.io.*;
import java.net.*;

class MultithreadedTCPServer {
  public static void main(String a[]) throws IOException {
    int backlog = 10;  // Max queue size for pending connections
    int port = 4444;   // TCP port number to use for incoming connections
    Socket sock;

    // Create a ServerSocket that binds to all available IP addresses on this device
    ServerSocket servsock = new ServerSocket(port, backlog);

    while (true) {
      // wait for the next client connection
      sock=servsock.accept();
      // Create and start handler for client that has just connected
      TCPAccountClientHandler handler = new TCPAccountClientHandler(sock);
      handler.start();
      // Loop back up and listen for another connection (runs in parallel wiht handler)
    }
  }
}
