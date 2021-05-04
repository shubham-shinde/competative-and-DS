console.log("-".repeat(40));

function heapify(arr, from) {
  let n = 0;
  let l = arr.length;
  let t;
  while (true) {
    let pos = n + from;
    let left = from + 2 * n + 1;
    let right = from + 2 * n + 2;
    if (left < l && right < l) {
      if (arr[left] >= arr[pos] && arr[right] >= arr[pos]) break;
      if (arr[left] < arr[right]) {
        t = arr[pos];
        arr[pos] = arr[left];
        arr[left] = t;
        n = left - from;
      } else {
        t = arr[pos];
        arr[pos] = arr[right];
        arr[right] = t;
        n = right - from;
      }
    } else if (left < l && arr[left] < arr[pos]) {
      t = arr[pos];
      arr[pos] = arr[left];
      arr[left] = t;
      n = left - from;
    } else if (right < l && arr[right] < arr[pos]) {
      t = arr[pos];
      arr[pos] = arr[right];
      arr[right] = t;
      n = right - from;
    } else break;
  }
}

function heapsort(arr) {
  for (i = arr.length - 1; i >= 0; i--) {
    heapify(arr, i);
  }
  let sorted = [];
  while (arr.length > 0) {
    let t = arr[0];
    arr[0] = arr[arr.length - 1];
    arr[arr.length - 1] = t;
    sorted.push(arr.pop());
    heapify(arr, 0);
  }
  return sorted;
}

console.log(heapsort([3, 4, 4, 2, 5, 4, 2, 8, 7]));
