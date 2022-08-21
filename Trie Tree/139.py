# Add solution for https://leetcode.com/problems/word-break/

class TrieNode:
    def __init__(self, char):
        self.char = char
        self.is_end = False
        self.children = {}

class Trie(object):
    def __init__(self):
        self.root = TrieNode("")

    def insert(self, word):        
        current = self.root
        for c in word:
            if c not in current.children:
                current.children[c] = TrieNode(c)
            current = current.children[c]
        current.is_end = True
        
    def search_word(self,word):
        current = self.root
        for c in word:
            if c not in current.children:
                return False 
            current = current.children[c]
        return current.is_end


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        trie = Trie()
        for w in wordDict:
            trie.insert(w)
        
        dp=[False for i in range(len(s)+1)]
        dp[0]=True
        
        for i in range(1,len(s)+1):
            for j in range(i):
                if dp[j] and trie.search_word(s[j:i]):
                    dp[i] = True
                    break
        return dp[-1]