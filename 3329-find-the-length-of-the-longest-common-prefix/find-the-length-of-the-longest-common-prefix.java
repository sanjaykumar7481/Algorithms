class Solution {
    class TrieNode {
        TrieNode[] children = new TrieNode[10];
    }

    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        TrieNode root = new TrieNode();
        int maxLen = 0;

        // 1. Build the Trie using arr2
        for (int num : arr2) {
            insert(num, root);
        }

        // 2. Search each number from arr1 in the Trie
        for (int num : arr1) {
            maxLen = Math.max(maxLen, findLongestPrefix(num, root));
        }

        return maxLen;
    }

    private void insert(int num, TrieNode root) {
        TrieNode curr = root;
        String s = Integer.toString(num);
        for (char c : s.toCharArray()) {
            int digit = c - '0';
            if (curr.children[digit] == null) {
                curr.children[digit] = new TrieNode();
            }
            curr = curr.children[digit];
        }
    }

    private int findLongestPrefix(int num, TrieNode root) {
        TrieNode curr = root;
        String s = Integer.toString(num);
        int count = 0;
        for (char c : s.toCharArray()) {
            int digit = c - '0';
            if (curr.children[digit] != null) {
                count++;
                curr = curr.children[digit];
            } else {
                break;
            }
        }
        return count;
    }
}