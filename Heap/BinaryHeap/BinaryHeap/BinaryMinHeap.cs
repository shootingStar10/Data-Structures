using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryHeap
{
    public class BinaryMinHeap : IBinaryHeap
    {
        private int Capacity;
        public int HeapSize;
        private int[] H;

        public BinaryMinHeap(int capacity)
        {
            Capacity = capacity;
            HeapSize = 0;
            H = new int[capacity];
        }

        public void DecreaseKey(int idx, int newVal)
        {
            H[idx] = newVal;

            while (idx != 0 && H[GetParent(idx)] > H[idx])
            {
                int temp = H[idx];
                H[idx] = H[GetParent(idx)];
                H[GetParent(idx)] = temp;
                idx = GetParent(idx);
            }
        }

        public void Delete(int idx)
        {
            DecreaseKey(idx, int.MinValue);
            ExtractMin();
        }

        public int ExtractMin()
        {
            if (HeapSize <= 0)
            {
                return int.MaxValue;
            }

            if (HeapSize == 1)
            {
                HeapSize--;
                return H[0];
            }

            int retVal = H[0];

            H[0] = H[HeapSize - 1];
            HeapSize--;
            MinHeapify(0);

            return retVal;
        }

        public int GetMin()
        {
            return H[0];
        }

        public void Insert(int key)
        {
            if (HeapSize == Capacity)
            {
                Console.WriteLine("Heap Overflow");
                return;
            }

            H[HeapSize] = key;
            int i = HeapSize;
            HeapSize++;

            while (i != 0 && H[GetParent(i)] > H[i])
            {
                int temp = H[i];
                H[i] = H[GetParent(i)];
                H[GetParent(i)] = temp;
                i = GetParent(i);
            }
        }

        private void MinHeapify(int idx)
        {
            int l = GetLeftChild(idx);
            int r = GetRightChild(idx);
            int smallest;

            if (l < HeapSize && H[l] < H[idx])
            {
                smallest = l;
            }
            else
            {
                smallest = idx;
            }

            if (r < HeapSize && H[r] < H[smallest])
            {
                smallest = r;
            }

            if (smallest != idx)
            {
                int temp = H[smallest];
                H[smallest] = H[idx];
                H[idx] = temp;
                MinHeapify(smallest);
            }
        }

        private int GetParent(int idx)
        {
            return (idx-1)/2;
        }

        private int GetLeftChild(int idx)
        {
            return (2 * idx) + 1;
        }

        private int GetRightChild(int idx)
        {
            return (2 * idx) + 2;
        }
    }
}
