import java.util.*;
public class RadixSort {
	static int n;
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println("No. of elements in array? ");
		n = s.nextInt();
		int a[] = new int[n];
		System.out.println("Enter the array elements- ");
		for(int i=0;i<n;i++)
			a[i] = s.nextInt();
		System.out.println("The unsorted array is - ");
		for(int i=0;i<n;i++)
			System.out.print(a[i] + " ");
		radixSort(a,n);
		
		System.out.println("\n\nThe sorted array is- ");
		for(int i=0; i<n; i++)
			System.out.print(a[i] + " ");
	}
	
	public static int max(int a[])
	{
		int maximum = a[0];
		for(int i =1;i<n;i++)
			if(a[i] > maximum)
				maximum = a[i];
		return maximum;
	}
	
	public static void radixSort(int a[],int n)
	{
		int max = max(a);
		for(int pos=1;max/pos>0;pos=pos*10)
			countSort(a,n,pos);
	}
	
	public static void countSort(int a[], int n, int pos)
	{
		int res[] = new int[n];
		int count[] = new int[10];
		int i;
		
		for(i=0;i<n;i++)
			++count[(a[i]/pos) % 10];
		
		for(i=1;i<10;i++)
			count[i] += count[i-1];
		
		for(i=n-1;i>=0;i--)
			res[--count[(a[i]/pos) % 10]] = a[i];
		
		for(i=0;i<n;i++)
			a[i] = res[i];
	}
}
