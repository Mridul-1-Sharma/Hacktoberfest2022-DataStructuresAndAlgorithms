def partition(data, start, end):
    i = start + 1
    pivot = data[start]

    for j in range(start + 1, end + 1):
        if data[j] < pivot:
            data[i], data[j] = data[j], data[i]
            i += 1
    data[start], data[i - 1] = data[i - 1], data[start]
    return i - 1

def Quick_Sort(data, start, end):
    if start < end:
        pivot_position = partition(data, start, end)
        Quick_Sort(data, start, pivot_position - 1)
        Quick_Sort(data, pivot_position + 1, end)