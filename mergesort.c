#include <stdio.h>
#include <string.h>

int main()
{
	int i,j,k,n=15,size,low1,high1,low2,high2;
	char arr[15]= "ASORTINGEXAMPLE";
	char temp[15];


	

	/*low1 low2 high1 and high2 set the bounds for the iterations of the divided parts of the array*/
	/*This for loop increments the size of the subarray by size*2 until size>n*/
	for(size=1; size < n; size=size*2 )
	{
		low1=0;
		k=0;  /*Index of temp array*/
		while( low1+size < n)
		{
			high1=low1+size-1;
			low2=high1+1;
			high2=low2+size-1;
			/* sets h2 to equal size of arr minus 1 if it excedes n*/
			if( high2>=n ) 
				high2=n-1;
			
			/*Sets where the merge will take place from in the given divided array*/
			i=low1;
			j=low2;
			/*merges the divided array*/
			while(i<=high1 && j<=high2 )
			{
				if( arr[i] <= arr[j] )
					temp[k++]=arr[i++];
				else
					temp[k++]=arr[j++];
			}
			
			while(i<=high1)
				temp[k++]=arr[i++];
			while(j<=high2)
				temp[k++]=arr[j++];
			/*completes the given merge and moves on to the next part of the divided array*/
			low1=high2+1; 
		}

		/*takes any remaining values and places it in the sorted array */
		for(i=low1; k<n; i++) 
			temp[k++]=arr[i];
		/*creates the sorted array based of the values in temp array*/
		for(i=0;i<n;i++)
			arr[i]=temp[i];
		/*prints the array after each iteration*/
		printf("\nSize=%d \nElements are : ",size);
			printf(arr);
		
	}
	
	printf("The sorted array is :\n");
		printf( arr);
	
	printf("\n");
	
	return 0;
}