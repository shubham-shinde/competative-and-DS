console.log("-".repeat(50));

function find_min_in_snake_and_ladder(matrix) {
  let h = matrix.length;
  let w = matrix[0].length;
  matrix = matrix.reverse();
  let list = [];
  for (i = 0; i < h; i++) {
    if (i % 2 === 0)
      for (j = 0; j < w; j++)
        list.push(matrix[i][j] === -1 ? matrix[i][j] : matrix[i][j] - 1);
    else
      for (j = w - 1; j >= 0; j--)
        list.push(matrix[i][j] === -1 ? matrix[i][j] : matrix[i][j] - 1);
  }
  let visited = new Array(list.length).fill(false);
  let queue = [[0, 0]];
  let d = 0;
  while (queue.length > d) {
    let [pos, dis] = queue[d];
    if (pos === h * w - 1) return dis;
    for (i = pos + 1; i <= pos + 6; i++)
      if (i < h * w && !visited[i]) {
        visited[i] = true;
        queue.push([list[i] === -1 ? i : list[i], dis + 1]);
      }
    d++;
  }
}

let matrix = [
  [-1, -1, -1, -1, -1, -1],
  [-1, -1, -1, -1, -1, -1],
  [-1, -1, -1, -1, -1, -1],
  [-1, 35, -1, -1, 13, -1],
  [-1, -1, -1, -1, -1, -1],
  [-1, 15, -1, -1, -1, -1],
];
console.log(find_min_in_snake_and_ladder(matrix));
