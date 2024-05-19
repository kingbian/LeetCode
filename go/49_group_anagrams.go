package main

func groupAnagrams(strs []string) [][]string {

	//create an empty map, use an array of ints as the key an
	ss := map[[26]int][]string{}

	for _, word := range strs {

		countArray := [26]int{}

		for _, chars := range word {
			countArray[chars-'a']++
		}
		ss[countArray] = append(ss[countArray], word)
	}

	result := [][]string{}

	for _, anagrams := range ss {
		result = append(result, anagrams)
	}
	return result
}
