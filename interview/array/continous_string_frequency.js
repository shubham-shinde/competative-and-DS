console.log("-".repeat(40));
function continous_string_frequency(str) {
  let arr = [...str];
  let obj = {};
  for (let i in arr) {
    obj[arr[i]] = (obj[arr[i]] || 0) + 1;
  }
  let values = Object.values(obj).sort((a, b) => a - b);
  let rem = 0;
  let set = 1;
  for (let i = 0; i < values.length; i++) {
    if (values[i] > set) rem += values[i] - set;
    if (values[i] < set) rem += values[i];
    else set++;
  }
  return rem;
}

console.log(continous_string_frequency("aab"));
console.log(continous_string_frequency("aaabbbcc"));
console.log(continous_string_frequency("ceabaacb"));
console.log(continous_string_frequency("accdcdadddbaadbc"));
