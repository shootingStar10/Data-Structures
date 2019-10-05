using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryHeap
{
    public interface IBinaryHeap
    {
        int GetMin();
        int ExtractMin();
        void DecreaseKey(int idx, int newVal);
        void Insert(int key);
        void Delete(int idx);
    }
}
