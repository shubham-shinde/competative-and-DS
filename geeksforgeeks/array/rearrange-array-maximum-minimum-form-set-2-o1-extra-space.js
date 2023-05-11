tests = [
	[1, 2, 3, 4, 5, 6, 7],
	[1, 2, 3, 4, 5, 6],
	[1, 2, 3, 4, 5, 6, 7, 8, 9],

]
function rearrange_max_min(array) {
	const n = array.length
	let max_i = n - 1
	let min_i = 0
	let max = 0
	array.forEach(e => {
		max = (e > max) ? e : max
	})
	max++
	for (let i in array) {
		if (i % 2 === 0) {
			array[i] += (array[max_i] % max) * max
			max_i--
		} else {
			array[i] += (array[min_i] % max) * max
			min_i++
		}
	}
	for (let i in array) {
		array[i] = Math.floor(array[i] / max)
	}
	return array
}

for (let i of tests) {
	console.log(rearrange_max_min(i))
}
