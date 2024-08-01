package week3;
//24,25,26
public class ConstructorExample {
    
    // 0 Argument (Default) Constructor
    public ConstructorExample() {
        System.out.println("Default constructor called.");
    }

    // Parameterized Constructor
    public ConstructorExample(int intValue, String stringValue) {
        System.out.println("Parameterized constructor called with values: " + intValue + ", " + stringValue);
    }

    // Constructor Overloading
    public ConstructorExample(double doubleValue) {
        System.out.println("Overloaded constructor called with value: " + doubleValue);
    }

    public static void main(String[] args) {
        // Creating objects using different constructors
        ConstructorExample defaultConstructorObj = new ConstructorExample();
        ConstructorExample parameterizedConstructorObj = new ConstructorExample(42, "Hello");
        ConstructorExample overloadedConstructorObj = new ConstructorExample(3.14);
    }
}

