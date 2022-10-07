package main

import "fmt"

type Stack []string

// IsEmpty: check if stack is empty
func (s *Stack) IsEmpty() bool {
	return len(*s) == 0
}

// Push a new value onto the stack
func (s *Stack) Push(str string) {
	*s = append(*s, str) // Simply append the new value to the end of the stack
}

// Remove and return top element of stack. Return false if stack is empty.
func (s *Stack) Pop() (string, bool) {
	if s.IsEmpty() {
		return "", false
	} else {
		index := len(*s) - 1   // Get the index of the top most element.
		element := (*s)[index] // Index into the slice and obtain the element.
		*s = (*s)[:index]      // Remove it from the stack by slicing it off.
		return element, true
	}
}

// peek
func (s *Stack) peek() {
	if s.IsEmpty() {
		fmt.Print("Underflow.")
		return
	} else {
		index := len(*s) - 1
		fmt.Println((*s)[index])
	}
}

func main() {
	var stack Stack // create a stack variable of type Stack

	stack.Push("this")
	stack.Push("is")
	stack.Push("sparta!!")
	stack.peek()

	for len(stack) > 0 {
		x, y := stack.Pop()
		if y == true {
			fmt.Println(x)
		}
	}
}
