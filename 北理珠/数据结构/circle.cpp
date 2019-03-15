#include<cstdio>
#define PI 3.14159
#define FENCEPRICE 21.5
#define CONCERNPRICE 3.5 
using namespace std;

class Circle{
	private:
		double radius;
	public:
		Circle(double r)
		{
			InputRadius(r);
		}
		void InputRadius(double r)
		{
			this -> radius = r;
		}
		double GetArea()
		{
			return PI*radius*radius;
		}
		double GetCircumference()
		{
			return 2*PI*radius;
		}
};

int main()
{
	double r;
	double fenceCost,concreteCost;
	
	printf("Please input the radius of the pool:");
	scanf("%lf",&r);
	Circle pool(r),poolRim(r+3);
	fenceCost = poolRim.GetCircumference()*FENCEPRICE;
	concreteCost = (poolRim.GetArea()-pool.GetArea())*CONCERNPRICE;
	printf("Fence cost is %f.\n",fenceCost);
	printf("Concrete cost is %f.\n",concreteCost);
	return 0;
} 
