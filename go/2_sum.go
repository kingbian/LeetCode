package main

func twoSum(nums []int, target int) []int {

	m := make(map[int]int)

	for i, val := range nums {

		complement := target - val
		if index, ok := m[complement]; ok {
			return []int{i, index}
		}

		m[val] = i

	}

	return []int{}
}
