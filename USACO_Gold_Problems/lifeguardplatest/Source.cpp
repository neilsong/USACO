#include <bits/stdc++.h>
using namespace std;

int partition1(int arr[], int l, int r, int k);

// A simple function to find median of arr[].  This is called 
// only for an array of size 5 in this program. 
int findMedian(int arr[], int n)
{
	sort(arr, arr + n);  // Sort the array 
	return arr[n / 2];   // Return middle element 
}

// Returns k'th smallest element in arr[l..r] in worst case 
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT 
int kthSmallest(int arr[], int l, int r, int k)
{
	// If k is smaller than number of elements in array 
	if (k > 0 && k <= r - l + 1)
	{
		int n = r - l + 1; // Number of elements in arr[l..r] 

		// Divide arr[] in groups of size 5, calculate median 
		// of every group and store it in median[] array. 
		int i, median[(n + 4) / 5]; // There will be floor((n+4)/5) groups; 
		for (i = 0; i < n / 5; i++)
			median[i] = findMedian(arr + l + i * 5, 5);
		if (i * 5 < n) //For last group with less than 5 elements 
		{
			median[i] = findMedian(arr + l + i * 5, n % 5);
			i++;
		}

		// Find median of all medians using recursive call. 
		// If median[] has only one element, then no need 
		// of recursive call 
		int medOfMed = (i == 1) ? median[i - 1] :
			kthSmallest(median, 0, i - 1, i / 2);

		// Partition the array around a random element and 
		// get position of pivot element in sorted array 
		int pos = partition1(arr, l, r, medOfMed);

		// If position is same as k 
		if (pos - l == k - 1)
			return pos;
		if (pos - l > k - 1)  // If position is more, recur for left 
			return kthSmallest(arr, l, pos - 1, k);

		// Else recur for right subarray 
		return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}

	// If k is more than number of elements in array 
	return INT_MAX;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// It searches for x in arr[l..r], and partitions the array  
// around x. 
int partition1(int arr[], int l, int r, int x)
{
	// Search for x in arr[l..r] and move it to end 
	int i;
	for (i = l; i < r; i++)
		if (arr[i] == x)
			break;
	swap(&arr[i], &arr[r]);

	// Standard partition algorithm 
	i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

struct State {
	int time;
	int index;
};


State newState(int a, int b) {
	State A;
	A.time = a;
	A.index = b;
	return A;
}

bool sortbytime(const State& a, const State& b) {
	return a.time < b.time;
}





/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}




int main(void) {

	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");

	std::set <int> set;
	int n,k;
	cin >> n >> k;
	vector <State> l(2 * n);

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		l[2 * i] = newState(start, i);
		l[2 * i + 1] = newState(end, i);
	}
	sort(l.begin(), l.end(), sortbytime);
	int actualCover = 0;
	int alone[n];
	int last = 0;
	for (State out : l) {
		if (set.size() == 1) {
			alone[*set.begin()] += out.time - last;
		}
		if (!set.empty()) {
			actualCover += out.time - last;
		}
		if (set.find(out.index) != set.end()) {
			set.erase(out.index);
		}
		else {
			set.insert(out.index);
		}
		last = out.time;
	}
	int ksmall = kthSmallest(alone, 0, n - 1, k);
	quickSort(alone, 0, ksmall);
	for (int i = 0; i < k; i++) {
		actualCover -= alone[i];
	}
	cout << actualCover << endl;
	return 0;
}

