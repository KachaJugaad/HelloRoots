# HelloRoots

Back-to-roots coding practice.

## Layout

| Folder    | Topic                               |
|-----------|-------------------------------------|
| `graphs/` | BFS, DFS, shortest paths, union-find |
| `trees/`  | traversals, BST, heap, trie          |
| `dp/`     | 1-D / 2-D DP, memoization            |
| `arrays/` | two-pointer, sliding window, prefix  |
| `strings/`| pattern matching, parsing            |
| `scratch/`| throwaway experiments                |

## Build & run

```sh
make run FILE=graphs/BFS     # compile graphs/BFS.cpp -> /tmp/helloroots/graphs/BFS and run
make build FILE=graphs/BFS   # compile only
make clean                   # remove build artifacts
```

## Log

| Date       | File              | Topic | Notes                    |
|------------|-------------------|-------|--------------------------|
| 2026-04-22 | `graphs/BFS.cpp`  | BFS   | undirected graph, n = 6  |
