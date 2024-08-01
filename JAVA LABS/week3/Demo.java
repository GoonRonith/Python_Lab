package week3;
import java.util.*;
public class Demo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter your marks->");
		int marks=sc.nextInt();
		if(marks<0 || marks>100) {
			System.out.println("Invalid marks...");
		}
		else {
			Grader gd=new Grader(marks);
			System.out.println("your grade is->"+gd.letterGrade(marks));
		}
		
		
	}

}
