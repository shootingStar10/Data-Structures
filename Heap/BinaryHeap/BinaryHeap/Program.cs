using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryHeap
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryMinHeap minHeap = new BinaryMinHeap(11);

            minHeap.Insert(3);
            minHeap.Insert(5);
            minHeap.Insert(1);
            minHeap.Insert(6);
            minHeap.Insert(8);
            minHeap.Insert(9);

            Console.WriteLine("Heap size: " + minHeap.HeapSize);
            Console.WriteLine("Minimum element of heap: " + minHeap.GetMin());
            Console.WriteLine("Extracting minimum element: " + minHeap.ExtractMin());
            Console.WriteLine("Minimum element of heap: " + minHeap.GetMin());
            Console.WriteLine("Deleting element from heap: ");
            minHeap.Delete(3);
            Console.WriteLine("Heap size: " + minHeap.HeapSize);
            Console.WriteLine("Minimum element of heap: " + minHeap.GetMin());

            Console.ReadKey();
        }
    }
}
