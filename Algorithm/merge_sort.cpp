#include <iostream>

void merge_sort(int* start, int n){
	if(n > 1) {
		int middle = n / 2;
		merge_sort(start, middle);
		merge_sort(start + middle, middle + n % 2);
		int temp[n];
		int i = 0;
		int j = middle;
		for (int k = 0; k < n; k++) {
			if (i > (middle - 1)) {
				temp[k] = start[j];
				j++;
			} else if (j > (n - 1)) {
				temp[k] = start[i];
				i++;
			} else if (start[i] < start[j]) {
				temp[k] = start[i];
				i++;
			} else {
				temp[k] = start[j];
				j++;
			}
		}
		for (int k = 0; k < n; k++) {
			start[k] = temp[k];
		}
	}
}


int main() {
	std::cout << "Hello, Merge Sort!" << std::endl;
	const int unsorted_size=10;
	int unsorted[unsorted_size]={6,4,3,9,5,2,1,7,8,10};
	std::cout<<"==== before sorted ===="<<std::endl;

	for(int i = 0; i < sizeof(unsorted)/sizeof(unsorted[0]);i++){
		std::cout<<unsorted[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"==== after sorted ===="<<std::endl;
	merge_sort(unsorted,unsorted_size);
	for(int i = 0; i < sizeof(unsorted)/sizeof(unsorted[0]);i++){
		std::cout<<unsorted[i]<<" ";
	}
	std::cout<<std::endl;

	for(int i = 1; i < sizeof(unsorted)/sizeof(unsorted[0]);i++) {
		assert(unsorted[i-1] < unsorted[i]);
	}
	return 0;
}
