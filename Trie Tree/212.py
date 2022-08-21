# Add solution for https://leetcode.com/problems/word-search-ii/

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

class Solution(object):
    def findWords(self, board, words):
        res = []
        trie = Trie()
        node = trie.root
        for w in words:
            trie.insert(w)
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.dfs(board, node, i, j, "", res)
        return res
    
    def dfs(self, board, node, i, j, path, res):
        if node.is_end:
            res.append(path)
            node.is_end = False
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
            return 
        tmp = board[i][j]
        if tmp not in node.children:
            return
        node = node.children[tmp]
        board[i][j] = "#"
        self.dfs(board, node, i+1, j, path+tmp, res)
        self.dfs(board, node, i-1, j, path+tmp, res)
        self.dfs(board, node, i, j-1, path+tmp, res)
        self.dfs(board, node, i, j+1, path+tmp, res)
        board[i][j] = tmp