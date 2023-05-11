tests = [
	"abba",
	"abcd",
	"ifailuhkqq",
	"kkkk"
]

function sherlockAndAnagrams(s) {
	let ana_count = {}
	for (let i = 0; i < s.length; i++) {
		let char_count = {}
		for (let j = i; j < s.length; j++) {
			if (char_count[s[j]] != undefined) char_count[s[j]] += 1
			else char_count[s[j]] = 1
			let str = ''
			for (let c = 'a'.charCodeAt(0); c <= 'z'.charCodeAt(0); c++) {
				char = String.fromCharCode(c)
				str += `${char}=${(char_count[char] ? char_count[char] : 0)}`
			}
			if (ana_count[str] != undefined) {
				ana_count[str] += 1
			} else ana_count[str] = 1
		}
	}
	let ans = 0
	for (let value of Object.values(ana_count)) {
		ans += (value * (value - 1)) / 2
	}
	return ans
}

for (let i of tests) {
	console.log(sherlockAndAnagrams(i))
}
