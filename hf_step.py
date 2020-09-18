# Build frequency dictionary (x)
# Build a Min Heap (x)
# Generate Huffman Tree
# Traverse and assign codes


import heapq


class HeapNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

    def __eq__(self, other):
        if other == None:
            return False
        return self.freq == other.freq

    def __repr__(self):
        return '[{} {} {} {}]'.format(self.char, self.freq, self.left, self.right)


class HuffmanEncoder:
    def __init__(self, text):
        self.text = text
        self.heap = []
        self.codes = {}

    def build_freq_dict(self):
        frequency = {}
        text_list = list(self.text)
        uniq_text = set(text_list)
        for letter in uniq_text:
            frequency[letter] = text_list.count(letter)
        return frequency

    def build_min_heap(self, frequency):
        for key in frequency:
            node = HeapNode(key, frequency[key])
            heapq.heappush(self.heap, node)

    def generate_tree(self):
        while(len(self.heap) > 1):
            x = heapq.heappop(self.heap)
            y = heapq.heappop(self.heap)
            merged = HeapNode(None, x.freq+y.freq)
            merged.left = x
            merged.right = y
            heapq.heappush(self.heap, merged)

    def traverse_tree(self, node, bin_code):
        if node == None:
            return
        if node.char != None:
            self.codes[node.char] = bin_code
        self.traverse_tree(node.left, bin_code + "0")
        self.traverse_tree(node.right, bin_code + "1")

    def generate_code(self):
        root = heapq.heappop(self.heap)
        bin_code = ""
        self.traverse_tree(root, bin_code)

    def compress(self):
        frequency = self.build_freq_dict()
        self.build_min_heap(frequency)
        self.generate_tree()
        self.generate_code()
        print(frequency)
        print(self.codes)


t_input = str(input())
HuffmanEncoder(t_input).compress()
