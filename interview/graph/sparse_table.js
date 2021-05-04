console.log("max in the range | will not work for cumulative query");

let sparse_table = {};

function build_sparse_table(arr) {
  let i = 0;
  for (i = 1; i < arr.length - 1; i = i * 2) {
    for (j = 0; j < arr.length; j++) {
      if (i === 1) {
        sparse_table[j] = [];
        sparse_table[j].push(arr[j]);
      } else {
        if (j + i / 2 < arr.length) {
          sparse_table[j].push(
            Math.max(
              sparse_table[j][sparse_table[j].length - 1],
              sparse_table[j + i / 2][sparse_table[j].length - 1]
            )
          );
        }
      }
    }
  }
}

function find_max(from, to) {
  let len = to - from + 1;
  let iz = 1 << Math.floor(Math.log2(len));
  let len_pos = Math.log2(iz);
  return Math.max(sparse_table[from][len_pos], sparse_table[to - iz][len_pos]);
}

build_sparse_table([3, 4, 2, 3, 5, 74, 4, 22, 5, 45, 3, 42, 4, 3]);
console.log(find_max(10, 12));
