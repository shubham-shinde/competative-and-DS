tests = [
	[5, 7],
	[7, 5],
	[20, 21],
	[20, 24],
	[24, 20],
	[5, 12]
]

function gcd(a, b) {
	return a !== 0 ? gcd(b % a, a) : b
}
// o(log(min(a, b)))

function rotate_array(array, d) {
	n = array.length
	gcp = gcd(d, n)
	for (let i = 0; i < gcp; i++) {
		let temp = array[i]
		let pos = i
		for (let j = 0; j < n / gcp; j++) {
			pos = (pos - d + n) % n
			let tp = array[pos]
			array[pos] = temp
			temp = tp
		}
	}
	return array
}

// for (let i of tests) {
// 	console.log(gcd(i[0], i[1]))
// }
//
//
let tests2 = [
	[[3, 34, 3, 33, 2, 6, 87, 2, 4, 2], 5],
	[[3, 34, 35, 3, 2, 6, 87, 2344, 2, 4, 2], 7]
]
for (let i of tests2) {
	console.log(rotate_array(i[0], i[1]))
}
