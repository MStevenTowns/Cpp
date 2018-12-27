#include <cstdio>

class circle
{
	private:
		double radius;
		static const double PI = 3.14;
		
	public:
		circle(double r);
		circle();
	
		double get_radius();
		double circumference();
		double area();
		
		void set_radius(double r);
};

circle::circle(double r)
{
	radius = r;
}

circle::circle()
{
	radius = 1;
}


double circle::get_radius()
{
	return radius;
}

double circle::circumference()
{
	return 2 * radius * PI;
}

double circle::area()
{
	return PI * (radius * radius);
}

void circle::set_radius(double r)
{
	radius = r;
}

int main()
{
	circle * c1 = new circle(10);
	
	printf("Radius: %.2f\n", c1 -> get_radius());
	printf("Circumference: %.2f\n", c1 -> circumference());
	printf("Area:  %.2f\n", c1 -> area());
	
	return 0;
}
