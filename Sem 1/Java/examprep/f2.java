import java.util.*;
import java.io.*;

class student{
  String stname = "Erick Xavier", stdno = "123", prg = "MCA", yr = "2025";
}

class writeread {
  public void writer(String sn, String stn, String prgm, String yr){
    try{
      FileWriter fw = new FileWriter("E:/Sem 1/Java/examprep/studentdetail.txt");
      fw.write(sn+" "+stn+" "+prgm+" "+yr);
    } catch (IOException e){
      System.out.println(e);
    }
  }
  
  public void reader(){
    try{
      FileReader fr = new FileReader("/Sem 1/Java/examprep/studentdetail.txt");
      int i = 0;
      while(i != -1){
        i = fr.read();
        System.out.print((char)i);
      }
    } catch (IOException e) {
      System.out.println(e);
    }
  }

  public static void main(String args[]){
    student s1 = new student();
    writeread wr = new writeread();
    wr.writer(s1.stname, s1.stdno, s1.prg, s1.yr);
    wr.reader();
  }
}