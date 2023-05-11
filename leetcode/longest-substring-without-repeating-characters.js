var lengthOfLongestSubstring = function (s) {
	dict = {}
	max_l = 0
	max_r = 0
	current_l = 0
	for (let i = 0; i < s.length; i++) {
		if (dict[s[i]] != undefined && dict[s[i]] >= current_l) {
			current_l = i
		}
		dict[s[i]] = i
		if ((max_r - max_l) < (i - current_l + 1)) {
			max_l = current_l
			max_r = i + 1
		}
	}

	let str = ''
	for (let i = max_l; i < max_r; i++) {
		str += s[i]
	}
	return str
};
