#include <iostream>

void counting_sort(int unsorted[], int size, int max){
	int* temp = new int[max];
	for(int i = 0; i<max; i++){
		temp[i]=0;
	}

	for(int i = 0; i < size; i++){
		temp[unsorted[i]]++;
	}
	int i = 0;
	int j = 0;
	for(; i < max; i++){
		for(int k = 0 ; k < temp[i]; k++){
			unsorted[j] = i;
			j++;
		}
	}
	delete[] temp;
}
int main(){
	std::cout << "Hello, Counting Sort!" << std::endl;
	int unsorted[]={63,14,34,9,52,23,1,77,80,10,33,4,67,93,33,20,39,34,35,3,1};

	std::cout<<"==== before sorted ===="<<std::endl;

	for(int i = 0; i < sizeof(unsorted)/sizeof(unsorted[0]);i++){
		std::cout<<unsorted[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"==== after sorted ===="<<std::endl;
	counting_sort(unsorted,sizeof(unsorted)/sizeof(unsorted[0]),100);
	for(int i = 0; i < sizeof(unsorted)/sizeof(unsorted[0]);i++){
		std::cout<<unsorted[i]<<" ";
	}
	std::cout<<std::endl;

	for(int i = 1; i < sizeof(unsorted)/sizeof(unsorted[0]);i++) {
		assert(unsorted[i-1] <= unsorted[i]);
	}
	return 0;
}