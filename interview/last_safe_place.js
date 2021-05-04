console.log("-".repeat(40));

function safe_place(n, k) {
  if (n === 1) return 1;
  return ((safe_place(n - 1, k) + (k - 1)) % n) + 1;
}

console.log(safe_place(5, 3));
