class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def traverse(root):
    print root.data,
    if root.left:
        traverse(root.left)
    if root.right:
        traverse(root.right)

T = int(raw_input())
for t in range(T):
    num_nodes = int(raw_input())
    node_map = {}
    root = Node(1)
    node_map[1] = root
    for n in range(num_nodes):
        node_data, left_node_data, right_node_data = map(int, raw_input().split(" "))
        node = node_map[node_data]
        if left_node_data:
            node.left = Node(left_node_data)
            node_map[left_node_data] = node.left
        if right_node_data:
            node.right = Node(right_node_data)
            node_map[right_node_data] = node.right
    traverse(root)
    print