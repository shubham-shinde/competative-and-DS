// https://www.geeksforgeeks.org/trapping-rain-water/
console.log("-".repeat(40));
//
function trapping_rain_water(arr) {
  let water = Array(arr.length).fill(0);
  max = arr[0];
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] > max) max = arr[i];
    water[i] = max - arr[i];
  }
  max = arr[arr.length - 1];
  for (let i = arr.length - 1; i >= 0; i--) {
    if (arr[i] > max) max = arr[i];
    if (max - arr[i] < water[i]) water[i] = max - arr[i];
  }
  return water.reduce((a, b) => a + b, 0);
}

console.log(trapping_rain_water([3, 0, 2, 0, 4]));
