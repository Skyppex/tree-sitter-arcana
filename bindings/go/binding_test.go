package tree_sitter_arcana_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-arcana"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_arcana.Language())
	if language == nil {
		t.Errorf("Error loading Arcana grammar")
	}
}
