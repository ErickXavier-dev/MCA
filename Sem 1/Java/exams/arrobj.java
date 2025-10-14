class product {
  int proid;
  String proname;

  product(int id, String name) {
    proid = id;
    proname = name;
  }

  void display() {
    System.out.println("Product ID: " + proid + "\nProduct Name: " + proname);
  }
}

class arrobj {
  public static void main(String args[]) {
    product arr[] = new product[3];
    arr[0] = new product(101, "Pen");
    arr[1] = new product(102, "Pencil");
    arr[2] = new product(103, "Eraser");

    System.out.println("Array of Objects: ");
    for (int i = 0; i < 3; i++) {
      arr[i].display();
      System.out.println();
    }
  }
}