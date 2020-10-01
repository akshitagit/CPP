import java.io.*;
import java.util.*;

class Array {

	static void assign(int a[], int n)
	{

		// Sort the array
		Arrays.sort(a);

		int ans[] = new int[n];
		int p = 0, q = n - 1;
		for (int i = 0; i < n; i++) {

			// Assign even indexes with maximum elements
			if ((i + 1) % 2 == 0)
				ans[i] = a[q--];

			// Assign odd indexes with remaining elements
			else
				ans[i] = a[p++];
		}

		// Print result
		for (int i = 0; i < n; i++)
			System.out.print(ans[i] + " ");
	}
	public static void main(String args[])
	{
		int A[] = { 1, 3, 2, 2, 5 };
		int n = A.length;
		assign(A, n);
	}
}

