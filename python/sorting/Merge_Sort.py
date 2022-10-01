def merge(data, start, mid, end):
    L = data[start : mid + 1]
    R = data[mid + 1: end + 1]
    L_idx, R_idx, S_idx = 0, 0, start
    while L_idx < len(L) and R_idx < len(R):
        if L[L_idx] <= R[R_idx]:
            data[S_idx] = L[L_idx]
            L_idx += 1
        else:
            data[S_idx] = R[R_idx]
            R_idx += 1
        S_idx += 1
    while L_idx < len(L):
        data[S_idx] = L[L_idx]
        L_idx += 1; S_idx += 1

    while R_idx < len(R):
        data[S_idx] = R[R_idx]
        R_idx += 1; S_idx += 1


def Merge_Sort(data, start, end):
    if start < end:
        mid = int((start + end) / 2)
        Merge_Sort(data, start, mid)
        Merge_Sort(data, mid + 1, end)
        merge(data, start, mid, end)