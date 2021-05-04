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
function topological(graph) {
  map = new Map();
  let visited = {};
  vertices = Object.keys(graph).map((a) => Number(a));
  for (let i in vertices) {
    visited[Number(i)] = false;
    map.set(Number(i), graph[i]);
  }

  let stack = [];

  for (let i in vertices) {
    top(map, Number(i), visited, stack);
  }
  console.log(stack.reverse());
}

let graph = {
  4: [0, 1],
  5: [2, 0],
  2: [3],
  0: [],
  1: [],
  3: [1],
};

topological(graph);
