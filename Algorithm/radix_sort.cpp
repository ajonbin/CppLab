#include <iostream>
#include <array>
#include <vector>

void radix_sort(int* unsorted, int size){
	std::array<std::vector<int>,10> buckets;

	int max = 0;
	for(int i = 0; i < size; i++){
		if(unsorted[i] > max){
			max = unsorted[i];
		}
	}
	int digits = 0;
	while(max/(int)pow(10,digits) != 0){
		digits++;
	}
	for(int i = 0; i < digits; i++){
		for (int j = 0; j < size; j++){
			buckets[(unsorted[j]/(int)pow(10,i)) % 10].push_back(unsorted[j]);
		}
		int index = 0;
		for (int j = 0; j < 10; j++) {
			for (auto e: buckets[j]) {
				unsorted[index] = e;
				index++;
			}
			buckets[j].clear();
		}
	}

}

int main(){
	std::cout << "Hello, Radix Sort" << std::endl;

	const int unsorted_size=15;
	int unsorted[unsorted_size]={3243,23,1332,329,44,45,47,66,88,50,9,333,444,6780,109};

	std::cout<<"==== before sorted ===="<<std::endl;

	for(int i = 0; i < sizeof(unsorted)/sizeof(unsorted[0]);i++){
		std::cout<<unsorted[i]<<" ";
	}
	std::cout<<std::endl;

	std::cout<<"==== after sorted ===="<<std::endl;
	radix_sort(unsorted,unsorted_size);
	for(int i = 0; i < sizeof(unsorted)/sizeof(unsorted[0]);i++){
		std::cout<<unsorted[i]<<" ";
	}
	std::cout<<std::endl;

	for(int i = 1; i < sizeof(unsorted)/sizeof(unsorted[0]);i++) {
		assert(unsorted[i-1] < unsorted[i]);
	}

	int unsorted1[5] = {1,2,3,4,5};
	radix_sort(unsorted1,5);
	for(int i = 1; i < sizeof(unsorted1)/sizeof(unsorted1[0]);i++) {
		assert(unsorted1[i-1] < unsorted1[i]);
	}

	return 0;
}