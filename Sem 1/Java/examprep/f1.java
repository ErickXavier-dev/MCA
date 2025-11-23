import java.io.*;
import java.util.Scanner;
class FileWriteRead {
  static void fileWriting()throws IOException {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the content to write");
    String msg = sc.nextLine();
    BufferedWriter writer = new BufferedWriter(new FileWriter("\\myfile.txt"));
    writer.write(msg);
    writer.close();
  }
  static void fileReading() throws IOException{
    BufferedReader br = new BufferedReader(new FileReader("\\myfile.txt"));
    String line;
    while((line=br.readLine())!=null){
      System.out.println(line);
    }
  }
  public static void main(String[] args) throws IOException{
    fileWriting();
    fileReading();
  }
}