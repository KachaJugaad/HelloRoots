# Arrays — Foundation Patterns

Arrays are the substrate for almost every other data structure. Master these seven patterns and you will recognise the skeleton inside 60–70% of array problems.

---

## 1. Two Sum
**Question.** Given `nums` and `target`, return indices of two numbers that add to `target`.

**Pattern: hashmap-as-complement.**
Walk the array once; for each element `x`, check whether `target - x` was seen earlier. O(n) time, O(n) space.

**What this unlocks.**
- Any problem of the form "find two / three / k elements that satisfy a relation" — first instinct becomes "can I precompute lookups in a map?"
- **3Sum / 4Sum** (fix one element, reduce to 2Sum).
- **Subarray Sum Equals K** (prefix-sum + hashmap of seen prefixes).
- **Contains Duplicate, Longest Consecutive Sequence.**
- **Group Anagrams, Isomorphic Strings** (map as canonical form).

**Mental model.** "Instead of looking forward, I ask: has the answer already walked past me?"

---

## 2. Best Time to Buy and Sell Stock
**Question.** Given daily prices, find max profit from one buy + one sell (buy before sell).

**Pattern: running extremum in a single pass.**
Keep `minSoFar`; at each day compute `price - minSoFar`, track max. O(n) / O(1).

**What this unlocks.**
- **Maximum Difference** problems on any sequence.
- **Stock II / III / IV** variants — each is a DP layered on this same "track something running" idea.
- **Longest Mountain, Container with Water (one-sided version).**
- Any problem that can be phrased as "best pair (i, j) with i < j."

**Mental model.** "I don't need to revisit the past — I just need to remember the best thing the past offered me."

---

## 3. Maximum Subarray (Kadane's Algorithm)
**Question.** Find the contiguous subarray with the largest sum.

**Pattern: extend vs restart (DP in one variable).**
`curr = max(nums[i], curr + nums[i])`. Either grow the current run or start a new one here.

**What this unlocks.**
- This is your **first real DP**. The decision "extend vs restart" is the seed of every 1-D DP.
- **Maximum Product Subarray** (track min too, because of negatives).
- **Circular Subarray Sum, Max Sum with K Deletions.**
- **House Robber** (extend = rob, restart = skip — same skeleton).

**Mental model.** "At every step I'm making a local choice that has O(1) state. DP is just remembering the right O(1) thing."

---

## 4. Move Zeroes / Remove Duplicates from Sorted Array
**Question.** Rearrange in-place so non-zero elements come first (preserving order) / remove duplicates in-place.

**Pattern: two-pointer, same direction (read vs write).**
Reader scans every element; writer only advances when the reader finds something worth keeping.

**What this unlocks.**
- **In-place mutation under O(1) space constraints** — an interview favourite.
- **Partition problems** (Dutch National Flag / Sort Colors).
- **Filtering any sequence without extra allocation.**
- The first half of **Quicksort's partition step.**

**Mental model.** "Two indices, two jobs. Decouple 'where I'm looking' from 'where I'm writing'."

---

## 5. Container With Most Water
**Question.** Given heights, pick two lines forming the container with most water.

**Pattern: converging two-pointer.**
Start at both ends; always move the *shorter* side inward, because moving the taller side can only make things worse.

**What this unlocks.**
- **Two-pointer on sorted arrays** (3Sum core loop).
- **Trapping Rain Water.**
- **Valid Triangle Number, Boats to Save People.**
- The core invariant: "at each step I can eliminate a whole class of candidates."

**Mental model.** "Every move must destroy options that couldn't have been optimal. That's what makes O(n) legal here."

---

## 6. Product of Array Except Self
**Question.** Return an array where `ans[i] = product of all nums except nums[i]`, without division, in O(n).

**Pattern: prefix × suffix precomputation.**
One left-to-right pass builds prefix products, one right-to-left builds suffix products. Combine.

**What this unlocks.**
- **Prefix sums** — the most reused trick in array problems.
- **Range sum queries, Subarray sums, Equilibrium Index.**
- **Trapping Rain Water** (prefix max + suffix max).
- The general idea: **replace nested loops with two linear passes.**

**Mental model.** "If every answer depends on 'everything to my left' and 'everything to my right', precompute both."

---

## 7. Trapping Rain Water
**Question.** Given an elevation map, compute how much rain it can trap.

**Pattern: bound-from-both-ends (two-pointer with max-so-far).**
At each step the side with the smaller max bounds the water above that column. Advance that side.

**What this unlocks.**
- The **"bounded by the min of two maxes"** shape shows up everywhere (histogram problems, skyline, largest-rectangle).
- Teaches you to **prove correctness from an invariant**, not by exhaustion.
- Bridges two-pointer thinking with monotonic-stack thinking (the stack solution is the other canonical approach — worth solving twice).

**Mental model.** "Water level at column i = min(maxLeft, maxRight) - height[i]. Find a way to compute that without two full passes."

---

## Meta-patterns that carry over everywhere

| Pattern | You'll reach for it when... |
|---|---|
| **Hashmap-as-complement** | You need O(1) "have I seen X?" |
| **Running extremum** | The answer is a pairwise relation across the sequence |
| **Extend vs restart** | The optimal substructure is "current run" |
| **Two-pointer (same-dir)** | Filtering / partitioning in place |
| **Two-pointer (converging)** | Sorted input, you can eliminate a side per step |
| **Prefix / suffix precomputation** | Every answer depends on "everything outside i" |
| **Invariant-driven shrinking** | Sliding window, monotonic structures |

---

## How to practice this list

1. **Solve it cold** (no hints).
2. **Write the pattern name** on top as a one-line comment.
3. **List two more problems** this pattern unlocks. If you can't name two, you haven't internalised it yet.
4. **Re-solve a week later** — muscle memory is the goal, not first-time cleverness.
