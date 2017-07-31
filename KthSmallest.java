import java.io.*;
import java.util.*;

class MinHeap {

    int[] heap;
    int size;

    public MinHeap(int[] heap) {
        this.size = heap.length;
        this.heap = Arrays.copyOf(heap, size);
    }

    /**
     * Makes the array {@param a} satisfy the min heap property starting from
     * {@param index} till the end of array.
     * <p/>
     * Time complexity: O(log n).
     *
     * @param index
     */
    public void minHeapify(int index) {
        int smallest = index;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        if (leftIndex < size && heap[index] > heap[leftIndex]) {
            smallest = leftIndex;
        }
        if (rightIndex < size && heap[smallest] > heap[rightIndex]) {
            smallest = rightIndex;
        }

        if (smallest != index) {
            swap(index, smallest);
            minHeapify(smallest);
        }
    }

    /**
     * Converts array {@param a} in to a min heap.
     * <p/>
     * Time complexity: O(n) and is not O(n log n).
     */
    public void buildMinHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            minHeapify(i);
        }
    }

    public void insert(int elem) {
        heap = Arrays.copyOf(heap, size + 1);
        int i = size;
        int parentIndex = (int) Math.floor((i - 1) / 2);
        while (i > 0 && elem < heap[parentIndex]) {
            heap[i] = heap[parentIndex];
            i = parentIndex;
            parentIndex = (int) Math.floor((i - 1) / 2);
        }
        heap[i] = elem;
        size++;
    }

    public int findMin() {
        if (size == 0) {
            return -1;
        } else {
            return heap[0];
        }
    }

    public int extractMin() {
        if (size == 0)
            return -1;

        int min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        minHeapify(0);
        return min;
    }

    public int getSize() {
        return size;
    }

    public int[] getHeap() {
        return heap;
    }

    public void printHeap() {
        if (heap == null)
            System.out.print("null");
        int iMax = size - 1, i;
        if (iMax == -1)
            System.out.print("[]");

        StringBuilder b = new StringBuilder();
        b.append('[');
        for (i = 0; i < iMax; i++) {
            b.append(heap[i]);
            b.append(", ");
        }
        System.out.println(b.append(heap[i]).append(']').toString());
    }

    private void swap(int firstIndex, int secondIndex) {
        int temp = heap[firstIndex];
        heap[firstIndex] = heap[secondIndex];
        heap[secondIndex] = temp;
    }
}


class KthSmallest {

    public static int KthSmallestFunc(int arr[], int k) {
        MinHeap mh = new MinHeap(arr);
        mh.buildMinHeap();
        while (true) {
            if (k == 1)
                break;

            mh.extractMin();
            k--;
        }

        return mh.findMin();
    }

    public static void main(String[] args) {
        int arr[] = new int[] { 2, 4, 5, 7, 1, 8, 9 };
        System.out.println(Arrays.toString(arr));
        System.out.println(KthSmallestFunc(arr, 3));
    }
}