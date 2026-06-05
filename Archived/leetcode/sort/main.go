package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func swap(x, y *int) {
	t := *x
	*x = *y
	*y = t
}

func bubbleSort(n int, arr []int) {
	for i := range n {
		for j := i + 1; j < n; j++ {
			if arr[i] > arr[j] {
				swap(&arr[i], &arr[j])
			}
		}
	}
}

func ReadInput(testNo int) (length int, array []int, err error) {
	inputFilePath := fmt.Sprintf("./testcases/%d.in", testNo)
	file, err := os.Open(inputFilePath)
	if err != nil {
		return 0, nil, err
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)

	// scan array length
	scanner.Scan()
	nStr := scanner.Text()
	length, err = strconv.Atoi(nStr)
	if err != nil {
		return 0, nil, fmt.Errorf("invalid number value: %w", err)
	}

	// scan array values
	scanner.Scan()
	valuesStr := scanner.Text()
	values := strings.Fields(valuesStr)
	if length != len(values) {
		return 0, nil, fmt.Errorf("length and values mismatch")
	}

	// populate values to array
	array = make([]int, len(values))
	for i, v := range values {
		array[i], err = strconv.Atoi(v)
		if err != nil {
			return 0, nil, fmt.Errorf("invalid number value: %w", err)
		}
	}
	return length, array, nil
}

func ReadAnswer(testNo int) (array []int, err error) {
	answerFilePath := fmt.Sprintf("./testcases/%d.ans", testNo)
	file, err := os.Open(answerFilePath)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)

	// scan array values
	scanner.Scan()
	valuesStr := scanner.Text()
	values := strings.Fields(valuesStr)

	// populate values to array
	array = make([]int, len(values))
	for i, v := range values {
		array[i], err = strconv.Atoi(v)
		if err != nil {
			return nil, fmt.Errorf("invalid number value: %w", err)
		}
	}
	return array, nil
}

func main() {
	n, a, err := ReadInput(1)
	if err != nil {
		log.Panic(err)
	}

	bubbleSort(n, a)

	ans, err := ReadAnswer(1)
	if err != nil {
		log.Panic(err)
	}

	if len(a) != len(ans) {
		log.Println("Failed: Array length mismatch")
		return
	}
	for i := range len(a) {
		if a[i] != ans[i] {
			log.Printf("Failed: Expected %d - Got: %d\n", ans[i], a[i])
			return
		}
	}
	log.Println("Passed")
}
