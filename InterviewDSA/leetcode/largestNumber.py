from functools import cmp_to_key
#Find the largest number possible from a given set of numbers
@cmp_to_key
def custom_compare(a, b):
	value1 = str(a) + str(b)
	value2 = str(b) + str(a)

	if value1 < value2:
		return 1
	elif value1 > value2:
		return -1
	else:
		return 0


def findLargestNumber(numbers):
	# sort using a custom function object
	numbers.sort(key=custom_compare)

	# join and return
	return ''.join(map(str, numbers))


if __name__ == '__main__':
	numbers = [10, 68, 97, 9, 21, 12]

	largestNumber = findLargestNumber(numbers)
	print('The largest number is', largestNumber)
