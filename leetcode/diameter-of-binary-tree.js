let tests = [
	[1, 2, 3, 4, 5]
]

var diameterOfNode = function (root) {
	if (!root.left && !root.right) {
		return [0, 0]
	}
	let [rightH, rightMax] = [0, 0]
	let [leftH, leftMax] = [0, 0]
	if (root.left) {
		[leftH, leftMax] = diameterOfNode(root.left)
		leftH += 1
	}
	if (root.right) {
		[rightH, rightMax] = diameterOfNode(root.right)
		rightH += 1
	}
	let max = rightH + leftH

	return [(leftH > rightH) ? leftH : rightH, Math.max(rightMax, leftMax, max)]
}

var diameterOfBinaryTree = function (root) {
	let [_height, max] = diameterOfNode(root)
	return max
};


for (let i of tests) {
	console.log(diameterOfBinaryTree(i))
}
