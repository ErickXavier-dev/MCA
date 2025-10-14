class Test {
    int a = 456; // instance variable

    public void trail(int a) {  // non-static method
        System.out.println("Local a (method parameter): " + a);   // parameter variable
        System.out.println("Instance a (using this): " + this.a); // instance variable
    }

    public static void main(String[] args) {
        Test obj = new Test();   // create an object to access non-static method
        obj.trail(123);          // call method with parameter
    }
}
