class book {
  String title, author;
  int price;
  
  book() {
    title = "Unknown";
    author = "Unknown";
    price = 0;
  }

  book(String t, String a, int p) {
    title = t;
    author = a;
    price = p;
  }
  
  book(String t, String a) {
    title = t;
    author = a;
  }

  void displayDetails() {
    System.out.println("Book Title: " + title);
    System.out.println("Book Author: " + author);
    System.out.println("Book Price: " + price);
  }
}

class books {
  public static void main(String args[]) {
    book b1 = new book();
    book b2 = new book("The Great Gatsby", "F. Scott Fitzgerald", 10);
    book b3 = new book("1984", "George Orwell");

    System.out.println("Details of Book 1:");
    b1.displayDetails();
    
    System.out.println("\nDetails of Book 2:");
    b2.displayDetails();
    
    System.out.println("\nDetails of Book 3:");
    b3.displayDetails();
  }
}