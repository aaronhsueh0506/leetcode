## Problem Decsription

Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:

- `'.'` Matches any single character.
- `'*'` Matches zero or more of the preceding element.

The matching should cover the **entire** input string (not partial).

#### Example 1:
```plaintext
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

#### Example 2:
```plaintext
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

#### Example 3:
```plaintext
Input: s = "ab", p = "."
Output: true
Explanation: "." means "zero or more (*) of any character (.)".
```

## Constraints

- `1 <= s.length <= 20`
- `1 <= p.length <= 30`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `'.'`, and `'*'`.
- It is guaranteed for each appearance of the character `'*'`, there will be a previous valid character to match.

## Concept
1. Use DP to record whether `s[0 to i]` matches `p[0 to j]`
2. character `*` can represent zero occurrences of the preceding element. Set `dp[0][i] = dp[0][i-2]` for patterns like `'a*'` or `'.*'`.
3. If the characters are the same (`s[i-1] == p[j-1]`) or `p[j-1] == '.'`, check whether the last match was successful (`dp[i][j] = dp[i-1][j-1]`).
4. If `p[j-1]` is `*`, consider two cases:
   - Check if `*` represents zero occurrences of the preceding element (`dp[i][j-2]`).
   - Or, if the last character of s matches the one before `*` in `p` (`s[i-1] == p[j-2] or p[j-2] == '.'`), and `dp[i-1][j]` is `true`. `dp[i-1][j]` indicates whether removing one character from `s` still results in a match.
