console.log("-".repeat(40));

// https://www.geeksforgeeks.org/topological-sorting/
// topological search is used for sorting in an order of direction of directed graph
//
//
//
//
function top(map, node, visited, stack) {
  if (visited[node] === true) return;
  let after = map.get(node);
  for (let i in after) {
    top(map, after[i], visited, stack);
  }
  visited[node] = true;
  stack.push(node);
}
function topological(map) {
  let visited = {};
  vertices = [...map.keys()];
  for (let i in vertices) {
    visited[i] = false;
  }

  let stack = [];

  for (let i in vertices) {
    top(map, vertices[i], visited, stack);
  }
  return stack.reverse();
}

function find_order(sorted_array) {
  map = new Map();

  for (let i = 0; i < sorted_array.length - 1; i++) {
    let j = 0;
    let str1 = [...sorted_array[i]];
    let str2 = [...sorted_array[i + 1]];
    while (true) {
      if (!str1[j] || !str2[j]) break;
      if (str1[j] !== str2[j]) {
        if (map.has(str1[j])) {
          map.get(str1[j]).push(str2[j]);
        } else {
          map.set(str1[j], [str2[j]]);
        }
        break;
      }
      j++;
    }
  }
  return topological(map);
}

console.log(find_order(["baa", "abcd", "abca", "cab", "cad"]));
console.log(find_order(["caa", "aaa", "aab"]));
