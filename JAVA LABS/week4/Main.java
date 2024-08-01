package week4;
import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		
		System.out.println("enter length height and width of the box->");
		int length=sc.nextInt();
		int height=sc.nextInt();
		int width=sc.nextInt();
		Box box=new Box(length,height,width);
		System.out.println("surface area of box is-->"+box.wholeSurafceArea());
		System.out.println("volume of box is-->"+box.volume());
		
		System.out.println("enter sidelength  of the cube->");
		int sidelength=sc.nextInt();
		Cube cube=new Cube(sidelength);
		System.out.println("surface area of cube is-->"+cube.wholeSurafceArea());
		System.out.println("volume of cube is-->"+cube.volume());
		
		
		System.out.println("enter  height and radius of the cylinder->");
		int radius=sc.nextInt();
		int height_cylinder=sc.nextInt();
		Cylinder cylinder=new Cylinder(radius,height_cylinder);
		System.out.println("surface area of cylinder is-->"+cylinder.wholeSurafceArea());
		System.out.println("volume of cylinder is-->"+cylinder.volume());
	}

}
