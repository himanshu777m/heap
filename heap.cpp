#include<iostream>
using namespace std;

//class for heap
//pointer for heap array
//current size of array
//maximum size of array
//paramiter counstructor
//define parent, left, right
//insert using compare function
	//compare
	//if- extrime point
	//insert (Csize is zero -if)
//delete using MinHeapify
	//
	//
	//
	//
//dispaly

class Heap{
 public:
 
	int *arr;
	int C_size;
	int M_size;

	Heap(int M_size){
		arr = new int[M_size];
		this-> M_size=M_size;
		C_size = -1;
	}

	int parent(int i){
		return (i-1)/2;
	}

	int left(int i){
		return 2*i+1;
	}

	int right(int i){
		return 2*i+2;
	}

	void insert(int value){
		C_size++;
		
		if(C_size==0) arr[0]=value;
		else{
			arr[C_size]=value;
			compare(C_size);
		}
	}

	void compare(int i){
		if(arr[parent(i)]<=arr[i]|| i==0) return;
		else{
			swap(arr[parent(i)],arr[i]);
			compare(parent(i));
		}
	}


	void swap(int &a,int &b){
		int t=a;
		a=b;
		b=t;
	}

	int arr_min(){
		return arr[0];
	}
	
	/* Delete function without using minhepify 
	delete using loop
	
	//swap with parent
	void swap_p(int i){
		int t = arr[parent(i)];
		arr[parent(i)] = arr[i];
		arr[i] = t;	
	}
	
	void delet(int j){
		arr[j] = arr[C_size];
		C_size--;
		
		int i=j;
		while(left(i)<C_size){
			if(arr[left(i)] < arr[i]  &&  arr[right(i)] < arr[i]){
				return;
			}
			else if(arr[left(i)] >= arr[right(i)]){
				swap_p(left(i));
				i = left(i);
			}
			else if(arr[left(i)] < arr[right(i)]){
				swap_p(right(i));
				i = right(i);
			}
		}	
	} 
	
	*/


	int delet(int i){
		if(i>C_size || i<0){
			 cout<<"position is large"<<endl;
		}
		
		else{
			int a=arr[i];
			swap(arr[C_size],arr[i]);
			C_size--;
			MinHeapify(i);
			return a;
		}
	}

	void MinHeapify(int i){

			if(i>C_size) return;
			else if(left(i)>C_size) return;
			else if(arr[i]<arr[left(i)] && arr[i]<arr[right(i)]) return;
			else if(right(i)>C_size && left(i)<=C_size){
				 swap(arr[i],arr[left(i)]); 
			}
			else if(arr[left(i)]>arr[right(i)]) {
				swap(arr[right(i)],arr[i]);
				MinHeapify(right(i));
			}

			else {
				swap(arr[left(i)],arr[i]);
				MinHeapify(left(i));
			}
	}

	int extractmin(){
		return delet(0);
	}


	void display(){
		for(int i=0;i<=C_size;i++){
			cout<<arr[i]<<"->";
		}
		cout<<"NULL"<<endl;
	}
};


int main(){
	Heap h(20);

	h.insert(25);
	h.insert(12);
	h.insert(16);
	h.insert(13);
	h.insert(10);
	h.insert(8);
	h.insert(14);
	h.insert(11);
	h.insert(7);
	h.insert(4);
	h.insert(3);
	h.insert(8);
	h.insert(10);
	h.insert(5);
	h.insert(4);
	h.insert(6);

	h.display();
	h.extractmin();
	h.display();
	
	h.delet(4);
	h.display();

}		
