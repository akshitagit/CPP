// Removes the k-index element from the vector v [0. . n − 1]
// and returns the new value of n. Supposes 0 ≤ k <n.

int Remove (int k, int v[], int n) {
int j;
	for (j = k; j < n-1; j++)
		v[j] = v[j+1];
		return n - 1;
	}