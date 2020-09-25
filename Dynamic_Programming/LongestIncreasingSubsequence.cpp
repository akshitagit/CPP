int Algo::LIS(vector<int> A){
	if(A.size()==0) return 0;
	vector<int> last;
	
	last.push_back(A[0]);
	for(int i=1;i<A.size();i++){
		if(A[i]<last[0]) last[0]=A[i];
		else if(A[i]>last[last.size()-1]) last.push_back(A[i]);
		else{
			int ind = lower_bound(last.begin(), last.end() ,A[i]) - last.begin();
			last[ind] = A[i];
		}
	}
	return last.size();
}