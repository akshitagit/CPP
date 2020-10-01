def assign(a, n):
	
	# Sort the array
	a.sort()
	
	ans = [0] * n
	p = 0
	q = n - 1
	for i in range(n):
		
		# Assign even indexes with
		# maximum elements
		if (i + 1) % 2 == 0:
			ans[i] = a[q]
			q = q - 1
		
		# Assign odd indexes with
		# remaining elements
		else:
			ans[i] = a[p]
			p = p + 1
			
	# Print result
	for i in range(n):
		print(ans[i], end = " ")

# Driver Code
A = [ 1, 3, 2, 2, 5 ]
n = len(A)
assign(A, n)

