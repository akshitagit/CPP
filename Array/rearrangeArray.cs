// C# program to rearrange the elements
// in array such that even positioned are
// greater than odd positioned elements
using System;

class Array {

	static void assign(int[] a, int n)
	{
		// Sort the array
		Array.Sort(a);

		int[] ans = new int[n];
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
			Console.Write(ans[i] + " ");
	}

	
	public static void Main()
	{
		int[] A = { 1, 3, 2, 2, 5 };
		int n = A.Length;
		assign(A, n);
	}
}
