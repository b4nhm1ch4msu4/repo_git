package split

import (
	"reflect"
	"testing"
)

func TestSplit(t *testing.T) {
	// got := Split("a/b/c", "/")
	// want := []string{"a", "b", "c"}
	// if !reflect.DeepEqual(got, want) {
	// 	t.Fatalf("expected: %v, got: %v", want, got)
	// }
	type test struct {
		input string
		sep   string
		want  []string
	}

	tests := []test{
		{input: "a/b/c", sep: "/", want: []string{"a", "b", "c"}},
		{input: "abc", sep: "/", want: []string{"abc"}},
		{input: "a/b/c", sep: ",", want: []string{"a/b/c"}},
		{input: "a/b/c/", sep: ",", want: []string{"a/b/c"}},
	}

	for _, tc := range tests {
		got := Split(tc.input, tc.sep)
		if !reflect.DeepEqual(got, tc.want) {
			t.Fatalf("expected: %v, got: %v", tc.want, got)
		}
	}
}
