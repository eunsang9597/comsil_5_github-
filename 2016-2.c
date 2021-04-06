#include<stdio.h> 
#include<stdlib.h> 

typedef struct{
	double x;
	double y;
	double z;
}coordinate;
void Input(coordinate* p1,coordinate* p2)
{
	printf("%lf %lf\n", p1->y,p2->y); 
	p1->x = p2->x - p1->x;
	p1->y = p2->y - p1->y;
	p1->z = p2->z - p1->z; 
	printf("%lf %lf\n", p1->y,p2->y); 
}
int Orthogonal(coordinate p1, coordinate p2)
{
	if((p1.x*p2.x + p1.y*p2.y + p1.z*p2.z)==0)
		return 1;
	return 0; 
}
int main()
{
	coordinate p1; 
	coordinate p2; 
	coordinate p3; 
	scanf("%lf %lf %lf",&p1.x,&p1.y,&p1.z);
	scanf("%lf %lf %lf",&p2.x,&p2.y,&p2.z); 
	Input(&p1,&p2); 
	printf("%lf %lf %lf\n",p1.x,p1.y,p1.z);
	scanf("%lf %lf %lf",&p2.x, &p2.y, &p2.z); 
	scanf("%lf %lf %lf",&p3.x, &p3.y, &p3.z); 
	Input(&p2, &p3); 
	printf("%lf %lf %lf\n",p2.x,p2.y,p2.z); 
	if(Orthogonal(p1,p2))
		printf("Orthogonal\n");
	else 
		printf("Not Orthogonal\n"); 

	return 0;
}
