#ifndef MINHEAP_H
#define MINHEAP_H

template <class Item>
void MinHeapfixUp(Item a[], int k)
  {
    while (k > 1 && a[k/2] > a[k])
      { exch(a[k], a[k/2]); k = k/2; }
  }


template <class Item>
void MinHeapfixDown(Item a[], int k, int N)
  {
    while (2*k <= N)
      { int j = 2*k;
        if (j < N && a[j] > a[j+1]) j++;
        if (!(a[k] > a[j])) break;
        exch(a[k], a[j]); k = j;
      }
  }


// heap based priority queue
template <class Item>
class MinHeapPQ
  {
    private:
      Item *pq; 
      int N;
    public:
		MinHeapPQ(int maxN)
        { pq = new Item[maxN+1]; N = 0; }
	  ~MinHeapPQ() { delete[] pq; } // Destructor
      int empty() const
        { return N == 1; }
      void insert(Item item)
        { pq[++N] = item;  MinHeapfixUp(pq, N); }
	  void stampa()
        { for(int i=1;i<=N;i++)
	       cout << pq[i] << " padre: " << pq[i/2] << endl;}
      Item getmin()
        { 
          exch(pq[1], pq[N]); 
		  MinHeapfixDown(pq, 1, N-1);
          return pq[N--]; 
        }
  };


#endif