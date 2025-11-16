import heapq
import pickle
from collections import Counter


class Node:
    def __init__(self, freq, char):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq


def build_tree(msg):
    frequency = Counter(msg)

    heap = [Node(freq, char) for char, freq in frequency.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        right = heapq.heappop(heap)
        left = heapq.heappop(heap)

        merged = Node(right.freq + left.freq, None)
        merged.right = right
        merged.left = left

        heapq.heappush(heap, merged)
    return heap[0]


def build_codes(root):
    codes = {}

    def walk_tree(node, code):
        if node.char is not None:
            codes[node.char] = code
        if node.left is not None:
            walk_tree(node.left, code + "1")
        if node.right is not None:
            walk_tree(node.right, code + "0")

    walk_tree(root, "")
    return codes


def encode(msg: str) -> tuple[str, dict[str, str]]:
    root = build_tree(msg)
    codes = build_codes(root)

    encoded_text = "".join([codes[char] for char in msg])

    return encoded_text, codes


def decode(encoded_text: str, table: dict[str, str]) -> str:
    reversed_codes = {code: char for char, code in table.items()}
    string = ""
    symbol = ""
    for i in encoded_text:
        if symbol in reversed_codes:
            string += reversed_codes[symbol]
            symbol = ""
        symbol += i
    return string


def encode_file(msg):
    encode_text, codes = encode(msg)

    with open("file12.bin", "wb") as file:
        pickle.dump(codes, file)

    return encode_text


def decode_file(encode_text):
    with open("file12.bin", "rb") as file:
        codes = pickle.load(file)

    string = decode(encode_text, codes)

    return string
