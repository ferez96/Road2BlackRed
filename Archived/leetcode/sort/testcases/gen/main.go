package main

import (
	"fmt"
	"math/rand"
	"os"
	"path"
	"slices"
)

const TestDir = "/Users/mduong/Workspace/personal-code/leetcode/sort/testcases"
const MaxN = 1000
const MaxValue = 1e9

func generateTestCase(outputDir string, testNo int) {
	inputFileName := fmt.Sprintf("%d.in", testNo)
	inputFilePath := path.Join(outputDir, inputFileName)
	fmt.Println("Creating new test file: ", inputFilePath)
	file, err := os.Create(inputFilePath)
	if err != nil {
		fmt.Println("Fatal Error:", err)
		os.Exit(1)
	}

	// Generate a random array
	n := rand.Intn(MaxN)
	a := make([]int, 0, n)
	for range n {
		a = append(a, rand.Intn(MaxValue))
	}

	// Write the result out
	fmt.Fprintf(file, "%d\n", n)
	for _, x := range a {
		fmt.Fprintf(file, "%d ", x)
	}

	// sort the array
	slices.Sort(a)
	resultFileName := fmt.Sprintf("%d.ans", testNo)
	resultFilePath := path.Join(outputDir, resultFileName)
	fmt.Println("Creating new result file: ", resultFilePath)
	file2, err := os.Create(resultFilePath)
	if err != nil {
		fmt.Println("Fatal Error:", err)
		os.Exit(1)
	}
	for _, x := range a {
		fmt.Fprintf(file2, "%d ", x)
	}
}

func main() {
	fmt.Println("Start generate testcases for sorting workout")
	fmt.Printf("Tests will be written to: %s\n", TestDir)

	for i := range 20 {
		generateTestCase(TestDir, i+1)
	}
}
