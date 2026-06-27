package main

import (
	"fmt"
	"strings"
)

func removeStars(s string) string {
	stack := make([]byte, len(s))
	top := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '*' && top > 0 {
			top-- // remove current character
		} else {
			stack[top] = s[i]
			top++
		}
	}

	sb := strings.Builder{}
	sb.Grow(top)
	for i := 0; i < top; i++ {
		sb.WriteByte(stack[i])
	}

	return sb.String()
}

func main() {
	fmt.Println(removeStars("leet**cod*e"))
}
