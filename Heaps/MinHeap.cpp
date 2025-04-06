#include <bits/stdc++.h>
using namespace std;

class MinHeap {
	private:
		int parent(int i){
			return (i-1)/2;
		}
		int left(int i){
			return 2*i + 1;
		}
		int right(int i){
			return 2*i + 2;
		}
		void heapifyUp(int i){
			while(i>0 && a[parent(i)] > a[i]){
				swap(a[parent(i)], a[i]);
				i = parent(i);
			}
		}
		void heapifyDown(int i){
			int lid = left(i);
			int rid = right(i);
			if(lid>last && rid>last)
				return;
			if(lid<=last && rid<=last){
				if(a[i]>a[lid] && a[i]>a[rid]){
					if(a[lid]>a[rid]){
						swap(a[i], a[rid]);
						heapifyDown(rid);
					} else {
						swap(a[i], a[lid]);
						heapifyDown(lid);
					}
					return;
				} 
			}
			if(lid<=last && a[i]>a[lid]) {
					swap(a[i], a[lid]);
					heapifyDown(lid);
			} else if(rid<=last && a[i]>a[rid]) {
					swap(a[i], a[rid]);
					heapifyDown(rid);
			}
			return;
		}
	public:
		int *a;
		int last;
		int cap;
		MinHeap(int sz){
			cap = sz;
			last=-1;
			a = new int[cap];
		}
		~MinHeap(){
			delete[] a;
		}
		int getMin(){
			if(last==-1){
				cerr << "Cannot get minima from empty heap" << endl;
				return INT_MIN;
			}
			return a[0];
		}
		int extractMin(){
			if(last==-1){
				cerr << "Cannot extract minima from empty heap" << endl;
				return INT_MIN;
			}
			int mn = getMin();
			swap(a[0], a[last--]);
			heapifyDown(0);
			return mn;
		}
		void insert(int val){
			if(last+1>=cap){
				cerr << "Cannot insert new element as maximum size of heap will exceed" << endl;
				return;
			}
			a[++last] = val;
			heapifyUp(last);
		}
		void increaseKey(int i, int new_val){
			if(i<0 || i>=cap){
				cerr << "Invalid index to increase key" << endl;
				return;
			}
			a[i]=new_val;
			heapifyDown(i);
		}
		void decreaseKey(int i, int new_val){
			if(i<0 || i>=cap){
				cerr << "Invalid index to decrease key" << endl;
				return;
			}
			a[i]=new_val;
			heapifyUp(i);
		}
		void print(){
			queue<int> q;
			q.push(0);
			while(!q.empty()){
				int tp = q.front();
				q.pop();
				cout << a[tp] << " ";
				if(left(tp)<=last)
					q.push(left(tp));
				if(right(tp)<=last)
					q.push(right(tp));
			}
		}
};

int main(){
	MinHeap* minHeap = new MinHeap(10);
	minHeap->insert(10);
	minHeap->insert(20);
	minHeap->insert(30);
	minHeap->insert(5);
	minHeap->insert(7);
	minHeap->increaseKey(0, 31);
	minHeap->print();
}