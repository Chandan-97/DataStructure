// Return lower bound index from vector v having non duplicated item created from array a, that can contain duplacate items
istream & operator >> (istream &in, vector <int> &v){
	for(int i=0; i<v.size(); i++)
		in>>v[i];
}
int n, q;
vector <int> a;
vector <pair<int, int> > v;
void input(){
	v.clear();
	cin>>n;
	a.resize(n);
	cin>>a;
	sort(a.begin(), a.end());
	v.pb(mp(a[0], 0));
	for(int i=1; i<n; i++){
		if(a[i] == a[i-1])
			continue;
		v.pb(mp(a[i], i));
	}
}

int lowerBoundIndex(int l){
	if(a[n-1] < l)
		return n;

	int st = 0;
	int nd = v.size()-1;

	// if element found
	while(st <= nd){
		int mid = (st + nd)/2;
		if(v[mid].first == l){
			return v[mid].second;
		}

		if(v[mid].first < l)
			st = mid+1;
		else
			nd = mid-1;
	}

	// element not found
	st = 0;
	nd = a.size()-1;

	auto it = lower_bound(a.begin(), a.end(), l);

	return it - a.begin();
}
