def binarySearch(arr, left, right, target):
    if left <= right:
        
        mid = int((left + right)/2)
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
           return binarySearch(arr, left, mid - 1, target)
        else:
          return  binarySearch(arr, mid + 1, right, target)
          
    else:
        return -1