let tests = [
	[[5, 7, 7, 8, 8, 10], 8],
	[[5, 7, 7, 8, 8, 10], 6],
	[[1, 2, 3], 2]
]
var searchRange = function (nums, target) {
	// find first
	let l = 0;
	let r = nums.length - 1
	let first = -1
	while (l < r) {
		let mid = Math.floor(l + (r - l) / 2)
		if (nums[l] === target) {
			first = l
			break
		}
		if (nums[mid] < target) {
			l = mid + 1
		} else {
			r = mid
		}
	}
	if (first === -1 && nums[r] === target) first = r
	// find last
	l = 0
	r = nums.length - 1
	let last = -1
	while (l < r) {
		let mid = Math.ceil(l + (r - l) / 2)
		if (nums[r] === target) {
			last = r
			break
		}

		if (nums[mid] > target) {
			r = mid - 1
		} else {
			l = mid
		}
	}
	if (last === -1 && nums[l] === target) last = l
	return [first, last]
};

for (let i of tests) console.log(searchRange(i[0], i[1]))
