def Insertion_Sort(data):
    for i in range(len(data)):
        temp = data[i]
        k = i
        while k > 0 and temp < data[k - 1]:
            data[k] = data[k - 1]; k -= 1
        data[k] = temp