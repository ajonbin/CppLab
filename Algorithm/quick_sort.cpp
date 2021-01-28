#include <iostream>

void quick_sort(int* orgin, int size){
	if(size <= 1){
		return;
	}
	int pivot = orgin[0];
	int left = 1;
	int right = size - 1;
	while(left <= (right -1)){
		for(;right > left; right--){
			if(orgin[right] < pivot){
				break;
			}
		}
		for(;left < right; left++){
			if(orgin[left] > pivot){
				break;
			}
		}
		if(left != right){
			std::swap(orgin[left],orgin[right]);
		}
	}
	if(orgin[left] < pivot)
		std::swap(orgin[left],orgin[0]);

	quick_sort(orgin,left);
	quick_sort(orgin+right,size-right);

}
int main(){
	std::cout << "Hello, Quick Sort" << std::endl;

	const int unsorted_size=10;
	int unsorted[unsorted_size]={3,2,1,9,4,5,7,6,8,0};

	std::cout<<"==== before sorted ===="<<std::endl;

	for(int i = 0; i < sizeof(unsorted)/sizeof(unsorted[0]);i++){
		std::cout<<unsorted[i]<<" ";
	}
	std::cout<<std::endl;

	std::cout<<"==== after sorted ===="<<std::endl;
	quick_sort(unsorted,unsorted_size);
	for(int i = 0; i < sizeof(unsorted)/sizeof(unsorted[0]);i++){
		std::cout<<unsorted[i]<<" ";
	}
	std::cout<<std::endl;

	for(int i = 1; i < sizeof(unsorted)/sizeof(unsorted[0]);i++) {
		assert(unsorted[i-1] < unsorted[i]);
	}

	int unsorted1[5] = {1,2,3,4,5};
	quick_sort(unsorted1,5);
	for(int i = 1; i < sizeof(unsorted1)/sizeof(unsorted1[0]);i++) {
		assert(unsorted1[i-1] < unsorted1[i]);
	}

	return 0;

}