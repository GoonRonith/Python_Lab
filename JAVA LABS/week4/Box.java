package week4;

public class Box extends ThreeDObject{
	double length;
	double height;
	double width;
	
	Box(double length,double height,double width){
		this.length=length;
		this.width=width;
		this.height=height;
	}

	@Override
	public double wholeSurafceArea() {
		// TODO Auto-generated method stub
		double surface_area=2*(this.height*this.width+this.length*this.width+this.length*this.height);
		return surface_area;
	}

	@Override
	public double volume() {
		// TODO Auto-generated method stub
		return this.length*this.width*this.height;
	}
	
	
}
