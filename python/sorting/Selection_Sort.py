def Selection_Sort(data):
    for i in range(len(data) - 1):
        Min_Idx = i
        for k in range(i + 1, len(data)):
            if data[k] < data[Min_Idx]:
                Min_Idx = k