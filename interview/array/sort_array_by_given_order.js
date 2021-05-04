console.log("-".repeat(40));

function sorf_array_by_given_preferences(arr, pref) {
  pref = [...pref];
  const map = {};
  for (let i = 0; i < pref.length; i++) {
    map[pref[i]] = i;
  }
  return arr.sort((a, b) => {
    let i = 0;
    while (true) {
      if (!a[i]) {
        return -1;
      }
      if (!b[i]) return 1;
      if (a[i] !== b[i]) {
        return map[a[i]] > map[[b[i]]] ? 1 : -1;
      }
      i++;
    }
  });
}

console.log(
  sorf_array_by_given_preferences(
    ["hello", "geeksforgeeks"],
    "hlabcdefgijkmnopqrstuvwxyz"
  )
);

console.log(
  sorf_array_by_given_preferences(
    ["word", "world", "row"],
    (order = "worldabcefghijkmnpqstuvxyz")
  )
);
