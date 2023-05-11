let tests = [
	["flower", "flow", "flight"],
	["", "b"]
]

class Node {
	#nodes
	#isEnd
	constructor() {
		this.#nodes = []
		for (let i = 0; i < 26; i++) {
			this.#nodes.push(-1)
		}
		this.#isEnd = false
	}

	getNode(char) {
		return this.#nodes[char.charCodeAt(0) - 97] === -1 ? null : this.#nodes[char.charCodeAt(0) - 97]
	}

	setEnd() {
		this.#isEnd = true
	}

	isEnd() {
		return this.#isEnd
	}

	setNode(char) {
		let node = new Node()
		if (this.getNode(char) === null) {
			this.#nodes[char.charCodeAt(0) - 97] = node
		}
		return node
	}

	noOfActiveNode() {
		return 26 - this.#nodes.reduce((a, b) => b === -1 ? a + 1 : a, 0)
	}

	activeNode() {
		for (let i = 0; i < 26; i++) {
			if (this.#nodes[i] !== -1) return [this.#nodes[i], String.fromCharCode(97 + i)]
		}
		return [null, null]
	}
}

class Trie {
	constructor() {
		this.root = new Node()
	}

	insert = (s) => {
		let parent = this.root
		for (let i of s) {
			if (parent.getNode(i)) {
				parent = parent.getNode(i)
			} else {
				parent = parent.setNode(i)
			}
		}
		parent.setEnd()
	}

	checkMaxPrefix() {
		let str = ''
		let parent = this.root
		while (parent) {
			if (parent.noOfActiveNode() === 1 && !parent.isEnd()) {
				let [node, char] = parent.activeNode()
				parent = node
				str += char
			} else break
		}
		return str
	}
}

var longestCommonPrefix = function (strs) {
	let trie = new Trie()
	for (let i of strs) trie.insert(i)
	return trie.checkMaxPrefix()
};

for (let i of tests) {
	console.log(longestCommonPrefix(i))
}
