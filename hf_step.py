# Build frequency dictionary
# Build a Min Heap
# Generate Huffman Tree
# Traverse and assign codes


import heapq


class HuffmanEncoder:
    def __init__(self, text):
        self.text = text

    def build_freq_dict(self):
        frequency = {}
        text_list = list(self.text)
        uniq_text = set(text_list)
        for letter in uniq_text:
            frequency[letter] = text_list.count(letter)
        return frequency

    def compress(self):
        frequency = self.build_freq_dict()
        print(frequency)


t_input = str(input())
HuffmanEncoder(t_input).compress()
