package main

import (
	"fmt"
)

/**
Approaches:

Look 1: Groups of task
If one task (e.g: A) located at x => from x+1 to x+n must not be A
If one type of task (e.g: A) have k occurs => there must be at least (k-1)*(n+1)+1 CPU intervals to complete them

The presentation will be look like this:
A _ _
A _ _
A _ _
A

If a cycle (A _ _) is completed, the sub-task have the same constraints with the task but will smaller space.

We can develop a forward greedy solution:

1. If every tasks have only 1 representation, list all of them sequencely
2. If the most frequent task (A) has more than 1 (>=2) reps. => create A _ _ and fill as many pots as possible
2.1. asnwer += (n+1) | the next start still fresh
2.2. select n tasks to fill in
3. Update state for new sub-task
3.1. every tasks selected => reduce count by 1
3.2. reduce A count by 1
3.3. add all non-empty tasks back to the collection
4. repeat

*/

type TaskGroup struct {
	Type  byte
	Count int
}

type TaskGroupHeap struct {
	size int
	heap []TaskGroup
}

func NewHeap(alloc int) *TaskGroupHeap {
	return &TaskGroupHeap{
		size: 0,
		heap: make([]TaskGroup, alloc+1), // 1-indexed
	}
}

func (h *TaskGroupHeap) Size() int {
	return h.size
}

func (h *TaskGroupHeap) Push(tg TaskGroup) {
	h.size++
	h.heap[h.size] = tg
	h.heapUp(h.size)
}

func (h *TaskGroupHeap) Pop() TaskGroup {
	copied := h.heap[1]
	h.swap(1, h.size)            // move the heap root to the last item to safely pop out, the heap lost its order
	h.heap[h.size] = TaskGroup{} // remove the last item, which is poping out
    h.size--    
	h.heapDown(1)	
	return copied
}

func (h *TaskGroupHeap) swap(pos1, pos2 int) {
	t := h.heap[pos1]
	h.heap[pos1] = h.heap[pos2]
	h.heap[pos2] = t
}


func (h *TaskGroupHeap) heapUp(pos int) {
	parrent := pos / 2
	for pos > 1 && h.heap[pos].Count > h.heap[parrent].Count {
		h.swap(pos, parrent)
		pos = parrent
		parrent = pos / 2
	}
}

func (h TaskGroupHeap) heapDown(pos int) {
	for i := range h.size{
        pos := i+1        
		lChild := pos*2
		rChild := pos*2 + 1
        if lChild <= h.size && h.heap[pos].Count < h.heap[lChild].Count {            
            h.swap(pos, lChild)
        }
        if rChild <= h.size && h.heap[pos].Count < h.heap[rChild].Count {            
            h.swap(pos, rChild)
        }
	}
}

func leastInterval(tasks []byte, n int) int {
	tasksMap := make(map[byte]*TaskGroup)
	for _, taskId := range tasks {
		if _, ok := tasksMap[taskId]; !ok {
			tasksMap[taskId] = &TaskGroup{Type: taskId, Count: 0}
		}
		tasksMap[taskId].Count++
	}

	gHeap := NewHeap(len(tasksMap))
	for _, taskGroup := range tasksMap {
		gHeap.Push(*taskGroup)
	}

	ans := 0
	for gHeap.Size() > 0 {
		tGroup := gHeap.Pop()
		// all groups have 1 left
		if tGroup.Count == 1 {			
			return ans+gHeap.Size()+1
		}

		// write A _ _ A then fill up the open spots
		ans += n+1
		groups := []TaskGroup{}
		for range n {
			if gHeap.Size() > 0 {
				groups = append(groups, gHeap.Pop())
			}
		}
		for _, group := range groups {
			group.Count--
			// Only add non-empty group back to heap
			if group.Count > 0 {
				gHeap.Push(group)
			}
		}
		tGroup.Count--
		gHeap.Push(tGroup)
	}
	return ans
}

func main() {
	fmt.Println(leastInterval([]byte{'A', 'A', 'A', 'B', 'B', 'B'}, 2))                          // expected: 8
	fmt.Println(leastInterval([]byte{'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}, 2)) // expected: 16
	fmt.Println(leastInterval([]byte{'A', 'A', 'A'}, 2))                                           // expected: 7
	fmt.Println(leastInterval([]byte{'A', 'B', 'C', 'D'}, 3))                                      // expected: 4
	fmt.Println(leastInterval([]byte{'A'}, 2))                                                     // expected: 1
	fmt.Println(leastInterval([]byte{'A', 'A', 'A', 'A'}, 3))                                      // expected: 13
	fmt.Println(leastInterval([]byte{'A', 'B', 'C'}, 2))                                           // expected: 3
	fmt.Println(leastInterval([]byte{'A', 'A', 'B', 'B', 'C', 'C'}, 2))                            // expected: 6
	fmt.Println(leastInterval([]byte{'A', 'A', 'A', 'B', 'B', 'B'}, 0))                            // expected: 6
	fmt.Println(leastInterval([]byte{'A', 'A', 'A', 'B', 'B', 'B'}, 3))                            // expected: 10
	fmt.Println(leastInterval([]byte{'A', 'A', 'B'}, 2))                                           // expected: 4 - AB.A
	fmt.Println(leastInterval([]byte{'A', 'A', 'A', 'B', 'B', 'C', 'D'}, 2))                                 // expected: 7 - ABCABDA
	fmt.Println(leastInterval([]byte{'A','A','A','B','B','B','C','C','C','D','D','E'}, 2)) // expected: 12 - ABCABCDABCDE
}