# include<bits/stdc++.h>
using namespace std;

class point         //co-ordinate points (x,y)
{
    public:
    int x;
    int y;
};

float f1(point p[],int);
float f2(point p[],int,float);
float dist(point p1,point p2);
float bf(point P[], int );

int compareX(const void* a, const void* b)              //comparing the x coordinate of points
{
    point *p1 = (point *)a, *p2 = (point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)              //comparing the y coordinate of points
{
    point *p1 = (point *)a, *p2 = (point *)b;
    return (p1->y - p2->y);
}

int main()
{
    int n,i;
    cin>>n;                             //number of points

    point arr[n];                       //arr[] stores the x and y coordinate of a point

    for(i=0;i<n;i++)
        cin>>arr[i].x>>arr[i].y;

    qsort(arr,n,sizeof(point),compareX);                //sort according to x coordinate
    cout<< fixed <<setprecision(5) << f1(arr,n);
    return 0;
}

float f1(point p[],int n)
{
    if(n<=3)
        return bf(p,n);

    float point1,point2;

    int mid=n/2;

    point midpoint=p[mid];                  //The reference line from where distance is measured

    point1=f1(p,mid);
    point2=f1(p+mid,n-mid);
    float d=min(point1,point2);

    point strip[n];
    int j=0,i;

    for(i=0;i<n;i++)
    {
        if(abs(p[i].x-midpoint.x)<d)
        {
            strip[j++]=p[i];
        }
    }

    return min(d,f2(strip,j,d));
}

float f2(point strip[],int n,float d)
{
    float mini=d;
    int i,j;

    qsort(strip,n,sizeof(point),compareY);              //sort according to Y coordinate

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n &&(strip[j].y-strip[i].y<mini);j++)
            if(dist(strip[i],strip[j])<mini)
                mini=dist(strip[i],strip[j]);
    }

    return mini;
}

float dist(point p1,point p2)
{
    return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));         //return the distance between two points
}

float bf(point P[], int n)
{
	float mini = FLT_MAX;

	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (dist(P[i], P[j]) < mini)
				mini = dist(P[i], P[j]);                    //mini is the minimum distance

	return mini;
}
