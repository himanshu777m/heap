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
			else if(2*i+1>C_size) return;
			else if(arr[i]<arr[2*i+1] and arr[i]<arr[2*i+2]) return;
			else if(2*i+2>C_size and 2*i+1<=C_size){
				 swap(arr[i],arr[2*i+1]); 
			}
			else if(arr[2*i+1]>arr[2*i+2]) {
				swap(arr[2*i+2],arr[i]);
				MinHeapify(2*i+2);
			}

			else {
				swap(arr[2*i+1],arr[i]);
				MinHeapify(2*i+1);
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
	Heap h(13);

	for(int i=10;i>0;i--){
		h.insert(i);	
	}

	h.display();
	h.extractmin();
	h.display();
	
	h.delet(4);
	h.display();

}		
