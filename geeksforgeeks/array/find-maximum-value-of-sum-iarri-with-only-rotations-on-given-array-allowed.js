let tests = [
	[4, 5, 1, 2],
	[5, 1, 2, 3, 4],
	[10, 1, 2, 3, 4, 5, 6, 7, 8, 9],
	[2, 10, 1, 20]
]

function findMaxSum(array) {
	let n = array.length;
	let sum = 0
	let isum = 0
	for (let i = 0; i < n; i++) {
		sum += array[i]
		isum += array[i] * i
	}
	max_isum = isum;
	for (let i = 0; i < n; i++) {
		isum -= sum - array[i];
		isum += array[i] * (n - 1)
		if (isum > max_isum) max_isum = isum
	}
	return max_isum
}

for (let i of tests) {
	console.log(findMaxSum(i))
}
