let tests = [
	['horse', 'ros'],
	['intention', 'execution'],
	['execution', 'intention']
]


var minDistance = function (word1, word2) {
	let dp = []
	for (let i = 0; i < word1.length; i++) {
		let temp = []
		for (let j = 0; j < word2.length; j++) {
			temp.push(-1)
		}
		dp.push(temp)
	}
	let getMinDistance = (s1, s2) => {
		if (s1 < 0 || s2 < 0) return (s1 > s2 ? s1 : s2) + 1
		if (dp[s1][s2] !== -1) return dp[s1][s2]
		let value = null
		if (word2[s2] === word1[s1]) {
			value = getMinDistance(s1 - 1, s2 - 1)
		} else {
			value = Math.min(getMinDistance(s1 - 1, s2), getMinDistance(s1, s2 - 1), getMinDistance(s1 - 1, s2 - 1)) + 1
		}
		dp[s1][s2] = value
		return value
	}
	let min_distance = getMinDistance(word1.length - 1, word2.length - 1)
	return min_distance
};

for (let i of tests) console.log(minDistance(i[0], i[1]))
