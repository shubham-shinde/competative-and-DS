let tests = [
	[2, 1, 3, 4, 3],
	// [2, 1, 5, 6, 2, 3]
]

var largestRectangleArea = function (heights) {
	// getting lest smallest
	let l_smallest = [-1]
	let stack = [0]
	for (let i = 1; i < heights.length; i++) {
		while (stack.length > 0 && heights[stack[stack.length - 1]] >= heights[i]) {
			stack.pop()
		}
		if (stack.length === 0) l_smallest.push(-1)
		else l_smallest.push(stack[stack.length - 1])
		stack.push(i)
	}
	// getting right smallest
	let r_smallest = [-1]
	stack = [heights.length - 1]
	for (let i = heights.length - 2; i >= 0; i--) {
		while (stack.length > 0 && heights[stack[stack.length - 1]] >= heights[i]) {
			stack.pop()
		}
		if (stack.length === 0) r_smallest.unshift(-1)
		else r_smallest.unshift(stack[stack.length - 1])
		stack.push(i)
	}
	// finding max
	let max_box = 0
	for (let i = 0; i < heights.length; i++) {
		let l_small = (l_smallest[i] === -1) ? 0 : l_smallest[i] + 1
		let r_small = (r_smallest[i] === -1) ? heights.length - 1 : r_smallest[i] - 1
		let box = heights[i] * (r_small - l_small + 1)
		if (box > max_box) max_box = box
	}
	return max_box
};

for (let i of tests) console.log(largestRectangleArea(i))
