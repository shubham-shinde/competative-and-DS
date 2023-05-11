let tests = [
	[[2, 3, 60, 90, 50], [[1, 3], [2, 4], [0, 2]]],
	[[2, 3, 6, 9, 5], [[1, 3]]]
]

class SegmentTree {
	constructor(list, func) {
		this.list = list
		this.func = func
		this.tree = {}
		this.constructSegmentTree(0, list.length - 1)
	}

	constructSegmentTree(l, r) {
		let value
		if (l >= r) {
			value = this.list[l]
		} else {
			let mid = Math.floor(l + (r - l) / 2)
			value = this.func(this.constructSegmentTree(l, mid), this.constructSegmentTree(mid + 1, r))
		}
		if (this.tree[l]) {
			this.tree[l][r] = value
		} else {
			this.tree[l] = {}
			this.tree[l][r] = value
		}
		return value
	}

	calFromtree(start, end, l, r) {
		if (l == undefined) l = 0
		if (r == undefined) r = this.list.length - 1
		if (this.tree[start] != undefined && this.tree[start][end] != undefined) {
			return this.tree[start][end]
		} else {
			let mid = Math.floor(l + (r - l) / 2)
			if (end <= mid) return this.calFromtree(start, end, l, mid)
			if (start > mid) return this.calFromtree(start, end, mid + 1, r)
			return this.func(this.calFromtree(start, mid, l, mid), this.calFromtree(mid + 1, end, mid + 1, r))
		}
	}
}

function GCD(a, b) {
	return (a == 0) ? b : GCD(b % a, a)
}

function gcd_range(array, queries) {
	tree = new SegmentTree(array, GCD)
	let solutions = []
	for (let q of queries) {
		[start, end] = q
		solutions.push(tree.calFromtree(start, end))
	}
	return solutions
}

for (let i of tests) {
	console.log(gcd_range(i[0], i[1]))
}
