const { Worker, parentPort, isMainThread } = require("worker_threads");

if (isMainThread) {
  const worker = new Worker(__filename);
  worker.on("message", (message) => console.log(message));
  worker.postMessage("ping");
} else {
  parentPort.once("message", (message) =>
    parentPort.postMessage({ pong: message })
  );
}
