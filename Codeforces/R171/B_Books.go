package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var scanner *Scanner
	if os.Getenv("ONLINE_JUDGE") == "" {
		file, err := os.Open("in.txt")
		if err != nil {
			panic(err)
		}
		defer file.Close()
		scanner = NewScanner(file)
	} else {
		scanner = NewScanner(os.Stdin)
	}

	solver := NewSolver(scanner)
	solver.solve()
}

type Solver struct {
	sc *Scanner
}

func NewSolver(sc *Scanner) *Solver {
	return &Solver{sc: sc}
}

func (s *Solver) solve() {
	n := s.sc.nextInt()
	t := s.sc.nextInt()
	cur := 0
	ans := 0
	left := 0
	books := make([]int, n)

	for i := 0; i < n; i++ {
		books[i] = s.sc.nextInt()
		if books[i]+cur <= t {
			cur += books[i]
			continue
		}
		if i-left > ans {
			ans = i - left
		}
		cur += books[i]
		for cur > t {
			cur -= books[left]
			left++
			if left > i {
				break
			}
		}
	}
	if cur <= t && n-left > ans {
		ans = n - left
	}
	fmt.Println(ans)
}

type Scanner struct {
	scanner *bufio.Scanner
}

func NewScanner(r *os.File) *Scanner {
	return &Scanner{scanner: bufio.NewScanner(r)}
}

func (s *Scanner) next() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func (s *Scanner) nextInt() int {
	val, _ := strconv.Atoi(s.next())
	return val
}

func (s *Scanner) nextLine() string {
	s.scanner.Scan()
	return s.scanner.Text()
}
