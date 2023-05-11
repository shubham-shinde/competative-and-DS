tests = [
	[[3, 2, 3, 1, 2, 4, 5, 5, 6], 4],
	[[3, 5, 2, 5, 2, 7], 4],
	[[3, 2, 1, 5, 6, 4], 2],
	[[3, 5, 2, 5, 2, 7, 8], 20],
]

function heapify(heap) {
	let n = heap.length
	if (n <= 1) return heap
	let pos = 0
	while ((2 * pos + 1) < n) {
		let child_node = pos
		if (2 * pos + 2 >= n) {
			child_node = (heap[child_node] > heap[2 * pos + 1]) ? 2 * pos + 1 : child_node
		} else {
			child_node = (heap[child_node] > heap[2 * pos + 1]) ? 2 * pos + 1 : child_node
			child_node = (heap[child_node] > heap[2 * pos + 2]) ? 2 * pos + 2 : child_node
		}
		if (child_node == pos) return
		let temp = heap[child_node]
		heap[child_node] = heap[pos]
		heap[pos] = temp
		pos = child_node
	}
}

function kthLargestElement(array, k) {
	if (k > array.length) return null
	let heap = []
	for (let i = 0; i < array.length; i++) {
		if (i < k) {
			heap.unshift(array[i])
			heapify(heap)
		} else if (heap[0] < array[i]) {
			heap[0] = array[i]
			heapify(heap)
		}
	}
	return heap[0]
}

for (let i of tests) {
	console.log(kthLargestElement(i[0], i[1]))
}
