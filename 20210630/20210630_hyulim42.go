func solution(answers []int) []int {
    ret := make([]int, 0, 3)
    count := []int{0,0,0}
    pattern := make([][]int, 5, 10)
    pattern[0] = append(pattern[0], 1,2,3,4,5)
    pattern[1] = append(pattern[1], 2,1,2,3,2,4,2,5)
    pattern[2] = append(pattern[2], 3,3,1,1,2,2,4,4,5,5)

    for i := 0; i < len(answers); i++ {
        ans := answers[i]
        for j := 0; j < 3; j++ {
            if ans == pattern[j][i % len(pattern[j])] {
                count[j]++
            }
        }
    }
    max := -1
    for i := 0; i < len(count); i++ {
        if max < count[i] {
            max = count[i]
        }
    }
    for i := 0; i < 3; i++ {
        if count[i] == max {
            ret = append(ret, i + 1)
        }
    }    
    return ret
}
