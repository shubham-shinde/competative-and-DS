let tests = [
	[[4, 2, 6, 1, 5], 3],
	[[4, 12, 16, 21, 25], 3],
	[[1, 5, 8, 9, 6, 7, 3, 4, 2, 0], 5]
]
function kSmallElements(arr, k) {
	n = arr.length
	for (let i = 0; i < n - k; i++) {
		let max = arr[0]
		let pos = 0
		for (let j = 0; j < (n - i); j++) {
			if (arr[j] > max) {
				max = arr[j]
				pos = j
			}
		}
		for (let j = pos; j < (n - 1 - i); j++) {
			arr[j] = arr[j + 1]
		}
	}
	let ret = []
	for (let i = 0; i < k; i++) {
		ret.push(arr[i])
	}
	return ret
}

for (let i of tests) {
	console.log(kSmallElements(i[0], i[1]))
}
