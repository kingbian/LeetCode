package main

import "strings"

func finalValueAfterOperations(operations []string) int {

	ans := 0

	for _, word := range operations {

		if strings.Contains(word, "++") {
			ans++
		} else {
			ans--
		}
	}

	return ans

}
