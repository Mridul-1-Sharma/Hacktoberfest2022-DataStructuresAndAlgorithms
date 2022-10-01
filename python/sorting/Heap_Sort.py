def heapify(data, n, i):
    largest, left, right = i, 2 * i + 1, 2 * i + 2
    if left < n and data[i] < data[left]:
        largest = left
    if right < n and data[largest] < data[right]:
        largest = right
    if largest != i:
        data[i], data[largest] = data[largest], data[i]
        heapify(data, n, largest)

def Heap_Sort(data):
    n = len(data)
    for i in range(n - 1, -1, -1):
        heapify(data, n, i)
    for i in range(n - 1, 0, -1):
        data[i], data[0] = data[0], data[i]
        heapify(data, i, 0)