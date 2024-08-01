package week4;

public class Cylinder extends ThreeDObject {
	double radius;
	double height;
	
	public Cylinder(double radius,double height) {
		this.radius=radius;
		this.height=height;
	}

	@Override
	public double wholeSurafceArea() {
		// TODO Auto-generated method stub
		double surface_area=(this.radius*this.radius)*2*(3.14)+2*3.14*this.radius*this.height;
		return surface_area;
	}

	@Override
	public double volume() {
		// TODO Auto-generated method stub
		return 3.14*this.radius*this.radius*this.height;
	}
}
