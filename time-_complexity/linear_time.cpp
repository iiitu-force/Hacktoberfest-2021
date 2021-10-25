#include<stdio.h>
#include<stdlib.h>

//function to swap by reference
void swap(int*a,int*b){
	int temp;
	temp=*b;
	*b=*a;
	*a=temp;
	return;
}
int* asort(int *a,int n){
	int low=0,mid=0,high=n-1;   //variables are set
	
	while(mid<=high){
		switch(a[mid]){
			case 0:     //if a[mid]==0
				//swap a[low] & a[mid], swapping by reference
				swap(&a[low],&a[mid]);  
				low++;      //increment low
				mid++;      //increment mid
				break;
			case 1:     //if a[mid]==1
				mid++;      //increment mid
				break;
			case 2:     //if a[mid]==2
				//swap a[mid] & a[high], swapping by reference
				swap(&a[mid],&a[high]);  
				high--;     //decrement high
				break;
		}
	}
	//returning adress of array(sorted)
	return a;   
}

int main() {
	int n;

	printf("enter no of array elements\n");
	//input array length
	scanf("%d",&n);

	int* a=(int*)malloc(sizeof(int)*n);

	printf("enter array elements\n");
	//input array elements
	for(int j=0;j<n;j++)      
		scanf("%d",&a[j]);
	//array is modified
	a=asort(a,n);   
	printf("after being sorted..............\n");
	//printing the sorted array
	for(int j=0;j<n-1;j++)   
		printf("%d ",a[j]);
	
	printf("%d\n",a[n-1]);

	return 0;
}

