func countCompleteSubstrings(word string, k int) int {
    mp := make(map[int]map[byte]int)
	mp[-1] = make(map[byte]int)
	n := len(word)
	ans := 0
	last := 0

	for i := 0; i < n; i++ {
		if i != 0 && int(math.Abs(float64(word[i-1])-float64(word[i]))) > 2 {
			mp = make(map[int]map[byte]int)
			mp[i-1] = make(map[byte]int)
			last = i
		}

		mp[i] = make(map[byte]int)
		for key, value := range mp[i-1] {
			mp[i][key] = value
		}
		mp[i][word[i]]++

		for j := 1; j <= 26; j++ {
			if (i - j*k) >= last-1 {
				flag := 0
				for x, count := range mp[i] {
					diff := count - mp[i-j*k][x]
					if (diff != 0 && diff != k) || (diff > k) {
						flag = 1
						break
					}
				}
				if flag == 0 {
					ans++
				}
			} else {
				break
			}
		}
	}
	return ans
}
