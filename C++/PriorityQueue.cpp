#include <iostream>
#include <string>
//Reference from Introduction to Algorithms and Data structure by Corman  .
using namespace std;

template <class T>
class ArrayListType {
	public:
		T *arrList;                               
		int assignedSize;
		int size;
	public:
		ArrayListType();
		void setSize(int item);
		void addElement(T item);
		void displayArrList();
};

template <class T>
ArrayListType<T> :: ArrayListType() {
	this->size = 0;
}

template <class T>
//func. to set the no. of items
void ArrayListType<T> :: setSize(int item) {                 
	this->assignedSize = item;
	arrList = new T[item];
}

template <class T>
void ArrayListType<T> :: addElement(T item) {
	if((size + 1) > assignedSize) {
		cout << "Size overflow!" << endl;         
	}
	else {
		arrList[this->size] = item;
		this->size = this->size + 1;
	}
}

template <class T>
void ArrayListType<T> :: displayArrList() {
	int i;
	cout << "ArrayList contains: ";
	for(i=0; i<size; i++) {
		cout << arrList[i] << " ";                 
	}
	cout << endl;
} 

template <class T>
class PriorityQueue : public ArrayListType<T> {
	private:
		int heapSize;
	public:
		PriorityQueue(int size);
		void MaxHeapify(int i);
		void build_heap();
		T HeapExtractMax();
		void HeapIncreaseKey(int i, T key);
		void MaxHeapInsert(T key, T minElement);
};

template <class T>
PriorityQueue<T> :: PriorityQueue(int size) {
    //set size
	heapSize = size - 1;                                         
	this->size = 0;
}

template <class T>
void PriorityQueue<T> :: MaxHeapify(int i) {
	int left, right;
	int largest;
	T temp;
	
	left = 2 * i;
	right = 2 * i + 1;
	//MaxHeap function 
	if( (left <= this->heapSize) && (this->arrList[left] > this->arrList[i]) ) largest = left;   
	else largest = i;
	
	if( (right <= this->heapSize) && (this->arrList[right] > this->arrList[largest]) ) largest = right;
	if(largest != i) {
		temp = this->arrList[i];
		this->arrList[i] = this->arrList[largest];
		this->arrList[largest] = temp;
		MaxHeapify(largest);
	}
}

template <class T>
T PriorityQueue<T> :: HeapExtractMax() {
	T max;
	if(this->heapSize < 1) {
		cout << "Heap Underflow" << endl;		
	}                                                                    
	else {
	    //get max.
		max = this->arrList[0];
		this->arrList[0] = this->arrList[this->heapSize];
		this->heapSize = this->heapSize - 1;
		MaxHeapify(0);
	}
	return max;
}
template <class T>
void PriorityQueue<T>::build_heap()
{
int i;
for(i =(this->size/2)-1; i>=0; i--)
	MaxHeapify(i);
}

template <class T>
void PriorityQueue<T> :: HeapIncreaseKey(int i, T key) {
	if(key < this->arrList[i]) {
		cout << "New key is smaller than current key" << endl;
		return;
	}
	this->arrList[i] = key;
	while((i > 1) && (this->arrList[i/2] < this->arrList[i])) {
		T temp;
		temp = this->arrList[i];
		this->arrList[i] = this->arrList[i/2];
		this->arrList[i/2] = temp;
		i = i/2;
	}
}

template <class T>
void PriorityQueue<T> :: MaxHeapInsert(T key, T minElement) {
	if((this->heapSize + 1) > this->size ) {
		cout << "Array Overflow!" << endl;
		return;
	}
	else {
		this->heapSize = this->heapSize + 1;           
		//insert with minimum element
		this->arrList[this->heapSize] = minElement;
		HeapIncreaseKey(this->heapSize, key);                                       
	}
}

int main() {
	ArrayListType<int> ALObj;
	ArrayListType<string> ALObjStr;
	PriorityQueue<int> pqObj(10);
	PriorityQueue<string> pqObjStr(10);
	int i;                                                              
	//array list, priority queue objects
	ALObj.setSize(10);
	ALObjStr.setSize(10);
	cout <<" ------------------adding elements -------------"<<endl;
	for(i=0; i<10; i++) ALObj.addElement(i);
	//ALObj.displayArrList();
	cout<<"--------------------display -----------------------"<<endl;
	pqObj.setSize(10);
	for(i=0; i<10; i++) pqObj.addElement(i);
	//display elements in the array list
	pqObj.displayArrList();                                             
	pqObj.build_heap();
	pqObj.displayArrList();	
	cout << "Max Heap() Element Deleted: " << pqObj.HeapExtractMax() << endl;
	pqObj.displayArrList();
	//priority ,numbers
	pqObj.MaxHeapInsert(12, -9999);                                                               
	pqObj.displayArrList();                                                            
	pqObj.build_heap();
	cout << "After Build Heap => ";
	pqObj.displayArrList();
	cout << "Max Heap() Element Deleted: " << pqObj.HeapExtractMax() << endl;
	pqObj.displayArrList();
	
	pqObjStr.setSize(10);
	pqObjStr.addElement("abc");
	pqObjStr.addElement("def");
	pqObjStr.addElement("xyz");
	pqObjStr.addElement("dsf");                                                    
	pqObjStr.addElement("wer");
	pqObjStr.displayArrList();
	pqObjStr.build_heap();
	pqObjStr.build_heap();
	cout << "After MaxHeapify() => ";
	pqObjStr.displayArrList();
	cout << "Max Heap() Element Deleted: " << pqObjStr.HeapExtractMax() << endl;
	pqObjStr.displayArrList();
	pqObjStr.build_heap();
	cout << "After MaxHeapify() => ";
	pqObjStr.displayArrList();
	
	return 0;
}
