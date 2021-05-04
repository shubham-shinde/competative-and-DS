console.log("|".repeat(50));
let createReadStream = require("fs").createReadStream;

let chunkIndex = 0;
const readStream = createReadStream("./data.txt");

readStream.on("open", () => {
  console.log("Started Reading...");
});

readStream.on("end", () => {
  console.log("Completed Reading...");
});

readStream.on("data", (chunk) => {
  console.log("Chunk: " + ++chunkIndex);
  console.log("-".repeat(20));
  console.log(chunk);
  console.log("\n");
});
