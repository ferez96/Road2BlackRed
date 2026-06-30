package main

const MAX_VALUE = 1<<14 - 1 // 11111111111111
const INF_STEPS = 41

func minRemovals(nums []int, target int) int {
	dp := make([][]int, len(nums))
	for i := range len(nums) {
		dp[i] = make([]int, MAX_VALUE+1)
	}

	for i := range len(nums) {
		for j := range MAX_VALUE + 1 {
			dp[i][j] = INF_STEPS
		}
	}

	if nums[0] == 0 {
		dp[0][0] = 0
	} else {
		dp[0][0] = 1
		dp[0][nums[0]] = 0
	}

	for i := 1; i < len(nums); i++ {
		for j := range MAX_VALUE + 1 {
			dp[i][j] = min(dp[i][j], dp[i-1][j]+1)
			dp[i][j] = min(dp[i][j], dp[i-1][j^nums[i]])
		}
	}

	if dp[len(nums)-1][target] == INF_STEPS {
		return -1
	} else {
		return dp[len(nums)-1][target]
	}
}

func main() {
	minRemovals([]int{1, 2, 3}, 2)
}
