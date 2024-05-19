package main

func isAnagram(s, t string) bool {

	if len(s) != len(t) {
		return false
	}

	mS := make(map[rune]int)
	mT := make(map[rune]int)

	for _, char := range s {
		mS[char]++
	}

	for _, char := range t {
		mT[char]++
	}

	for char, count := range mS {
		if mT[char] != count {
			return false
		}
	}

	return true

}
