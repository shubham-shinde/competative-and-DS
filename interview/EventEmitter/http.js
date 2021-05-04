console.log("-".repeat(40));
let http = require("http");
http
  .createServer((req, res) => {
    console.log(req.constructor.name);
    res.end("2");
  })
  .listen(8080);
