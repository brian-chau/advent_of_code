package main

import (
	"fmt"
	"strconv"
	"strings"
)
func Answer2(puzzleInput string) int {
	lines := strings.Split(puzzleInput, ",")
	fishes := make([]int, 9)

	for _, line := range lines {
		index, _ := strconv.Atoi(line)
		fishes[index] += 1
	}

	fmt.Println(fishes)

	day := 0
	for day < 256 {
		sum := 0
		for _, count := range fishes {
			sum += count
		}
		fmt.Println("day", day, fishes, sum)

		day += 1
		new_fishes := make([]int, 9)

		for index, count := range fishes {
			if index == 0 {
				new_fishes[6] += count
				new_fishes[8] += count
			} else {
				new_fishes[index-1] += count
			}
		}
		fishes = new_fishes
	}

	sum := 0
	for _, count := range fishes {
		sum += count
	}
	fmt.Println("day", day, fishes, sum)

	return sum
}

func main(){
	fmt.Println(Answer2( "5,1,1,5,4,2,1,2,1,2,2,1,1,1,4,2,2,4,1,1,1,1,1,4,1,1,1,1,1,5,3,1,4,1,1,1,1,1,4,1,5,1,1,1,4,1,2,2,3,1,5,1,1,5,1,1,5,4,1,1,1,4,3,1,1,1,3,1,5,5,1,1,1,1,5,3,2,1,2,3,1,5,1,1,4,1,1,2,1,5,1,1,1,1,5,4,5,1,3,1,3,3,5,5,1,3,1,5,3,1,1,4,2,3,3,1,2,4,1,1,1,1,1,1,1,2,1,1,4,1,3,2,5,2,1,1,1,4,2,1,1,1,4,2,4,1,1,1,1,4,1,3,5,5,1,2,1,3,1,1,4,1,1,1,1,2,1,1,4,2,3,1,1,1,1,1,1,1,4,5,1,1,3,1,1,2,1,1,1,5,1,1,1,1,1,3,2,1,2,4,5,1,5,4,1,1,3,1,1,5,5,1,3,1,1,1,1,4,4,2,1,2,1,1,5,1,1,4,5,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,4,2,1,1,1,2,5,1,4,1,1,1,4,1,1,5,4,4,3,1,1,4,5,1,1,3,5,3,1,2,5,3,4,1,3,5,4,1,3,1,5,1,4,1,1,4,2,1,1,1,3,2,1,1,4"))
}