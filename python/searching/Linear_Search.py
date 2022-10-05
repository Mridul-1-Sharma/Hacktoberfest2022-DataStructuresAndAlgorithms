def linearSearch(arr, elementToSearch):
  for x in arr:
    if x == elementToSearch:
      return arr.index(x)
  return -1


numArray = [10,2,3,44,5]
key = 10

result = linearSearch(numArray, key)

if(result != -1):
  print(f'Element Found at index {result}')
else:
  print("Element Not Found!!")