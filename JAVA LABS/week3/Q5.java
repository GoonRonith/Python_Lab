package week3;

public class Q5 {
    public static void main(String[] args) {
        
        int[] array = {5, 10, 3, 8, 15, 7};

       
        int range = findRange(array);

    
        System.out.println("The range of the array is: " + range);
    }

   
    static int findRange(int[] arr) {
        if (arr.length == 0) {
         
            System.out.println("Array is empty. Range is undefined.");
            return 0;
        }

        
        int min = arr[0];
        int max = arr[0];

       
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < min) {
                min = arr[i];
            } else if (arr[i] > max) {
                max = arr[i];
            }
        }

        
        return max - min;
    }
}

