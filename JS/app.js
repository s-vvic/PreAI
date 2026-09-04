const express = require("express");

var app = express();
var port = 8080;

app.listen(port, function () {
  console.log("server on 8080 port!");
});

app.get("/", (req, res) => {
  res.send("<h1>express server on port 8080</h1>");
});
