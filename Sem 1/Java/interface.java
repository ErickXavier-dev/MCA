interface cat{
  void meow();
}

interface dog {
  void bark();
}

class interfaceexample implements cat, dog {
  public void meow(){
    System.out.println("Meow");
  }
  public void bark(){
    System.out.println("Bark"); 
  }
  public static void main(String args[]){
    interfaceexample obj = new interfaceexample();
    obj.meow();
    obj.bark();
  }
}