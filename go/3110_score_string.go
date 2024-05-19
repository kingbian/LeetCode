package main

import "math"

func scoreString(s string) int {
	sum := 0
	var prev, current float64
	for i := 1; i < len(s); i++ {
		prev = float64(s[i-1] - '0')
		current = float64(s[i] - '0')
		sum += int(math.Abs(prev - current))
	}
	return sum
}
