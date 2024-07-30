public class Swap {

    public void sp(int a, int b) {
        int temp =a;
        a = b;
        b = temp;
    }
    
    public void run() {
        int a = 5;
        int b = 6;
        System.out.println("a= "+ a + " b= " + b);
        
        sp(a,b);
        
        System.out.println("a= "+ a + " b= " + b);
        
    }

    public static void main(String[] args) {

        Swap s = new Swap();
        s.run(); 
    }
}


  
