'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
class Node():
	def __init__(self,alphabet):
		self.value = alphabet
		self.children = []

class Trie():
	def __init__(self):
		self.root = Node("root")

	def insertWord(self,word):
		letters = list(word)
		currentNode = self.root
		while True:
			try:
				letter = letters.pop(0)
			except IndexError:break
			found = 0
			for node in currentNode.children:
				if node.value == letter:
					currentNode = node
					found = 1
					break
			if found == 1: continue
			newNode = Node(letter)
			currentNode.children.append(newNode)
			currentNode = newNode
				
	def numOfNodes(self):
		self.totalNodes = 0
		def calc(currNode):
			self.totalNodes = self.totalNodes + len(currNode.children) 
			for node in currNode.children:
				calc(node)
		calc(self.root)
		return self.totalNodes+1

N = int(raw_input())
trie = Trie()
for x in range(N):
	word = raw_input()
	trie.insertWord(word)
print trie.numOfNodes()