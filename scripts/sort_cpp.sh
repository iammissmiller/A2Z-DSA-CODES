#!/usr/bin/env bash
classify_topic() {
  local name="${1,,}"
  if [[ "$name" == *pattern* ]]; then echo "Patterns"
  elif [[ "$name" == *array* || "$name" == *subarray* || "$name" == *missing* || "$name" == *dutch* || "$name" == *boyer* || "$name" == *kadane* || "$name" == *two-sum* || "$name" == *twosum* || "$name" == *three-sum* || "$name" == *threesum* || "$name" == *four-sum* || "$name" == *foursum* ]]; then echo "Arrays"
  elif [[ "$name" == *hash* || "$name" == *occurrence* || "$name" == *character* || "$name" == *map* ]]; then echo "Hashing"
  elif [[ "$name" == *recursi* || "$name" == *fibonacci* || "$name" == *backtrack* ]]; then echo "Recursion"
  elif [[ "$name" == *sort* ]]; then echo "Sorting"
  elif [[ "$name" == *binary* || "$name" == *search* || "$name" == *linear* || "$name" == *bound* ]]; then echo "BinarySearch"
  elif [[ "$name" == *string* || "$name" == *palindrome* || "$name" == *pallindrome* ]]; then echo "Strings"
  elif [[ "$name" == *tree* || "$name" == *bst* ]]; then echo "Trees"
  elif [[ "$name" == *graph* || "$name" == *bfs* || "$name" == *dfs* ]]; then echo "Graphs"
  elif [[ "$name" == *dp* || "$name" == *dynamic* ]]; then echo "DynamicProgramming"
  elif [[ "$name" == *link* || "$name" == *list* ]]; then echo "LinkedLists"
  elif [[ "$name" == *stack* || "$name" == *queue* ]]; then echo "StackQueue"
  elif [[ "$name" == *math* || "$name" == *armstrong* || "$name" == *prime* ]]; then echo "Math"
  elif [[ "$name" == *bit* || "$name" == *xor* ]]; then echo "BitManipulation"
  elif [[ "$name" == *greedy* ]]; then echo "Greedy"
  elif [[ "$name" == *heap* ]]; then echo "Heap"
  else echo "Misc"
  fi
}
classify_platform() {
  local name="${1,,}"
  if [[ "$name" == *leetcode* ]]; then echo "LeetCode"
  elif [[ "$name" == *hackerrank* || "$name" == *-hr* ]]; then echo "HackerRank"
  elif [[ "$name" == *codechef* || "$name" == *-cc* ]]; then echo "CodeChef"
  elif [[ "$name" == *codeforces* || "$name" == *-cf* ]]; then echo "Codeforces"
  elif [[ "$name" == *gfg* || "$name" == *geeks* ]]; then echo "GFG"
  else echo "General"
  fi
}
moved=0
for f in *.cpp; do
  [[ -e "$f" ]] || continue
  base="${f%.cpp}"
  platform=$(classify_platform "$base")
  topic=$(classify_topic "$base")
  dest_dir="${platform}/${topic}"
  mkdir -p "$dest_dir"
  git mv "$f" "$dest_dir/$f"
  echo "  moved: $f  →  $dest_dir/"
  ((moved++))
done
echo ""
echo "Done. Moved: $moved files."
