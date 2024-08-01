package week3;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

//1,6,7,9,10,14,15,16,17,18,21,22,23
public class Q1 {
	
	
	public static int[] mergeSortedArrays(int[] arr1, int[] arr2) {
        int len1 = arr1.length;
        int len2 = arr2.length;
        int[] mergedArray = new int[len1 + len2];

        int i = 0, j = 0, k = 0;

        
        while (i < len1 && j < len2) {
            if (arr1[i] <= arr2[j]) {
                mergedArray[k++] = arr1[i++];
            } else {
                mergedArray[k++] = arr2[j++];
            }
        }

    
        while (i < len1) {
            mergedArray[k++] = arr1[i++];
        }

        while (j < len2) {
            mergedArray[k++] = arr2[j++];
        }

        return mergedArray;
    }
	
	
	public static void printAlternateNumbers(int []arr) {
		for(int i=0;i<arr.length;i+=2) {
			System.out.println(arr[i]);
		}
	}
	
	public static void DuplicateElementsFrequency(int []array) {
		
        Map<Integer, Integer> frequencyMap = new HashMap<>();

        
        for (int num : array) {
         
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

       
        System.out.println("Duplicate Elements and their Frequencies:");
        for (Map.Entry<Integer, Integer> entry : frequencyMap.entrySet()) {
            if (entry.getValue() > 1) {
                System.out.println("Element: " + entry.getKey() + ", Frequency: " + entry.getValue());
            }
	}
	}
	
	public static void AddAndSortArrays(int []array1,int []array2) {
		 if (array1.length != array2.length) {
	            System.out.println("Arrays must have the same length.");
	            return;
	        }

	        
	        int[] sumArray = new int[array1.length];

	      
	        for (int i = 0; i < array1.length; i++) {
	            sumArray[i] = array1[i] + array2[i];
	        }

	        
	        Arrays.sort(sumArray);

	       
	        System.out.println("Array 1: " + Arrays.toString(array1));
	        System.out.println("Array 2: " + Arrays.toString(array2));
	        System.out.println("Sum Array: " + Arrays.toString(sumArray));
	}
	public static int findNonZeroElm(int []arr) {
		int count=0;
		for(int n:arr) {
			if(n!=0) count++;
		}
		return count;
	}
	 static float[] mergeArrays(float[] arr1, float[] arr2) {
	        int length1 = arr1.length;
	        int length2 = arr2.length;

	        float[] mergedArray = new float[length1 + length2];

	        System.arraycopy(arr1, 0, mergedArray, 0, length1);
	        System.arraycopy(arr2, 0, mergedArray, length1, length2);

	        return mergedArray;
	    }
	
	public static int findSecondHighest(int[] arr) {
    

        int highest = Integer.MIN_VALUE;
        int secondHighest = Integer.MIN_VALUE;

        for (int num : arr) {
            if (num > highest) {
                secondHighest = highest;
                highest = num;
            } else if (num > secondHighest && num != highest) {
                secondHighest = num;
            }
        }

        return secondHighest;
    }
	public static void searchElement(int []arr,int elm) {
		boolean flag=false;
		for(int n:arr) {
			if(n==elm) {
				flag=true;
				break;
			}
		}
		if(flag) {
			System.out.println("element found");
		}
		else {
			System.out.println("element not found");
		}
	}
	
	public static int sumOfEvenNumbers(int []arr) {
		int sum=0;
		for(int n:arr) {
			if(n%2==0) {
				sum+=n;
			}
		}
		return sum;
	}
	
	public static void reverseArray(int[] arr) {
        int start = 0;
        int end = arr.length - 1;

        while (start < end) {
            
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            
            start++;
            end--;
        }
    }
	
	 public static void printArray(int[] arr) {
	        for (int element : arr) {
	            System.out.print(element + " ");
	        }
	        System.out.println();
	    }
	
	 public static int getSmallestNumber(int[] arr) {
		 int small=arr[0];
		 for(int n:arr) {
			 if(small > n) {
				 small=n;
			 }
		 }
		 return small;
	 }
	 
	 public static int countPrimeNumbers(int[] arr) {
		 int count=0;
		 boolean flag;
		 for(int n:arr) {
			 flag=false;
			 for(int i=2;i<n/2;i++) {
				 if(n%i==0) {
					 flag=true;
					 break;
				 }
				 else {
					 flag=false;
				 }
			 }
			 if(!flag) count++;
		 }
		 return count;
	 }
	 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[]= {1,5,8,3,9};
		int a[]= {10,20,30,5,10};
		
		 float[] array1 = {1.5f, 2.5f, 3.5f};
	        float[] array2 = {4.5f, 5.5f, 6.5f};
	        
	    	int sort_arr1[]= {1,2,3,8,15};
			int sort_arr2[]= {6,45,100};
	        
		int avg,sum=0;
		for(int n:arr) {
			sum+=n;
		}
		avg=sum/arr.length;
		System.out.println("sum is->"+sum);
		System.out.println("average is->"+avg);
		
		int element=5;
		searchElement(arr, element);
		
		System.out.println("sum of even element is->"+sumOfEvenNumbers(arr));
		
		  System.out.println("Original Array: ");
	        printArray(arr);

	        reverseArray(arr);

	        System.out.println("Reversed Array: ");
	        printArray(arr);
	        
	        System.out.println("Smallest element is"+getSmallestNumber(arr));
	        
	        System.out.println("no of prime no is->"+countPrimeNumbers(arr));
	        
	        System.out.println("The second highest element is: " + findSecondHighest(arr));
	        System.out.println("no of non-zero elemnt is->"+findNonZeroElm(arr));
	        
	        float[] mergedArray = mergeArrays(array1, array2);

	        System.out.println("Merged Array: " + Arrays.toString(mergedArray));
	        
	        AddAndSortArrays(arr, a);
	        
	        DuplicateElementsFrequency(a);
	        
	        
	        printAlternateNumbers(arr);
	        
	        
	        int[] mergedArr = mergeSortedArrays(sort_arr1, sort_arr2);

	        System.out.println("Merged Sorted Array:");
	        for (int num : mergedArr) {
	            System.out.print(num + " ");
	        }
	        
		
	}

}
